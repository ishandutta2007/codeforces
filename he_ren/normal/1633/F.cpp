#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

struct Segment_Tree
{
	ll sum[MAXN<<2][2];
	int cnt[MAXN<<2][2], tag[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u)
	{
		for(int k=0; k<=1; ++k)
			sum[u][k] = sum[ls(u)][k] + sum[rs(u)][k],
			cnt[u][k] = cnt[ls(u)][k] + cnt[rs(u)][k];
	}
	inline void upd(int u)
	{
		swap(sum[u][0], sum[u][1]);
		swap(cnt[u][0], cnt[u][1]);
		tag[u] ^= 1;
	}
	inline void push_down(int u)
	{
		if(tag[u])
		{
			upd(ls(u)); upd(rs(u));
			tag[u] = 0;
		}
	}
	void insert(int u,int l,int r,int q,int k)
	{
		if(l == r){ cnt[u][0] = 1; sum[u][0] = k; return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(q<=mid) insert(lson(u),q,k);
		else insert(rson(u),q,k);
		push_up(u);
	}
	void update(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr){ upd(u); return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) update(lson(u),ql,qr);
		if(mid<qr) update(rson(u),ql,qr);
		push_up(u);
	}
}tree;

vector<pii> g[MAXN];
int anc[MAXN], ancw[MAXN], siz[MAXN], son[MAXN];
void dfs_tree(int u,int fa)
{
	siz[u] = 1; son[u] = -1;
	for(pii it: g[u]) if(it.first != fa)
	{
		int v = it.first;
		anc[v] = u; ancw[v] = it.second;
		dfs_tree(v,u);
		siz[u] += siz[v];
		if(son[u] == -1 || siz[v] > siz[son[u]]) son[u] = v;
	}
}

int dfn[MAXN], seq[MAXN], top[MAXN], curdfn = 0;
void dfs_dfn(int u,int fa,int tp)
{
	top[u] = tp;
	dfn[u] = ++curdfn; seq[curdfn] = u;
	if(son[u] != -1) dfs_dfn(son[u], u, tp);
	for(pii it: g[u]) if(it.first != fa && it.first != son[u])
		dfs_dfn(it.first, u, it.first);
}

void update_path(int u)
{
	while(u)
	{
		tree.update(1,1,curdfn, dfn[top[u]], dfn[u]);
		u = anc[top[u]];
	}
}

bool active[MAXN];
vector<int> edges;
bool dfs_edges(int u,int fa)
{
	if(!active[u]) return 0;
	bool res = 1;
	for(pii it: g[u]) if(it.first != fa)
	{
		int v = it.first;
		bool t = dfs_edges(v,u);
		if(t) edges.push_back(it.second);
		res ^= t;
	}
	return res;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].emplace_back(v, i);
		g[v].emplace_back(u, i);
	}
	
	dfs_tree(1,0); dfs_dfn(1,0,1);
	
	auto make_active = [&] (int u)
	{
		active[u] = 1;
		tree.insert(1,1,n, dfn[u], ancw[u]);
		update_path(u);
	};
	make_active(1);
	
	ll lstans = 0;
	while(1)
	{
		int type;
		scanf("%d",&type);
		if(type == 3) break;
		if(type == 1)
		{
			int u;
			scanf("%d",&u);
			make_active(u);
			if(tree.cnt[1][0] == tree.cnt[1][1])
				lstans = tree.sum[1][1];
			else
				lstans = 0;
			printf("%lld\n",lstans);
		}
		else
		{
			if(lstans == 0) printf("0\n");
			else
			{
				edges.clear();
				dfs_edges(1,0);
				sort(edges.begin(), edges.end());
				printf("%d ",(int)edges.size());
				for(int x: edges) printf("%d ",x);
				printf("\n");
			}
		}
		fflush(stdout);
	}
	return 0;
}