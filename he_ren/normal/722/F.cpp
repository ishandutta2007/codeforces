#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;
const int LB = 17 + 2;

int lb[MAXN];

ll gcd(ll a,ll b){ return b? gcd(b,a%b): a;}
inline ll lcm(ll a,ll b){ return a / gcd(a,b) * b;}

ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b) return x = 1, y = 0, a;
	ll t = exgcd(b, a%b, y, x);
	y -= a / b * x;
	return t;
}

int n,m;
vector<int> a[MAXN];

namespace Subtask1
{
	vector<pii> apos[MAXM];
	
	inline ll slow_mul(ll a,ll b,ll pmod)
	{
		a %= pmod; b %= pmod;
		if(a < 0) a += pmod; if(b < 0) b += pmod;
		static int lim = 2e9;
		if(a <= lim && b <= lim) return a * b %pmod;
		
		ll res = 0;
		while(b)
		{
			if(b&1){ res += a; if(res >= pmod) res -= pmod;}
			a += a; if(a >= pmod) a -= pmod;
			b >>= 1;
		}
		return res;
	}
	
	inline pll merge(pll P,pll Q)
	{
		if(!P.first || !Q.first) return make_pair(0ll, 0ll);
		ll p1 = P.first, r1 = P.second, p2 = Q.first, r2 = Q.second;
		
		ll x, y, t = exgcd(p1, p2, x, y), c = r1 - r2;
		if(c % t) return make_pair(0ll, 0ll);
		x *= c / t;
		ll p3 = p1 / t * p2, r3 = r1 - slow_mul(x, p1, p3);
		r3 %= p3; if(r3 < 0) r3 += p3;
		return make_pair(p3, r3);
	}
	
	int totf;
	pll f[MAXN][LB];
	
	inline void calc_f(void)
	{
		for(int i=totf; i>=1; --i)
			for(int j=1; i+(1<<j)-1 <= totf; ++j)
				f[i][j] = merge(f[i][j-1], f[i + (1<<(j-1))][j-1]);
	}
	
	inline bool chk(int l,int r)
	{
		int k = lb[r-l+1];
		return merge(f[l][k], f[r-(1<<k)+1][k]).first != 0;
	}
	
	inline bool chk(int len)
	{
		for(int i=1; i+len-1 <= totf; ++i)
			if(chk(i, i+len-1)) return 1;
		return 0;
	}
	
	void solve(void)
	{
		for(int i=1; i<=n; ++i)
			for(int j=0; j<(int)a[i].size(); ++j)
				apos[a[i][j]].push_back(make_pair(i,j));
		
		for(int C=1; C<=m; ++C)
		{
			vector<pii> &vec = apos[C];
			vector<pii> lrs;
			for(int i=0,j=0; i<(int)vec.size(); i=j)
			{
				j = i + 1;
				while(j<(int)vec.size() && vec[j].first == vec[j-1].first + 1)
					++j;
				lrs.push_back(make_pair(- (j - i), i));
			}
			sort(lrs.begin(), lrs.end());
			
			int ans = 0;
			for(int it = 0; it < (int)lrs.size() && -lrs[it].first > ans; ++it)
			{
				int i = lrs[it].second, j = i - lrs[it].first;
				
				totf = 0;
				for(int k=i; k<j; ++k)
					f[++totf][0] = make_pair((int)a[vec[k].first].size(), vec[k].second);
				
				calc_f();
				
				if(!chk(ans + 1)) continue;
				int l = ans + 1, r = totf;
				while(l < r)
				{
					int mid = (l+r+1)>>1;
					if(chk(mid)) l = mid;
					else r = mid-1;
				}
				ans = max(ans, l);
			}
			
			printf("%d\n",ans);
		}
		exit(0);
	}
}

int main(void)
{
	lb[0] = -1;
	for(int i=2; i<MAXN; ++i) lb[i] = lb[i>>1] + 1;
	
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
	{
		int k;
		scanf("%d",&k);
		a[i].resize(k);
		for(int j=0; j<k; ++j) scanf("%d",&a[i][j]);
	}
	
	Subtask1::solve();
	return 0;
}