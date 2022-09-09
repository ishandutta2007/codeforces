#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXM = 1e5 + 5;
const int MAXN = 1e5 + 5;

int fa[MAXN+MAXM];
inline void init(int n){ for(int i=1; i<=n; ++i) fa[i] = i;}
int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}
inline void connect(int u,int v){ fa[find(u)] = find(v);}

struct Edge_uvw
{
	int u,v,w;
};
inline bool cmp(const Edge_uvw &p,const Edge_uvw &q){ return p.w > q.w;}

int a[MAXM], b[MAXN];
vector<Edge_uvw> ee;

int main(void)
{
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=1; i<=m; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	for(int i=1; i<=m; ++i)
	{
		int d;
		scanf("%d",&d);
		while(d--)
		{
			int v;
			scanf("%d",&v);
			ee.push_back((Edge_uvw){i,v+m, a[i]+b[v]});
		}
	}
	
	ll ans = 0;
	for(int i=0; i<(int)ee.size(); ++i)
		ans += ee[i].w;
	
	sort(ee.begin(), ee.end(), cmp);
	init(n+m);
	
	for(int i=0; i<(int)ee.size(); ++i)
	{
		int u = ee[i].u, v = ee[i].v, w = ee[i].w;
		if(find(u) == find(v)) continue;
		
		ans -= w;
		connect(u,v);
	}
	printf("%lld",ans);
	return 0;
}