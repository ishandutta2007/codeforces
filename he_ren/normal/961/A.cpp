#include<cstdio>
const int MAXN = 1e3 + 5;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

int t[MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int c;
		scanf("%d",&c);
		++t[c];
	}
	
	int ans=m;
	for(int i=1; i<=n; ++i) chk_min(ans,t[i]);
	printf("%d",ans);
	return 0;
}