#include<cstdio>
const int MAXN = 7 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int g[MAXN][MAXN];
int d[MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(n<7)
	{
		printf("%d",m);
		return 0;
	}
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u][v]=g[v][u]=1;
		++d[u]; ++d[v];
	}
	
	int ans=0;
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j) if(i!=j)
		{
			int res=m-d[i];
			for(int k=1; k<=n; ++k)
			{
				if(g[i][k] && !g[j][k]) ++res;
			}
			chk_max(ans,res);
		}
	}
	
	printf("%d",ans);
	return 0;
}