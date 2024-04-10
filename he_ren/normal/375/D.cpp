#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot;
}

struct Data
{
	map<int,int> cnt;
	vector<int> freq;
	inline void add(int clr,int k)
	{
		int aft = (cnt[clr] += k), bef = aft - k;
		if((int)freq.size() < aft+1) freq.resize(aft+1);
		for(int i=bef+1; i<=aft; ++i) ++freq[i];
	}
	inline void merge(Data &oth)
	{
		for(map<int,int>::iterator it = oth.cnt.begin(); it != oth.cnt.end(); ++it)
			add(it -> first, it -> second);
	}
	inline int query(const int x) const { return x < (int)freq.size()? freq[x]: 0;}
};

int siz[MAXN], son[MAXN];
void dfs_son(int u,int fa)
{
	siz[u] = 1;
	son[u] = -1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs_son(v,u);
		siz[u] += siz[v];
		if(son[u] == -1 || siz[v] > siz[son[u]]) son[u] = v;
	}
}

int clr[MAXN];
vector<pii> qrys[MAXN];
int ans[MAXM];

Data *f[MAXN];
void dfs_f(int u,int fa)
{
	if(son[u] == -1) f[u] = new Data;
	else dfs_f(son[u],u), f[u] = f[son[u]];
	
	f[u] -> add(clr[u], 1);
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa || v == son[u]) continue;
		dfs_f(v,u);
		f[u] -> merge(*f[v]);
		delete f[v];
	}
	
	vector<pii> &qry = qrys[u];
	for(int i=0; i<(int)qry.size(); ++i)
		ans[qry[i].second] = f[u] -> query(qry[i].first);
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&clr[i]);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	for(int i=1; i<=m; ++i)
	{
		int u,k;
		scanf("%d%d",&u,&k);
		qrys[u].push_back(make_pair(k,i));
	}
	
	dfs_son(1,0);
	dfs_f(1,0);
	
	for(int i=1; i<=m; ++i)
		printf("%d\n",ans[i]);
	return 0;
}