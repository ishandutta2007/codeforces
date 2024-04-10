#include <cstdio>
#include <algorithm>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)

const int MOD = 998244353;
const int MK = 1e5 + 100;
const int ML = 1e6 + 10;
const int MV = 1e5 + 1e6 + 100;

int K;
int a[MK];
ll inv[MV];
ll f[2][MV];
void pcpmod(void)
{
	inv[1] = 1;
	for(int i = 2;i < MV;i++)
		inv[i] = (MOD-MOD/i)*inv[MOD%i]%MOD;
	f[0][0] = f[1][0] = 1;
	for(int i = 1;i < MV;i++)
		f[0][i] = f[0][i-1]*i%MOD, f[1][i] = f[1][i-1]*inv[i]%MOD;
}
ll ch(int n, int k) {return f[0][n]*f[1][n-k]%MOD*f[1][k]%MOD;}
ll distr(int n, int k) //n elements, k non-negative buckets
{
	if(n<0) return 0LL;
	return ch(n+k-1,k-1);
}
void solve1(int cp)
{
	ll ans = 0;
	for(int i = 0, j = 0;i < cp;i++)
	{
		for(;a[j]<i;j++);
		ans += distr(i-j, K);
	}
	printf("%d\n", ans%MOD);
}

int v[MK];
int main(void)
{
	pcpmod();
	scanf("%d", &K);
	for(int i = 0;i < K;i++)
		scanf("%d", a+i);
	sort(a, a+K);
	int cp = 0;
	for(;cp < K;cp++)
		if(a[cp] < cp)
			break;
	if(cp != K)
		return solve1(cp), 0;
	ll ans = 0;
	for(int i = 0, j = 0, q = 0;i <= ML;i++)
	{
		ans += distr(i-q,K)-distr(i-q-K+j,K);
		//if(i<10) printf("%d, %d\n", i, ans);
		for(;j < K && i==a[j];j++)
			v[i%K]++;
		q += v[i%K];
	}
	printf("%d\n", ans%MOD);
	return 0;
}