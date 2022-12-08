#include <cstdio>
#define NDEBUG
#include <cassert>

using ll = long long;

const int MN = 55;
const ll MK = 1e18 + 1000;

ll sum(ll a, ll b)
{
	ll r = a+b;
	if(r>MK) return MK;
	return r;
}
ll prod(ll a, ll b)
{
	if(!a||!b) return 0;
	if(a > (MK-1)/b) return MK;
	return a*b;
}

int T;
ll dp[MN];
ll cyc[MN];
ll fact[MN];
void pcp()
{
	fact[0] = 1;
	for(int i = 1;i < MN;++i)
		fact[i] = prod(i, fact[i-1]);
	cyc[1] = 1;
	for(int i = 2;i < MN;++i)
		cyc[i] = fact[i-2];
	dp[0] = 1;
	for(int i = 1;i < MN;++i)
	{
		dp[i] = cyc[i];
		for(int j = 1;j < i;++j)
			dp[i] = sum(dp[i], prod(cyc[j], dp[i-j]));
	}
}
int N;
ll K;

int cr[MN], en[MN];//create val, end val
bool rem[MN];//removed
void outcyc(int n, int offset, ll v)//should be o(n^2)
{
	assert(v < cyc[n]);
	for(int i = 0;i < n;++i)
		cr[i] = i, rem[i] = 0, en[i] = i;
	printf("%d ", offset+n-1);
	for(int i = 1;i < n-1;++i)
	{
		ll q = fact[n-i-2];
		int c = v/q;
		v%=q;

		rem[cr[i]] = 1;
		int k = 0;
		for(;rem[k] || c;++k)
			if(!rem[k])
				--c;
		rem[cr[i]] = 0;
		rem[k] = 1;
		printf("%d ", offset+k);
		en[cr[i]] = en[k];
		cr[en[k]] = cr[i];
	}
	for(int i = 0;i < n-1;++i)
		if(!rem[i])
			printf("%d ", offset+i);
}
void solve()
{
	scanf("%d%lld", &N, &K);
	--K;
	if(K >= dp[N])
		return (void) printf("-1\n");
	for(int i = 0, j;i < N;i+=j)
	{
		ll v = 0LL;
		for(j=1;(v=cyc[j]*dp[N-i-j]) <= K;++j, K -= v);
		outcyc(j, i+1, K/dp[N-i-j]);
		K %= dp[N-i-j];
	}
	printf("\n");
}
int main(void)
{
	pcp();
	scanf("%d", &T);
	for(int i = 1;i <= T;++i)
		solve();
	return 0;
}