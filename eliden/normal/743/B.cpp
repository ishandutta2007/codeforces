#include<stdio.h>
int n, c;
long long k, x;
int main()
{
    scanf("%i%lli",&n,&k);
    x = k&(-k);
    c = 0;
    while(x>0)
    {
	x/=2;
	c++;
    }
    printf("%i\n",c);
}