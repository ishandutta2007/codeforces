#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
const int MAXP = MAXN * 2;
const int MAXL = MAXP * 2;
const int LB = 18 + 2;
const int inf = 0x3f3f3f3f;

inline int read(void)
{
	int res=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') res=res*10+c-'0', c=getchar();
	return res;
}

int lb[MAXL];

struct Solver
{
	int n,m;
	array<int,3> es[MAXM];
	
	vector<int> g[MAXP];
	int val[MAXP];
	int dfn[MAXP], seq[MAXL], len, mx[MAXL][LB];
	void dfs_tree(int u)
	{
		seq[++len] = u;
		dfn[u] = len;
		for(int v: g[u])
		{
			dfs_tree(v);
			seq[++len] = u;
		}
	}
	
	int fa[MAXP];
	inline int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}
	
	void add_edge(array<int,3> k)
	{
		es[++m] = k;
	}
	void build(void)
	{
		static int eid[MAXM];
		iota(eid+1, eid+m+1, 1);
		sort(eid+1, eid+m+1, [&] (int i,int j){
			return es[i][2] < es[j][2];
		});
		
		for(int i=1; i<=2*n; ++i)
		{
			val[i] = 0;
			g[i].clear();
			fa[i] = i;
		}
		int pcnt = n;
		for(int k=1; k<=m; ++k)
		{
			int i = eid[k], u = es[i][0], v = es[i][1], w = es[i][2];
			if(find(u) == find(v)) continue;
			++pcnt;
			val[pcnt] = w;
			int uu = find(u), vv = find(v);
			g[pcnt] = {uu, vv};
			fa[uu] = fa[vv] = pcnt;
		}
		
		len = 0;
		dfs_tree(pcnt);
		
		for(int i=len; i>=1; --i)
		{
			mx[i][0] = val[seq[i]];
			for(int j=1; i+(1<<j)-1<=len; ++j)
				mx[i][j] = max(mx[i][j-1], mx[i+(1<<(j-1))][j-1]);
		}
	}
	
	inline int getmx(int u,int v)
	{
		int l = dfn[u], r = dfn[v];
		if(l > r) swap(l, r);
		int k = lb[r-l+1];
		return max(mx[l][k], mx[r-(1<<k)+1][k]);
	}
}s1, s2;

array<int,3> es[MAXM];
vector<int> g[MAXN];

int fa[MAXP];
inline int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}

void solve(void)
{
	int n = read(), m = read();
	s1.n = s2.n = n;
	s1.m = s2.m = 0;
	for(int i=1; i<=m; ++i)
		es[i][0] = read(), es[i][1] = read(), es[i][2] = read();
	
	fill(g+1, g+n+1, vector<int>());
	for(int i=1; i<=m; ++i)
	{
		int u = es[i][0], v = es[i][1];
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	for(int i=1; i<=m; ++i) s1.add_edge(es[i]);
	s1.build();
	
	static int ord[MAXN], rnk[MAXN];
	int currnk = 0;
	for(int i=1; i<=s1.len; ++i)
	{
		int u = s1.seq[i];
		if(u <= n && i == s1.dfn[u])
		{
			rnk[u] = ++currnk;
			ord[currnk] = u;
		}
	}
	
	iota(fa+1, fa+n+1, 1);
	int ccnt = n;
	while(ccnt > 1)
	{
		static int bak[MAXN], id[MAXN];
		memset(bak, 0, (n+1)<<2);
		for(int i=1; i<=n; ++i) ++bak[find(ord[i])];
		for(int i=1; i<=n; ++i) bak[i] += bak[i-1];
		for(int i=n; i>=1; --i) id[bak[find(ord[i])]--] = ord[i];
		
		vector< array<int,3> > cure;
		
		static int nxt[MAXN], pre[MAXN];
		for(int i=0; i<=n+1; ++i)
			pre[i] = i-1, nxt[i] = i+1;
		for(int l=1,r=1; l<=n; l=r)
		{
			while(r<=n && find(id[r]) == find(id[l])) ++r;
			for(int i=l; i<r; ++i)
			{
				int x = rnk[id[i]];
				pre[nxt[x]] = pre[x];
				nxt[pre[x]] = nxt[x];
			}
			
			int cu = -1, cv = -1, cw = inf;
			for(int i=l; i<r; ++i)
			{
				int u = id[i];
				static bool del[MAXN];
				for(int v: g[u])
					del[rnk[v]] = 1;
				
				auto chk = [&] (int x)
				{
					if(x < 1 || x > n) return;
					int v = ord[x], w = s1.getmx(u, v);
					if(w < cw) cu = u, cv = v, cw = w;
				};
				
				int x = pre[rnk[u]];
				while(x>=1 && del[x]) x = pre[x];
				chk(x);
				x = nxt[pre[rnk[u]]];
				while(x<=n && del[x]) x = nxt[x];
				chk(x);
				
				for(int v: g[u])
					del[rnk[v]] = 0;
			}
			for(int i=r-1; i>=l; --i)
			{
				int x = rnk[id[i]], y = pre[x];
				nxt[x] = nxt[y]; pre[nxt[y]] = x;
				pre[x] = y; nxt[y] = x;
			}
			
			if(cu != -1) cure.push_back({cu, cv, cw});
		}
		
		for(auto t: cure)
		{
			int u = t[0], v = t[1];
			if(find(u) == find(v)) continue;
			fa[find(u)] = find(v);
			--ccnt;
			s2.add_edge(t);
		}
	}
	s2.build();
	
	for(int i=1; i<=m; ++i)
		printf("%d ",s2.getmx(es[i][0], es[i][1]));
	printf("\n");
}

int main(void)
{
	lb[0] = -1;
	for(int i=1; i<MAXL; ++i) lb[i] = lb[i>>1] + 1;
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}