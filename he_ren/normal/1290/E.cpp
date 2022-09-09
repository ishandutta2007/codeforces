#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1.5e5 + 5;
const int inf = 0x3f3f3f3f;

struct Segment_Tree
{
	int fir[MAXN<<2], fcnt[MAXN<<2], sec[MAXN<<2], tag[MAXN<<2], ftag[MAXN<<2];
	int cnt[MAXN<<2];
	ll sum[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void clear(void)
	{
		#define CLN(arr) memset(arr,0,sizeof(arr))
		memset(fir, 0x3f, sizeof(fir));
		memset(sec, 0x3f, sizeof(sec));
		CLN(fcnt); CLN(tag); CLN(ftag); CLN(cnt); CLN(sum);
		#undef CLN
	}
	inline void push_up(int u)
	{
		int l = ls(u), r = rs(u);
		cnt[u] = cnt[l] + cnt[r];
		sum[u] = sum[l] + sum[r];
		if(fir[l] == fir[r])
		{
			fir[u] = fir[l]; fcnt[u] = fcnt[l] + fcnt[r];
			sec[u] = min(sec[l], sec[r]);
		}
		else
		{
			if(fir[l] > fir[r]) swap(l, r);
			fir[u] = fir[l]; fcnt[u] = fcnt[l];
			sec[u] = min(sec[l], fir[r]);
		}
	}
	inline void upd_add(int u,int k)
	{
		tag[u] += k; sum[u] += (ll)k * cnt[u];
		fir[u] += k; sec[u] += k;
	}
	inline void upd_fir(int u,int k)
	{
		ftag[u] += k; fir[u] += k;
		sum[u] += (ll)fcnt[u] * k;
	}
	inline void push_down(int u)
	{
		if(tag[u])
		{
			upd_add(ls(u), tag[u]); upd_add(rs(u), tag[u]);
			tag[u] = 0;
		}
		if(ftag[u])
		{
			if(fir[ls(u)] == fir[rs(u)])
				upd_fir(ls(u), ftag[u]), upd_fir(rs(u), ftag[u]);
			else if(fir[ls(u)] < fir[rs(u)])
				upd_fir(ls(u), ftag[u]);
			else
				upd_fir(rs(u), ftag[u]);
			ftag[u] = 0;
		}
	}
	void update_add(int u,int l,int r,int ql,int qr,int k)
	{
		if(!cnt[u]) return;
		if(ql<=l && r<=qr){ upd_add(u,k); return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) update_add(lson(u),ql,qr,k);
		if(mid<qr) update_add(rson(u),ql,qr,k);
		push_up(u);
	}
	void chk_max(int u,int l,int r,int ql,int qr,int k)
	{
		if(!cnt[u] || fir[u] >= k) return;
		if(ql<=l && r<=qr && sec[u] >= k){ upd_fir(u, k-fir[u]); return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) chk_max(lson(u),ql,qr,k);
		if(mid<qr) chk_max(rson(u),ql,qr,k);
		push_up(u);
	}
	void set(int u,int l,int r,int q,int k)
	{
		if(l == r)
		{
			fir[u] = k; sec[u] = inf; fcnt[u] = 1;
			tag[u] = ftag[u] = 0;
			cnt[u] = 1; sum[u] = k;
			return;
		}
		push_down(u);
		int mid = (l+r)>>1;
		if(q<=mid) set(lson(u),q,k);
		else set(rson(u),q,k);
		push_up(u);
	}
	int get_cnt(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return cnt[u];
		push_down(u);
		int mid = (l+r)>>1, res = 0;
		if(ql<=mid) res += get_cnt(lson(u),ql,qr);
		if(mid<qr) res += get_cnt(rson(u),ql,qr);
		return res;
	}
	
	int n;
	inline void update_add(int ql,int qr,int k){ update_add(1,1,n,ql,qr,k);}
	inline void chk_max(int ql,int qr,int k){ chk_max(1,1,n,ql,qr,k);}
	inline void set(int q,int k){ set(1,1,n,q,k);}
	inline ll get_all_sum(void){ return sum[1];}
	inline int get_cnt(int ql,int qr){ return ql<=qr? get_cnt(1,1,n,ql,qr): 0;}
}tree;

int n;
int a[MAXN];

inline vector<ll> get_res(void)
{
	tree.clear();
	tree.n = n;
	
	static int pos[MAXN];
	for(int i=1; i<=n; ++i) pos[a[i]] = i;
	
	vector<ll> res(n);
	for(int i=1; i<=n; ++i)
	{
		int p = pos[i];
		int id = tree.get_cnt(1, p) + 1;
		tree.update_add(p+1, n, 1);
		tree.chk_max(p+1, n, id+1);
		tree.set(p, 1);
		
		res[i-1] = (ll)i * (i+1) / 2 - tree.get_all_sum();
	}
	return res;
}

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	vector<ll> p = get_res();
	reverse(a+1,a+n+1);
	vector<ll> q = get_res();
	
	for(int i=0; i<n; ++i)
		printf("%lld\n",p[i] + q[i] + (i+1));
	return 0;
}