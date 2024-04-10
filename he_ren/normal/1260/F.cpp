#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXH = 1e5 + 5;
const int mod = 1e9 + 7;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

inline ll pw(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod; b>>=1;
	}
	return res;
}

struct Segment_Tree
{
	int sum[MAXN<<2], tag[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u){ sum[u] = sum[ls(u)] + sum[rs(u)]; if(sum[u] >= mod) sum[u] -= mod;}
	inline void push_down(int u,int l,int r)
	{
		if(tag[u])
		{
			int mid = (l+r)>>1;
			add_mod(tag[ls(u)], tag[u]); sum[ls(u)] = (sum[ls(u)] + (ll)tag[u] * (mid-l+1)) %mod;
			add_mod(tag[rs(u)], tag[u]); sum[rs(u)] = (sum[rs(u)] + (ll)tag[u] * (r-mid)) %mod;
			tag[u] = 0;
		}
	}
	void update(int u,int l,int r,int ql,int qr,int k)
	{
		if(ql<=l && r<=qr){ add_mod(tag[u], k); sum[u] = (sum[u] + (ll)k * (r-l+1)) %mod; return;}
		push_down(u,l,r);
		int mid = (l+r)>>1;
		if(ql<=mid) update(lson(u),ql,qr,k);
		if(mid<qr) update(rson(u),ql,qr,k);
		push_up(u);
	}
	int query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return sum[u];
		push_down(u,l,r);
		int mid = (l+r)>>1, res = 0;
		if(ql<=mid) add_mod(res, query(lson(u),ql,qr));
		if(mid<qr) add_mod(res, query(rson(u),ql,qr));
		return res;
	}
}tree;

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

int pre[MAXN], dep[MAXN], siz[MAXN], son[MAXN];
void dfs_siz(int u,int fa)
{
	son[u] = -1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		pre[v] = u;
		dep[v] = dep[u] + 1;
		dfs_siz(v,u);
		siz[u] += siz[v];
		if(son[u] == -1 || siz[son[u]] < siz[v]) son[u] = v;
	}
}

int top[MAXN], dfn[MAXN], seq[MAXN], cur_dfn = 0;
void dfs_dfn(int u,int fa,int tp)
{
	dfn[u] = ++cur_dfn; seq[cur_dfn] = u;
	top[u] = tp;
	if(son[u] == -1) return;
	dfs_dfn(son[u], u, tp);
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa || v == son[u]) continue;
		dfs_dfn(v,u, v);
	}
}

int n;

inline void update(int u,int k)
{
	while(u)
		tree.update(1,1,n, dfn[top[u]], dfn[u], k),
		u = pre[top[u]];
}
inline int query(int u)
{
	int res = 0;
	while(u)
		add_mod(res, tree.query(1,1,n, dfn[top[u]], dfn[u])),
		u = pre[top[u]];
	return res;
}

int lh[MAXN], rh[MAXN], inv_len[MAXN];

int sum_inv = 0, sump = 0, cur_ans = 0;
inline int get_res(int u)
{
	return ((ll)dep[u] * sum_inv + sump + 2 * (-query(u) + mod)) %mod * inv_len[u] %mod;
}

int main(void)
{
	scanf("%d",&n);
	int mxh = 0;
	for(int i=1; i<=n; ++i)
		scanf("%d%d",&lh[i], &rh[i]), mxh = max(mxh, rh[i]);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	dep[1] = 1;
	dfs_siz(1,0);
	dfs_dfn(1,0, 1);
	
	for(int i=1; i<=n; ++i) inv_len[i] = pw(rh[i] - lh[i] + 1, mod-2);
	
	static vector<pii> eves[MAXH];
	for(int i=1; i<=n; ++i)
		eves[lh[i]].push_back(make_pair(i, 1)),
		eves[rh[i]+1].push_back(make_pair(i, mod-1));
	
	int ans = 0;
	for(int k=1; k<=mxh; ++k)
	{
		vector<pii> &eve = eves[k];
		for(int i=0; i<(int)eve.size(); ++i)
		{
			int u = eve[i].first, type = eve[i].second;
			
			sump = (sump + (ll)type * dep[u] %mod * inv_len[u]) %mod;
			sum_inv = (sum_inv + (ll)type * inv_len[u]) %mod;
			update(u, (ll)type * inv_len[u] %mod);
			
			cur_ans = (cur_ans + (ll)type * get_res(u)) %mod;
		}
		
		int tmp = cur_ans;
		for(int i=1; i<=n; ++i)
			tmp = (ll)tmp * (rh[i] - lh[i] + 1) %mod;
		
		add_mod(ans, cur_ans);
	}
	
	for(int i=1; i<=n; ++i)
		ans = (ll)ans * (rh[i] - lh[i] + 1) %mod;
	
	printf("%d",ans);
	return 0;
}