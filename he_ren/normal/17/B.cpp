#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 1e3 + 5;
const int MAXM = 1e4 + 5;
const int inf = 0x3f3f3f3f;

inline void error(void){ printf("-1"); exit(0);}
inline void chk_min(int &a,int b){ if(a>b) a=b;}

vector<int> g[MAXN];
int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	int m;
	scanf("%d",&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[v].push_back(w);
	}
	
	bool flag=0;
	for(int i=1; i<=n; ++i)
		if(!g[i].size())
		{
			if(flag) error();
			flag=1;
		}
	
	int ans=0;
	for(int i=1; i<=n; ++i)
	{
		int mn = inf;
		for(unsigned int j=0; j<g[i].size(); ++j)
			chk_min(mn, g[i][j]);
		if(mn!=inf) ans+=mn;
	}
	printf("%d",ans);
	return 0;
}