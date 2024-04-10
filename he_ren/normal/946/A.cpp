#include<cstdio>

int main(void)
{
	int n;
	scanf("%d",&n);
	int ans=0;
	for(int i=1; i<=n; ++i)
	{
		int a;
		scanf("%d",&a);
		if(a<0) ans-=a;
		else ans+=a;
	}
	printf("%d",ans);
	return 0;
}