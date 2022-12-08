#include <cstdio>
#include <cassert>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)

const int MOD = 1e9 + 7;
const int MN = 2e5 + 100;
int N;
ll T;

ll f[2][MN];
ll inv[MN];
ll p2[2][MN];

void pcp(void)
{
	f[0][0] = f[1][0] = 1LL;
	inv[1] = 1;
	for(int i = 2;i < MN;i++)
		inv[i] = (MOD-MOD/i)*inv[MOD%i]%MOD;//assert(inv[i]*i%MOD == 1);
	for(int i = 1;i < MN;i++)
		f[0][i]=f[0][i-1]*i%MOD, f[1][i]=f[1][i-1]*inv[i]%MOD;
	p2[0][0] = p2[1][0] = 1LL;
	for(int i = 1;i < MN;i++)
		p2[0][i] = p2[0][i-1]*2%MOD, p2[1][i] = p2[1][i-1]*inv[2]%MOD;
}
ll choose(int n, int k) {if(k>n) return 0; else return f[0][n]*f[1][k]%MOD*f[1][n-k]%MOD;}

ll ans;
ll sm, t;

ll pn = 0, pk = 0, pv = 1;
void inc(void)//pn,pk -> pn+1,pk+1
{
	pv = (pv*2+choose(pn,pk+1)+MOD)%MOD;
	pn++, pk++;
}
ll pick(ll n, ll k)//pick <= k elements 
{
	for(;pn<n;inc());
	for(;pk > k;pk--)
		pv = (pv-choose(n, pk))%MOD;
	//printf("%lld %lld %lld\n", n, k, pv);
	return pv;
}
int main(void)
{
	pcp();
	scanf("%d%lld", &N, &T);
	for(int i = 1;i <= N;i++)
	{
		scanf("%lld", &t);
		sm += t;
		if(sm+i <= T) ans++;
		else if(sm>T) break;
		else ans = (ans+(pick(i, T-sm)+MOD)%MOD*p2[1][i]%MOD)%MOD;
	}
	printf("%lld\n", ans%MOD);
	return 0;
}