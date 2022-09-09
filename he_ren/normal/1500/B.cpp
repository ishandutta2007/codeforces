#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;
const int MAXM = 5e5 + 5;
const int MAXA = MAXN * 2;

inline ll gcd(ll a,ll b){ return b? gcd(b,a%b): a;}
inline ll lcm(ll a,ll b){ return a / gcd(a,b) * b;}

inline ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b) return x = 1, y = 0, a;
	ll t = exgcd(b, a%b, y, x);
	y -= a / b * x;
	return t;
}

int n,m;
ll d;
int a[MAXN], b[MAXM];

ll com, fir[MAXN];
inline bool chk(ll mid)
{
	ll res = mid + 1;
	for(int i=0; i<n; ++i) if(fir[i] != -1 && fir[i] <= mid)
		res -= (mid - fir[i]) / com + 1;
	return res >= d;
}

int main(void)
{
	scanf("%d%d%lld",&n,&m,&d);
	for(int i=0; i<n; ++i) scanf("%d",&a[i]);
	for(int i=0; i<m; ++i) scanf("%d",&b[i]);
	
	static int posb[MAXA];
	memset(posb,-1,sizeof(posb));
	for(int i=0; i<m; ++i) posb[b[i]] = i;
	
	com = lcm(n,m);
	memset(fir,-1,sizeof(fir));
	for(int i=0; i<n; ++i) if(posb[a[i]] != -1)
	{
		int j = posb[a[i]];
		ll x, y, t = exgcd(n, m, x, y);
		if((j-i) % t) continue;
		x *= (j-i) / t;
		
		fir[i] = (n * x + i) % com;
		if(fir[i] < 0) fir[i] += com;
	}
	
	ll l = 0, r = 2e18;
	while(l < r)
	{
		ll mid = (l+r) >> 1;
		if(chk(mid)) r = mid;
		else l = mid+1;
	}
	printf("%lld",l + 1);
	return 0;
}