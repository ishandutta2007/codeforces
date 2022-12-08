#include<stdio.h>
int n;
int main()
{
    scanf("%i",&n);
    if(n==1)
	printf("%i\n",-1);
    else
	printf("%i %i %i\n",n,n+1,n*(n+1));
}