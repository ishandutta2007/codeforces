#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
int a,b,k1,k2;
LL ans;
LL inf=100000000000000000LL;
LL f(int a,int n)
{
	if (n<0) return -inf;
	if (a>0&&n==0) return -inf;
	if (a>0&&n>a) return -inf;
	if (a==0&&n>0) return -inf;
	if (a==0&&n==0) return 0;
	return 1LL*(a-n+1)*(a-n+1)+n-1;
}
LL g(int a,int n) 
{
	if (n<0) return inf;
	if (a>0&&n==0) return inf;
	if (a>0&&n>a) return inf;
	if (a==0&&n>0) return inf;
	if (a==0&&n==0) return 0;
	int c=a/n;
	return 1LL*c*c*n+1LL*(2*c+1)*(a%n);
}
int main()
{
	scanf("%d%d",&a,&b);
	LL ans=-inf;
	for (int i=0;i<=a;i++)
	{
		if (ans<f(a,i)-g(b,i-1)) ans=f(a,i)-g(b,i-1),k1=i,k2=i-1;
		if (ans<f(a,i)-g(b,i)) ans=f(a,i)-g(b,i),k1=i,k2=i;
		if (ans<f(a,i)-g(b,i+1)) ans=f(a,i)-g(b,i+1),k1=i,k2=i+1;
	}
	printf("%lld\n",ans);
	while (k1>0||k2>0)
	{
		if (k1>=k2)
		{
			if (k1>1) 
			{
				printf("o");
				a--;
			} else 
			{
				for (int i=1;i<=a;i++) printf("o");
				a=0;
			}
			k1--;
		}
		else
		{
			for (int i=1;i<=b/k2;i++) printf("x");
			b-=b/k2;k2--;
		}
	}
	return 0;
}