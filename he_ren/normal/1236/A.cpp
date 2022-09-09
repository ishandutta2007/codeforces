#include<cstdio>

inline void chk_max(int &a,int b){ if(a<b) a=b;}

void solve(void)
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int ans=0;
	for(int i=0; i*2<=b && i<=a; ++i)
	{
		for(int j=0; i*2+j<=b && j*2<=c; ++j)
			chk_max(ans, (i+j)*3);
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}