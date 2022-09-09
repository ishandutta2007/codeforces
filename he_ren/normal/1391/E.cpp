#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;
const int MAXM = 1e6 + 5;

struct Edge
{
	int next,to;
}e[MAXM<<1];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot;
}

int dep[MAXN], pre[MAXN];
vector<int> dep_node[MAXN];
void dfs_dep(int u)
{
	dep_node[dep[u]].push_back(u);
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(dep[v] != -1) continue;
		pre[v] = u;
		dep[v] = dep[u] + 1;
		dfs_dep(v);
	}
}

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) head[i] = 0;
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	for(int i=1; i<=n; ++i) dep_node[i].clear();
	for(int i=1; i<=n; ++i) dep[i] = -1;
	
	dep[1] = 1; pre[1] = 0;
	dfs_dep(1);
	
	int mxdepi = 1;
	for(int i=1; i<=n; ++i)
		if(dep[i] > dep[mxdepi])
			mxdepi = i;
	if(dep[mxdepi] >= (n+1)/2)
	{
		printf("PATH\n");
		printf("%d\n",dep[mxdepi]);
		int u = mxdepi;
		while(u) printf("%d ",u), u = pre[u];
		putchar('\n');
		return;
	}
	
	vector<pii> ans;
	for(int i=1; i<=n; ++i)
	{
		vector<int> &vec = dep_node[i];
		for(int j=0; j+1<(int)vec.size(); j+=2)
			ans.push_back(make_pair(vec[j], vec[j+1]));
	}
	
	printf("PAIRING\n");
	printf("%d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i)
		printf("%d %d\n",ans[i].first,ans[i].second);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}