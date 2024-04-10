#include<stdio.h>
long long n, a, b, t;
int main()
{
    scanf("%lld",&n);
    int g = 1;
    a = 1;
    b = 2;
    while(a+b<=n)
    {
	t = a + b;
	a = b;
	b = t;
	g++;
    }
    printf("%i\n",g);
    
}