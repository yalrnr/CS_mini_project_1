/*  
    Mini-Project 1
    CS 201, Data Structures
    Department of Computer Science and Engineering, 
    National Institute of Technology Silchar
    Anuj Yadav_2012024
    Time complexity is O(n), with large constant coefficient of size 'length'.
*/
#include <stdio.h>
#define length 4185
// No of digits in 20,000 fibonacci number is 4180. 
//The formula is fib(n) = (pow(Φ,n) - pow(Ψ,-n)) / √5, Φ = (1 + √5) / 2, Ψ = (1 - √5) / 2 
char fib1[length];
char fib2[length];
char answer[length];
void SumOfPrecedingTwoNumbers(char num1[], char num2[], char answer[]){
  int i,sum,carry=0;
  for(i=length-1;i>=0;--i){
    sum=(num1[i]-48)+(num2[i]-48)+carry;
    answer[i]=(sum%10)+48;
    carry=sum/10;
  }
}
int main(){
  int n,i;
  scanf("%d", &n);
  for(i=0;i<length;++i){
    fib1[i]=fib2[i]=answer[i]=48;// Zero (ASCII Value - 48) assigned to all
  }
  fib2[length-1]=49;//ASCII Code of 1 is 49
  if(n<=1){
    printf("%d",n);
    return 0;
  }
  else{
    for(i=2;i<=n;++i){
      SumOfPrecedingTwoNumbers(fib1,fib2,answer);
        //Assigning the last number and the sum to preceding numbers subsequently
      for(int i=length-1;i>=0;--i)
        fib1[i]=fib2[i];
      for(int i=length-1;i>=0;--i)
        fib2[i]=answer[i];
        }
    int found=0;
    for(int i=0;i<length;++i){
        //All the leading zeroes are ignored
      if(found==0&&answer[i]==48)
        continue;
      if(found==0&&answer[i]!=48)
        found=1;
      printf("%c",answer[i]);
      }
  }
  return 0;
}
