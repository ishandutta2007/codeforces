#include <cstdio>
#include <cassert>

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
		mint(ll _val) // should work
		{
			val = _val%MOD;
			if(val < 0) val += MOD;
		}
		explicit operator int () const {return val;}

		mint operator -() const {return mint(-val);}
		mint& operator += (const mint& m) {if((val += m.val) >= MOD) val -= MOD; return *this;}
		mint& operator -= (const mint& m) {if((val -= m.val) < 0) val += MOD; return *this;}
		mint& operator *= (const mint& m) {val = ti(tl(val)*m.val%MOD); return *this;}

		template<typename T>
		friend mint pow(mint a, T p)
		{
			mint r(1);
			for(;p;p>>=1, a*=a) if(p&1) r*=a;
			return r;
		}

		friend mint operator + (mint a, const mint& b) {return a += b;}
		friend mint operator - (mint a, const mint& b) {return a -= b;}
		friend mint operator * (mint a, const mint& b) {return a *= b;}
};

const int MN = 1e5+10;
 
mint inv[MN], F[2][MN];
 
void pcp()
{
	inv[1]=mint(1);
	for(int i=2;i<MN;++i)
		inv[i]=mint(MOD-MOD/i)*inv[MOD%i];
	F[0][0]=F[1][0]=mint(1);
	for(int i=1;i<MN;++i)
		F[0][i]=F[0][i-1]*mint(i), F[1][i]=F[1][i-1]*inv[i];
}

mint choose(int n, int k) {assert(0 <= k && k <= n); return F[0][n]*F[1][k]*F[1][n-k];}

int N;
char s[MN];

void solve()
{
	scanf("%d", &N);
	scanf(" %s", s);

	int pairs=0, slots=0;
	for(int i=0;i<N;++i)
	{
		if(s[i] == '0') ++slots;
		else
			if(i+1<N && s[i+1]=='1') ++pairs, ++i;
	}

	//count
	printf("%d\n", choose(pairs+slots, slots));
}

int main()
{
	pcp();
	int T;
	scanf("%d",  &T);
	while(T--) solve();
	return 0;
}