#include<cstdio>
#include<vector>
int a[2000005],pos;
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int cnt=__builtin_popcount(n);
	if(cnt>k||k>n)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(int i=0;i<=31;++i)
	{
		if(n&(1<<i))
		{
			a[++pos]=(1<<i);
		}
	}
	for(int i=1;i<=pos&&k>cnt;++i)
	{
		if(a[i]!=1)
		{
			--k;
			a[++pos]=(a[i]>>1);
			a[++pos]=(a[i]>>1);
			a[i]=0;
		}
	}
	for(int i=1;i<=pos;++i)
	{
		if(a[i])
		{
			printf("%d ",a[i]);
		}
	}
	printf("\n");
	return 0;
}