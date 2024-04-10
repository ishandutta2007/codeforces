#include<cstdio>

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	int now=0;
	for(int i=1; i<=n; ++i)
	{
		int a;
		scanf("%d",&a);
		now+=a;
		printf("%d ",now/m);
		now%=m;
	}
	return 0;
}