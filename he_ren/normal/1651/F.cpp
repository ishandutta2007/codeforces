#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXP = MAXN * 19;

ll sumc[MAXP], sumd[MAXP];
int ls[MAXP], rs[MAXP], pcnt = 0;
#define lson(u) ls[u],l,mid
#define rson(u) rs[u],mid+1,r

void insert(int &u,int l,int r,int q,ll kc,ll kd)
{
	++pcnt;
	ls[pcnt] = ls[u]; rs[pcnt] = rs[u];
	sumc[pcnt] = sumc[u] + kc;
	sumd[pcnt] = sumd[u] + kd;
	u = pcnt;
	if(l == r) return;
	int mid = (l+r)>>1;
	if(q<=mid) insert(lson(u),q,kc,kd);
	else insert(rson(u),q,kc,kd);
}

int n;
ll c[MAXN], d[MAXN];
ll mxtim[MAXN];

ll keytim[MAXN];
int rt[MAXN];

struct Seg
{
	int L, R;
	ll beg, delta;
	Seg(void){}
	Seg(int _L,int _R,ll _beg,ll _delta): L(_L), R(_R), beg(_beg), delta(_delta) {}
	pair<ll,int> query(ll t,ll rem) const
	{
		assert(rem > 0);
		if(L == R)
		{
			ll cur = min(c[L], delta + (t - beg) * d[L]);
			if(cur < rem) return {rem - cur, L+1};
			else return {rem, L};
		}
		assert(delta == 0);
		
		auto dfs = [&] (auto self,int u1,int u2,int l,int r)
		{
			if(L <= l && r <= R)
			{
				ll cur = sumc[u1] + (sumd[u2] - sumd[u1]) * (t - beg);
				if(cur < rem){ rem -= cur; return r+1;}
				if(l == r) return r;
			}
			int mid = (l+r)>>1;
			if(L<=mid)
			{
				int res = self(self, ls[u1], lson(u2));
				if(res <= mid) return res;
			}
			if(mid<R)
				return self(self, rs[u1], rson(u2));
			return R+1;
		};
		
		int pos = upper_bound(keytim+1, keytim+n+1, t - beg) - keytim - 1;
		int tmp = dfs(dfs, rt[pos], rt[n], 1, n);
		return {rem, tmp};
	}
};

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%lld%lld",&c[i],&d[i]);
	
	for(int i=1; i<=n; ++i)
		mxtim[i] = (c[i] + d[i] - 1) / d[i];
	
	static int id[MAXN];
	iota(id+1,id+n+1,1);
	sort(id+1,id+n+1,[&] (int x,int y){
		return mxtim[x] < mxtim[y];
	});
	
	for(int i=1; i<=n; ++i)
	{
		keytim[i] = mxtim[id[i]];
		insert(rt[i] = rt[i-1], 1, n, id[i], c[id[i]], d[id[i]]);
	}
	
	ll ans = 0;
	
	static Seg sta[MAXN];
	int tp = 0;
	sta[++tp] = Seg(1, n, -1e9 - 10, 0);
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		ll t,h;
		scanf("%lld%lld",&t,&h);
		
		while(1)
		{
			if(!tp)
			{
				sta[++tp] = Seg(1, n, t, 0);
				break;
			}
			auto cur = sta[tp--];
			auto tmp = cur.query(t, h);
			ll rem = tmp.first;
			int pos = tmp.second;
			if(pos > cur.R)
			{
				h = rem;
				continue;
			}
			
			if(pos+1 <= cur.R)
				sta[++tp] = Seg(pos+1, cur.R, cur.beg, 0);
			
			{
				ll curval = min(c[pos], cur.delta + (t - cur.beg) * d[pos]);
				sta[++tp] = Seg(pos, pos, t, curval - rem);
			}
			
			if(1 <= pos-1)
				sta[++tp] = Seg(1, pos-1, t, 0);
			
			h = 0;
			break;
		}
		
		ans += h;
	}
	
	printf("%lld",ans);
	return 0;
}