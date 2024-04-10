#include <cstdio>
//#define NDEBUG
#include <cassert>

using ll = long long;

const int MN = 1e5 + 100;
const int MP = 1e4 + 100;
const int MOD = 1e9 + 7;

ll pw(ll b, int p)
{
	ll r = 1LL;
	for(;p;p>>=1,b=b*b%MOD)if(p&1)r=r*b%MOD;
	return r;
}
int N, K;

int p[MP], q[MN];
int t[MN], l[MN], T[MN];
void pcpp(void)
{
	for(int i = 2;i <= N;++i)
	{
		if(!q[i]) t[i] = i-1, p[l[i]=++p[0]] = i;
		for(int j = 1, k;j <= p[0] && (k = i*p[j]) <= N;++j)
		{
			assert(!q[k]), q[k] = 1, l[k] = j;
			if(l[i]==j) {t[k] = t[i] * p[j]; break;}
			t[k] = t[i] * (p[j]-1);
		}
	}
}
ll v[MN], f, z[MN];
int main(void)
{
	scanf("%d%d", &N, &K);
	pcpp();
	z[0] = 1LL, z[1] = pw(K, MOD-2);
	for(int i = 1;i < N;++i) z[i+1] = z[i]*z[1]%MOD;
	for(int i = 0;i <= N;++i)
		T[i+1] = (t[i]+T[i])%MOD;
	for(int i = 1;i < N;++i)
		v[i] = N-i-1;
	for(int g = 1;g < N;++g)
	{
		int k = (N+g-1)/g;
		v[g] += T[k+1];
		if(k*g>N) v[k*g-N] -= t[k];
	}
	for(int i = 1;i < N;++i)
		f += v[i]*z[N-i]%MOD;
	printf("%lld\n", f%MOD);
	return 0;
}