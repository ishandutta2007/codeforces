#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;
const int mod = 1e9 + 7;

struct Segment_Tree
{
	ll sum[MAXN<<2], tag[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u){ sum[u] = sum[ls(u)] + sum[rs(u)];}
	inline void push_down(int u,int l,int r,int mid)
	{
		sum[ls(u)] += (mid-l+1) * tag[u]; tag[ls(u)] += tag[u];
		sum[rs(u)] += (r-mid) * tag[u]; tag[rs(u)] += tag[u];
		tag[u] = 0;
	}
	inline void update(int u,int l,int r,int ql,int qr,int k)
	{
		if(ql<=l && r<=qr){ sum[u]+=(r-l+1)*(ll)k; tag[u]+=k; return;}
		int mid = (l+r)>>1;
		push_down(u,l,r,mid);
		if(ql<=mid) update(lson(u),ql,qr,k);
		if(mid<qr) update(rson(u),ql,qr,k);
		push_up(u);
	}
	inline ll query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return sum[u];
		int mid = (l+r)>>1;
		push_down(u,l,r,mid);
		ll res = 0;
		if(ql<=mid) res += query(lson(u),ql,qr);
		if(mid<qr) res += query(rson(u),ql,qr);
		push_up(u);
		return res;
	}
}pre, suf;

int a[MAXN];
pii b[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i) b[i] = make_pair(a[i], i);
	sort(b+1,b+n+1);
	
	ll ans = 0;
	for(int i=1; i<=n; ++i)
	{
		int pos = b[i].second;
		
		ll lef = suf.query(1,1,n,1,pos) - (pos==n? 0: suf.query(1,1,n ,pos+1,pos+1) * pos);
		suf.update(1,1,n, 1,pos,1);
		
		pre.update(1,1,n, pos,n,1);
		ll rig = pre.query(1,1,n,pos,n) - (pos==1? 0: pre.query(1,1,n, pos-1,pos-1) * (n-pos+1));
		
		lef = lef%mod * (n-pos+1) %mod;
		rig = rig%mod * pos %mod;
		
		ans = (ans + (lef + rig) * b[i].first) %mod;
	}
	printf("%lld",ans);
	return 0;
}