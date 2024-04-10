#include<stdio.h>
long long int n;
int main(){
	scanf("%I64d",&n);
	while(n%3==0)n/=3;
	printf("%I64d",n/3+1);
}