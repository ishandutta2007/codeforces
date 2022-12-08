#include <cstdio>
#include <cstring>
#include <algorithm>

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

const int MN = 3e3 + 100;
char s[MN], t[MN];
int S, T;

mint dp[MN][MN];
mint ans;
int main(void)
{
	scanf(" %s %s", s, t);
	for(;s[S];++S);
	for(;t[T];++T);
	for(int i = 0;i < S;++i)
		if(i >= T || t[i] == s[0])
			dp[i][i+1] = 2;
	for(int i = 1;i < S;++i)
	{
		for(int j = 0;j+i <= S;++j)
		{
			if(j && (j-1 >= T || t[j-1] == s[i]))
				dp[j-1][j+i] += dp[j][j+i];
			if(j+i+1 <= S && (j+i >= T || t[j+i] == s[i]))
				dp[j][j+i+1] += dp[j][j+i];
		}
		if(i >= T)
			ans += dp[0][i];
	}
	printf("%d\n", ans + dp[0][S]);
	return 0;
}