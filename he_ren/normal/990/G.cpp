#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXA = 2e5 + 5;

int gcd(int a,int b){ return b? gcd(b,a%b): a;}

struct Edge_uvw
{
	int u,v,w;
}e[MAXN];

int a[MAXN];

ll res = 0;

int fa[MAXN], size[MAXN];
inline void init(int n){ for(int i=1; i<=n; ++i) fa[i]=i, size[i]=1;}
int find(int u){ return fa[u] == u? fa[u]: fa[u] = find(fa[u]);}
void connect(int u,int v)
{
	int fu = find(u), fv = find(v);
	if(fu == fv) return;
	res += (ll)size[fu] * size[fv];
	size[fv] += size[fu];
	fa[fu] = fv;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[i] = (Edge_uvw){ u,v,gcd(a[u],a[v])};
	}
	
	int maxa = 0;
	for(int i=1; i<=n; ++i)
		maxa = max(maxa, a[i]);
	
	static vector<Edge_uvw> g[MAXA];
	for(int i=1; i<n; ++i)
		g[e[i].w].push_back(e[i]);
	
	init(n);
	
	static ll f[MAXA];
	for(int i=2; i<=maxa; ++i)
	{
		res = 0;
		for(int j=i; j<=maxa; j+=i)
		{
			vector<Edge_uvw> &vec = g[j];
			for(int k=0; k<(int)vec.size(); ++k)
				connect(vec[k].u, vec[k].v);
		}
		f[i] = res;
		
		for(int j=i; j<=maxa; j+=i)
		{
			vector<Edge_uvw> &vec = g[j];
			for(int k=0; k<(int)vec.size(); ++k)
			{
				fa[vec[k].u] = vec[k].u; size[vec[k].u] = 1;
				fa[vec[k].v] = vec[k].v; size[vec[k].v] = 1;
			}
		}
	}
	
	f[1] = (ll)n * (n-1) / 2;
	for(int i=maxa; i>=1; --i)
	{
		for(int j=i*2; j<=maxa; j+=i)
			f[i] -= f[j];
	}
	
	for(int i=1; i<=n; ++i)
		++f[a[i]];
	
	for(int i=1; i<=maxa; ++i)
		if(f[i]) printf("%d %lld\n",i,f[i]);
	return 0;
}