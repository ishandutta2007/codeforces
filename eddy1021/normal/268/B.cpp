#include <stdio.h>
long long n;
int main(){
	scanf("%I64d",&n);
	printf("%I64d\n",n*(n*n+5)/6);
}