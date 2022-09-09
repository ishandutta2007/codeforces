#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int mod = 998244353;

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

ll fac[MAXN], inv[MAXN];
inline ll c(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

struct Node
{
	int l,r;
}p[MAXN];

vector<pii> g;

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXN; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXN-1] = pw(fac[MAXN-1], mod-2);
	for(int i=MAXN-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i)
		scanf("%d%d",&p[i].l,&p[i].r);
	
	for(int i=1; i<=n; ++i)
		g.push_back(make_pair(p[i].l, i)),
		g.push_back(make_pair(p[i].r+1, -i));
	sort(g.begin(), g.end());
	
	int cnt = 0;
	
	int ans = 0;
	for(int i=0; i<(int)g.size(); ++i)
	{
		int u = g[i].second;
		if(u > 0)
		{
			ans = (ans + c(cnt, d-1)) %mod;
			++cnt;
		}
		else --cnt;
	}
	
	printf("%d",ans);
	return 0;
}