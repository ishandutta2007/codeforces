#include<cstdio>

inline int min(int a,int b){ return a<b? a: b;}
inline void chk_max(int &a,int b){ if(a<b) a=b;}

inline void solve(void)
{
	int b,p,f,h,c;
	scanf("%d%d%d%d%d",&b,&p,&f,&h,&c);
	int ans=0;
	for(int i=0; i<=p; ++i)
	{
		if(i*2>b) break;
		chk_max(ans, h*i + c*min((b-i*2)/2,f));
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