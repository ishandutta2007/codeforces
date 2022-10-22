#include<cstdio>
using namespace std;
long long n,sum,maxn,minn,a[200005],s;
int main()
{
	scanf("%I64d",&n);
	if(n%2==0)
	{
		printf("NO\n");
		return 0;
	}
	else printf("YES\n");
	maxn=2*n,minn=1;
	sum=(n*(2*n+1))/2;
	for(int i=1;i<=n-1;i++)
	{
		if(i%2==0) a[i]=minn,minn+=2;
		else a[i]=maxn,maxn-=2;
		s+=a[i];
	}
	for(int i=n;i<=2*n;i++)
	{
		if(i%2==1) sum++;
		else sum--;
		a[i]=sum-s;
		s+=a[i];
		s-=a[i-n+1];
	}
	for(int i=1;i<=2*n;i++)
	{
		printf("%I64d ",a[i]);
	}
	return 0;
}