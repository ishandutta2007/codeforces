#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

struct Segment_Tree
{
	ll mx[MAXN<<2], tag[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	Segment_Tree(void)
	{
		memset(mx, 0xc0, sizeof(mx));
	}
	inline void push_up(int u)
	{
		mx[u] = max(mx[ls(u)], mx[rs(u)]);
	}
	inline void upd(int u,ll k)
	{
		mx[u] += k; tag[u] += k;
	}
	inline void push_down(int u)
	{
		if(tag[u])
		{
			upd(ls(u), tag[u]); upd(rs(u), tag[u]);
			tag[u] = 0;
		}
	}
	inline void chk_max(int u,int l,int r,int q,ll k)
	{
		if(l == r){ mx[u] = max(mx[u], k); return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(q<=mid) chk_max(lson(u),q,k);
		else chk_max(rson(u),q,k);
		push_up(u);
	}
	inline void add(int u,int l,int r,int ql,int qr,ll k)
	{
		if(ql<=l && r<=qr){ upd(u, k); return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) add(lson(u),ql,qr,k);
		if(mid<qr) add(rson(u),ql,qr,k);
		push_up(u);
	}
	inline ll query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return mx[u];
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid && mid<qr)
			return max(query(lson(u),ql,qr), query(rson(u),ql,qr));
		else
			return ql<=mid? query(lson(u),ql,qr): query(rson(u),ql,qr);
	}
}f, g;

ll s[5][MAXN], a[MAXN], b[MAXN];
vector<pii> qs[MAXN];

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=3; ++i)
		for(int j=1; j<=n; ++j) scanf("%lld",&s[i][j]);
	for(int i=1; i<=Q; ++i)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		qs[r].emplace_back(l, k);
	}
	
	for(int i=1; i<=3; ++i)
		for(int j=1; j<=n; ++j)
			s[i][j] += s[i][j-1];
	
	for(int i=1; i<=n; ++i)
	{
		a[i] = s[1][i] - s[2][i-1];
		b[i] = s[3][n] - s[3][i-1] + s[2][i];
	}
	
	ll ans = -linf;
	stack<int> sta;
	for(int i=1; i<=n; ++i)
	{
		while(sta.size() && b[sta.top()] <= b[i])
		{
			int j = sta.top(); sta.pop();
			int k = sta.size()? sta.top()+1: 1;
			g.add(1,1,n, k, j, -b[j]);
		}
		
		ll curf = -linf;
		f.chk_max(1,1,n, i, a[i]);
		g.chk_max(1,1,n, i, a[i]);
		for(pii t: qs[i])
		{
			int l = t.first, k = t.second;
			curf = max(curf, f.query(1,1,n, l, i) - k);
		}
		if(i+1 <= n && curf > -linf)
		{
			f.chk_max(1,1,n, i+1, curf);
			g.chk_max(1,1,n, i+1, curf);
		}
		
		g.add(1,1,n, sta.size()? sta.top()+1: 1, i, b[i]);
		sta.push(i);
		
		for(pii t: qs[i])
		{
			int l = t.first, k = t.second;
			ans = max(ans, a[i] + b[i] - k);
			ans = max(ans, g.query(1,1,n, l, i) - k);
		}
	}
	
	printf("%lld",ans);
	return 0;
}