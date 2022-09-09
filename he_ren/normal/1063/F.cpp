#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;
const int LB = 18 + 2;
const int inf = 0x3f3f3f3f;

int lb[MAXN];

namespace SegT
{
	const int MAXP = MAXN * LB;
	int ls[MAXP], rs[MAXP], mx[MAXP], pcnt = 0;
	#define lson(u) ls[u],l,mid
	#define rson(u) rs[u],mid+1,r
	void update(int &u,int l,int r,int q,int k)
	{
		++pcnt; mx[pcnt] = mx[u]; ls[pcnt] = ls[u]; rs[pcnt] = rs[u]; u = pcnt;
		mx[u] = max(mx[u], k);
		if(l == r) return;
		int mid = (l+r)>>1;
		if(q<=mid) update(lson(u),q,k);
		else update(rson(u),q,k);
	}
	int query(int u,int l,int r,int ql,int qr)
	{
		if(!u) return 0;
		if(ql<=l && r<=qr) return mx[u];
		int mid = (l+r)>>1, res = 0;
		if(ql<=mid) res = max(res, query(lson(u),ql,qr));
		if(mid<qr) res = max(res, query(rson(u),ql,qr));
		return res;
	}
};

namespace SA
{
	int n;
	int _rnk1[MAXN], _rnk2[MAXN];
	int sa[MAXN], *rnk = _rnk1, *lst_rnk = _rnk2, sa_k;
	int lcp[MAXN], st[MAXN][LB];
	inline bool sa_same(int x,int y){ return lst_rnk[x] == lst_rnk[y] && lst_rnk[x + sa_k] == lst_rnk[y + sa_k];}
	inline void build(char s[],int _n)
	{
		n = _n;
		static int t[MAXN];
		int m = 300; rnk[0] = lst_rnk[0] = rnk[n+1] = lst_rnk[n+1] = 0;
		memset(t,0,(m+1)<<2);
		for(int i=1; i<=n; ++i) ++t[rnk[i] = s[i]];
		for(int i=1; i<=m; ++i) t[i] += t[i-1];
		for(int i=n; i>=1; --i) sa[t[rnk[i]]--] = i;
		if(m == n) ++m;
		if(n == 1) sa[1] = rnk[1] = 1;
		else for(int &k=sa_k=1; m!=n; k<<=1)
		{
			static int id[MAXN];
			int cur = 0, *w = lst_rnk;
			for(int i=n-k+1; i<=n; ++i) id[++cur] = i;
			for(int i=1; i<=n; ++i) if(sa[i] > k) id[++cur] = sa[i] - k;
			
			memset(t,0,(m+1)<<2);
			for(int i=1; i<=n; ++i) ++t[w[i] = rnk[id[i]]];
			for(int i=1; i<=m; ++i) t[i] += t[i-1];
			for(int i=n; i>=1; --i) sa[t[w[i]]--] = id[i];
			
			m = 0; swap(rnk, lst_rnk);
			for(int i=1; i<=n; ++i)
				rnk[sa[i]] = sa_same(sa[i], sa[i-1])? m: ++m;
		}
		
		for(int i=1,k=0; i<=n; ++i)
		{
			if(rnk[i] == n){ lcp[rnk[i]] = k = 0; continue;}
			if(k) --k;
			int j = sa[rnk[i]+1];
			while(s[i+k] == s[j+k]) ++k;
			lcp[rnk[i]] = st[rnk[i]][0] = k;
		}
		
		for(int i=n; i>=1; --i)
			for(int j=1; i+(1<<j)-1 <= n; ++j)
				st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
	}
	
	inline int get_mn(int l,int r){ int k = lb[r-l+1]; return min(st[l][k], st[r-(1<<k)+1][k]);}
	inline int get_lcp(int i,int j)
	{
		if(i == j) return inf;
		i = rnk[i]; j = rnk[j];
		return i < j? get_mn(i,j-1): get_mn(j,i-1);
	}
	
	inline pii get_seg(int pos,int len)
	{
		int l = pos, r = pos;
		for(int i=lb[l-1]; i>=0; --i)
			if(i <= lb[l-1] && st[l - (1<<i)][i] >= len)
				l -= 1<<i;
		for(int i=lb[n-r]; i>=0; --i)
			if(i <= lb[n-r] && st[r][i] >= len)
				r += 1<<i;
		return make_pair(l,r);
	}
} using SA::sa; using SA::rnk; using SA::get_mn; using SA::get_lcp; using SA::get_seg;

int n;
char s[MAXN];

namespace Subtask1
{
	int rt[MAXN], f[MAXN];
	
	inline bool chk(int pos,int len)
	{
		if(len == 1) return 1;
		int lim = pos + len;
		
		pii seg = get_seg(rnk[pos], len - 1);
		if(SegT::query(rt[lim],1,n, seg.first, seg.second) >= len - 1)
			return 1;
		
		seg = get_seg(rnk[pos+1], len - 1);
		if(SegT::query(rt[lim],1,n, seg.first, seg.second) >= len - 1)
			return 1;
		
		return 0;
	}
	
	void solve(void)
	{
		SA::build(s, n);
		
		int ans = 0, lst = 0, curmx = 0;
		for(int i=n; i>=1; --i)
		{
			while((ll)curmx * (curmx + 1) / 2 <= n - i + 1) ++curmx;
			
			lst = min(lst + 1, curmx - 1);
			while(!chk(i, lst)) --lst;
			
			f[i] = lst;
			ans = max(ans, f[i]);
			SegT::update(rt[i] = rt[i+1], 1, n, rnk[i], f[i]);
		}
		
		printf("%d",ans);
		exit(0);
	}
}

int main(void)
{
	lb[0] = -1; lb[1] = 0;
	for(int i=2; i<MAXN; ++i) lb[i] = lb[i>>1] + 1;
	
	scanf("%d%s",&n,s+1);
	
	Subtask1::solve();
	return 0;
}