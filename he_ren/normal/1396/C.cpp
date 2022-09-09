#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int linf = 0x3f3f3f3f;

ll solve(ll a[],ll p[],ll q[],int n,ll d)
{
	static ll f[MAXN];
	f[0] = 0; f[1] = p[1];
	for(int i=2; i<=n; ++i)
		f[i] = min(f[i-1] + p[i], f[i-2] + q[i-1] + q[i] + d * 2);
	return f[n];
}

ll a[MAXN];
ll p[MAXN], q[MAXN];
ll sump[MAXN], sumq[MAXN];

int main(void)
{
	int n;
	ll r1,r2,r3,d;
	scanf("%d%lld%lld%lld%lld",&n,&r1,&r2,&r3,&d);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	
	for(int i=1; i<=n; ++i)
		p[i] = a[i] * r1 + r3,
		q[i] = min((a[i]+1)*r1, r2) + r1;
	
	for(int i=1; i<=n; ++i)
		sump[i] = sump[i-1] + p[i],
		sumq[i] = sumq[i-1] + q[i];
	
	
	static ll f[MAXN];
	f[0] = 0; f[1] = p[1];
	for(int i=2; i<=n; ++i)
		f[i] = min(f[i-1] + p[i], f[i-2] + q[i-1] + q[i] + d * 2);
	
	ll ans = f[n];
	for(int i=1; i<n; ++i)
		ans = min(ans, f[i-1] + sumq[n-1] - sumq[i-1] + p[n] + d * (n-i));
	ans = min(ans, solve(a,p,q,n-1,d) + d*2 + q[n]);
	
	printf("%lld\n",ans + (n-1) * d);
	return 0;
}