#include <cstdio>
#include <cassert>
#include <algorithm>
#include <functional>

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)
const int MOD = 1e9+7;
 
struct mint
{
public:
	int val;
	mint(int _val = 0) : val(_val)
	{
		val = (-MOD <= val && val < MOD) ? val : val%MOD;
		if(val < 0) val += MOD;
	}
	explicit operator int () const {return val;}

	mint operator -() const {return mint(-val);}
	mint& operator += (mint m) {if((val += m.val) >= MOD) val -= MOD; return *this;}
	mint& operator -= (mint m) {if((val -= m.val) < 0) val += MOD; return *this;}
	mint& operator *= (mint m) {val = ti(tl(val)*m.val%MOD); return *this;}

	friend mint pow(mint a, int p)
	{
		mint r(1);
		for(;p;p>>=1, a*=a) if(p&1) r*=a;
		return r;
	}

	friend mint operator + (mint a, mint b) {return a += b;}
	friend mint operator - (mint a, mint b) {return a -= b;}
	friend mint operator * (mint a, mint b) {return a *= b;}
};

const int MN = 1e6+100;
ll mul(ll& a, const ll& b)
{
	if((a*=b)>MN)
		a=MN;
}
ll pow(ll b, int p)
{
	ll r=1;
	for(;p;p>>=1,mul(b,b))
		if(p&1)
			mul(r,b);
	return r;
}

int T, N, P, k[MN];
int u[MN];
ll ctr;
int main(void)
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &N, &P);
		for(int i=0;i<N;++i)
			scanf("%d", k+i);
		std::sort(k, k+N);
		mint ans(0);
		ctr=0;
		for(int i=N-1;i>=0;--i)
		{
			if(ctr)
				mul(ctr, pow(P, k[i+1]-k[i]));
			mint v = pow(mint(P), k[i]);
			if(ctr)
				ans-=v, --ctr;
			else
				++ctr, ans+=v;
		}
		printf("%d\n", ans);
	}
	return 0;
}