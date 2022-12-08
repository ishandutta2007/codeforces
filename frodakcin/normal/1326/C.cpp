#include <cstdio>

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)
const int MOD = 998244353;
 
//copied from benq
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

const int MN = 2e5 + 100;
int N, K, p[MN];
int pos[MN], P;
mint ans;

int main(void)
{
	scanf("%d%d", &N, &K);
	for(int i = 0;i < N;++i)
	{
		scanf("%d", p+i);
		if(p[i] + K > N)
			pos[P++] = i;
	}
	printf("%lld ", tl(K)*(N+N-K+1)/2);
	ans = mint(1);
	for(int i = 0;i < K-1;++i)
		ans *= mint(pos[i+1] - pos[i]);
	printf("%d\n", ti(ans));
	return 0;
}