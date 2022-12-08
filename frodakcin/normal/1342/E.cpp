#include <cstdio>

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)
const int MOD = 998244353;
 
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

const int MN = 2e5 + 10;
mint f[2][MN*2], inv[MN*2];
void pcp()
{
	f[0][0] = f[1][0] = mint(1);
	inv[1] = mint(1);
	for(int i = 2;i < MN*2;++i)
		inv[i] = mint(MOD) - mint(MOD/i) * inv[MOD%i];
	for(int i = 1;i < MN*2;++i)
		f[0][i] = f[0][i-1]*mint(i), f[1][i] = f[1][i-1]*inv[i];
}
mint ch(int n, int k)
{
	if(k > n) return mint(0);
	return f[0][n]*f[1][k]*f[1][n-k];
}

int N;
ll K;
mint ans;

int main(void)
{
	pcp();

	scanf("%d%lld", &N, &K);
	if(K == 0)
		return printf("%d\n", f[0][N]), 0;
	if(K >= N)
		return printf("0\n"), 0;
	
	int c = N-ti(K);
	for(int i = 1;i <= c;++i)
		if(c+i&1)
			ans -= ch(c, i)*pow(mint(i), N);
		else
			ans += ch(c, i)*pow(mint(i), N);
	ans *= ch(N, c);
	printf("%d\n", ans*mint(2));
	return 0;
}