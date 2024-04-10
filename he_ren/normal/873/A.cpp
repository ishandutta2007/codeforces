#include<cstdio>

int main(void)
{
	int n,k,x;
	scanf("%d%d%d",&n,&k,&x);
	int ans=k*x;
	for(int i=1; i<=n-k; ++i)
	{
		int a;
		scanf("%d",&a);
		ans+=a;
	}
	printf("%d",ans);
	return 0;
}