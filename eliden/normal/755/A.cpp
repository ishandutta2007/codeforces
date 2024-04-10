#include<stdio.h>
int n, m;
bool isprime(long long x)
{
    for(int i=2;i*i<=x;i++)
	if(x%i==0)
	    return false;
    return true;
}
int main()
{
    scanf("%i",&n);
    m = 1;
    while(isprime(m*n+1))
	m++;
    printf("%i\n",m);
}