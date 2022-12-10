#include<stdio.h>
int n, c[200], v[200];
int gcd(long long a, long long b)
{
    if(b==0)
	return a;
    return gcd(b,a%b);
}
int main()
{
    scanf("%i",&n);
    for(int i=0;i<n;i++)
    {
	scanf("%i",c+i);
	c[i]--;
    }
    long long l = 2;
    for(int i=0;i<n && l>0;i++)
    {
	int t = 0;
	for(int j=0;j<n;j++)
	    v[j]=0;
	int j = i;
	while(v[j]==0)
	{
	    v[j]++;
	    j = c[j];
	    t++;
	}
	if(i==j)
	    l = l*t/gcd(l,t);
	else
	    l = -2;
    }
    printf("%lli\n",l/2);
}