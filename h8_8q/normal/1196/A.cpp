#include<cstdio>

long long a,b,c;
int n,i;

int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		printf("%lld\n",(a+b+c)/2);
	}
	return 0;
}