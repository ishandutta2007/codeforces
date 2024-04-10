#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int lvl[MAXN];

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

bool del[MAXN<<1];
inline int anoth(int id){ return id&1? id+1: id-1;}
inline void chg_del(int id){ del[id] = del[anoth(id)] ^= 1;}

int siz[MAXN], mxson[MAXN];
void dfs_siz(int u,int fa)
{
	siz[u] = 1; mxson[u] = 0;
	for(int i=head[u]; i; i=e[i].next) if(!del[i])
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs_siz(v,u);
		siz[u] += siz[v];
		mxson[u] = max(mxson[u], siz[v]);
	}
}
int root, tot_siz;
void dfs_root(int u,int fa)
{
	mxson[u] = max(mxson[u], tot_siz - siz[u]);
	if(mxson[u] < mxson[root]) root = u;
	for(int i=head[u]; i; i=e[i].next) if(!del[i])
		if(e[i].to != fa)
			dfs_root(e[i].to, u);
}

vector<int> vec;
int anc[MAXN];
void dfs_vec(int u,int fa,int need)
{
	siz[u] = 1;
	for(int i=head[u]; i; i=e[i].next) if(!del[i])
	{
		int v = e[i].to;
		if(v == fa) continue;
		anc[v] = i;
		dfs_vec(v,u, need);
		siz[u] += siz[v];
	}
	if(lvl[siz[u]] == need) vec.push_back(u);
}

bool divid(int u)
{
	dfs_siz(u,0);
	tot_siz = siz[root = u];
	if(tot_siz <= 3) return 1;
	dfs_root(u,0);
	u = root;
	
	vec.clear();
	dfs_vec(u, 0, lvl[tot_siz] - 2);
	if(!vec.size()) return 0;
	
	if(vec.size() == 1)
	{
		int v = vec[0];
		chg_del(anc[v]);
		return divid(v) && divid(u);
	}
	
	int v1 = vec[0], v2 = vec[1];
	chg_del(anc[v1]); chg_del(anc[v2]);
	
	return divid(u) && divid(v1) && divid(v2);
}

int main(void)
{
	for(int x = 1, y = 1, t = 1; y < MAXN; ++t, swap(x += y, y))
		lvl[y] = t;
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	if(!lvl[n]) return printf("NO"), 0;
	
	if(divid(1)) printf("YES");
	else printf("NO");
	return 0;
}