#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int inf = 0x3f3f3f3f;

const int SZ = 3e3;
struct Set_2D
{
	vector<pii> a,b;
	vector< vector<int> > tree;
	int cnt;
	Set_2D(void): cnt(0) {}
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	#define allt(u) tree[u].begin(), tree[u].end()
	inline int size(void) const { return (int)a.size() + (int)b.size();}
	inline pii operator [] (int x) const { return x < (int)a.size()? a[x]: b[x - (int)a.size()];}
	void build(int u,int l,int r)
	{
		if(l == r){ tree[u].resize(1); tree[u][0] = a[l].second; return;}
		int mid = (l+r)>>1;
		build(lson(u)); build(rson(u));
		tree[u].resize(tree[ls(u)].size() + tree[rs(u)].size());
		merge(allt(ls(u)), allt(rs(u)), tree[u].begin());
	}
	int query(int u,int l,int r,int ql,int qr,int k)
	{
		if(ql <= l && r <= qr) return upper_bound(allt(u),k) - tree[u].begin();
		int mid = (l+r)>>1, res = 0;
		if(ql<=mid) res += query(lson(u),ql,qr,k);
		if(mid<qr) res += query(rson(u),ql,qr,k);
		return res;
	}
	void build(void)
	{
		cnt = 0;
		sort(b.begin(), b.end());
		vector<pii> tmp(a.size() + b.size());
		merge(a.begin(), a.end(), b.begin(), b.end(), tmp.begin());
		a = tmp; b.clear();
		
		tree.resize(((int)a.size() << 2) + 5);
		build(1,0,(int)a.size()-1);
	}
	inline void insert(int x,int y)
	{
		b.push_back(make_pair(x,y));
		if(++cnt > SZ) build();
	}
	inline int query(int x,int y)
	{
		if(++cnt > SZ) build();
		int res = 0;
		for(int i=0; i<(int)b.size(); ++i)
			if(b[i].first <= x && b[i].second <= y) ++res;
		int pos = upper_bound(a.begin(),a.end(),make_pair(x,inf)) - a.begin() - 1;
		if(pos >= 0) res += query(1,0,(int)a.size()-1, 0, pos, y);
		return res;
	}
};

struct Edge
{
	int next,to,w;
}e[MAXN<<1];
int head[MAXN],etot=0;
inline void add(int u,int v,int w)
{
	e[++etot] = (Edge){ head[u],v,w};
	head[u] = etot;
}

struct State
{
	Set_2D s;
	int tagx, tagy;
	State(void): tagx(0), tagy(0) {};
	inline int size(void) const { return s.size();}
	inline pii operator [] (int x) const { pii res = s[x]; return make_pair(res.first + tagx, res.second + tagy);}
	
	inline void insert(int x,int y){ s.insert(x - tagx, y - tagy);}
	inline void insert(pii p){ insert(p.first, p.second);}
	
	inline int query(int x,int y){ return s.query(x - tagx, y - tagy);}
	inline int query(pii p){ return query(p.first, p.second);}
	
	inline void merge(State &oth)
	{
		for(int i=0; i<(int)oth.size(); ++i)
			insert(oth[i]);
	}
};

int limx, limy;

ll ans = 0;
State *s[MAXN];
void dfs(int u,int fa)
{
	s[u] = new State;
	s[u] -> insert(0,0);
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs(v,u);
		++s[v] -> tagx; s[v] -> tagy += e[i].w;
		
		if(s[v] -> size() > s[u] -> size()) swap(s[u], s[v]);
		State &t = *s[v];
		
		for(int i=0; i<(int)t.size(); ++i)
		{
			pii p = t[i];
			ans += s[u] -> query(limx - p.first, limy - p.second);
		}
		s[u] -> merge(t);
	}
}

int main(void)
{
	int n;
	scanf("%d%d%d",&n,&limx,&limy);
	for(int i=2; i<=n; ++i)
	{
		int pre,w;
		scanf("%d%d",&pre,&w);
		add(pre,i,w); add(i,pre,w);
	}
	
	dfs(1,0);
	
	printf("%lld",ans);
	return 0;
}