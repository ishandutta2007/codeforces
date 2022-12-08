#include <cstdio>
#include <cassert>
#include <cstring>

const int MOD = 998244353;
const int MV = 3e5+10;

using ll = long long;

template<int M> struct _mint
{
	public:
		int v;
		_mint(int _v=0): v(_v) {}

		_mint& operator += (const _mint& o) {if((v+=o.v)>=M) v-=M; return *this;}
		_mint& operator -= (const _mint& o) {if((v-=o.v)<0) v+=M; return *this;}
		_mint& operator *= (const _mint& o) {return v=(ll)v*o.v%MOD, *this;}

		friend _mint operator + (_mint a, const _mint& b) {return a+=b;}
		friend _mint operator - (_mint a, const _mint& b) {return a-=b;}
		friend _mint operator * (_mint a, const _mint& b) {return a*=b;}

		operator int() const {return v;}
		operator bool() const {return v;}
};
using mint = _mint<MOD>;

int N, cnt[MV], p[MV], P, n[MV], l[MV], tot;
bool c[MV];
mint dp[MV], inv[10];

int gcd(int a, int b) {return a?gcd(b%a,a):b;}
void sieve()
{
	inv[0]=mint(0);
	inv[1]=mint(1);
	for(int i=2;i<10;++i)
		inv[i]=inv[MOD%i]*mint(MOD-MOD/i);
	for(int i=2;i<MV;++i)
	{
		if(!c[i])
			p[P++]=i, n[i]=1, l[i]=P-1;
		for(int j=0,k;(k=p[j]*i)<MV;++j)
		{
			assert(!c[k]);
			c[k]=1;
			l[k]=j;
			if(j==l[i])
			{
				n[k]=n[i];
				break;
			}
			else
				n[k]=i;
		}
	}
}

int get(int v)
{
	int f=1;
	for(;v>1;v=n[v])
		f*=p[l[v]];
	return f;
}

mint choose(int n, int k)
{
	if(n<k) return mint(0);
	mint f(1);
	for(int i=0;i<k;++i)
		f*=mint(n-i)*inv[1+i];
	return f;
}

int main()
{
	sieve();
	scanf("%d", &N);
	for(int i=0,v;i<N;++i)
	{
		scanf("%d", &v);
		v=get(v);
		tot=gcd(tot,v);
		++cnt[v];
	}
	for(int i=1;i<MV;++i)
		for(int j=2*i;j<MV;j+=i)
			cnt[i]+=cnt[j];
	if(tot>1)
		return printf("-1\n"), 0;
	for(int i=1;i<=7;++i)
	{
		memset(dp, 0, sizeof dp);
		for(int j=MV-1;j>=1;--j)
		{
			dp[j] = choose(cnt[j], i);
			for(int k=j*2;k<MV;k+=j)
				dp[j]-=dp[k];
		}
		if(dp[1])
			return printf("%d\n", i), 0;
	}
	assert(0);
	return 0;
}