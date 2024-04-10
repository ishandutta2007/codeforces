#include<cstdio>

inline void chk_min(int &a,int b){ if(a>b) a=b;}

int main(void)
{
	int n,k;
	scanf("%d%d",&n,&k);
	int ans=k;
	for(int i=1; i<=n; ++i)
	{
		int a;
		scanf("%d",&a);
		if(k%a==0) chk_min(ans,k/a);
	}
	printf("%d",ans);
	return 0;
}