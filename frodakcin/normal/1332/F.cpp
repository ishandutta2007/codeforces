#include <cstdio>
#include <vector>

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

const int MN = 3e5 + 100;

std::vector<int> a[MN];
int N;
mint dp[MN][4];
void dfs(int n = 1, int p = 0)
{
	dp[n][0] = mint(1);//dp[n][0] and dp[n][1] are technically the same
	dp[n][1] = mint(1);
	dp[n][2] = mint(0);
	dp[n][3] = mint(0);
	for(int x : a[n])
		if(x != p)
		{
			dfs(x, n);
			dp[n][2] = dp[n][2] * (dp[x][0] + dp[x][0] + dp[x][1] + dp[x][2] + dp[x][2] + dp[x][3] + dp[x][3]) + dp[n][0] * (dp[x][0] + dp[x][1] + dp[x][2] + dp[x][3]);
			dp[n][3] = dp[n][3] * (dp[x][0] + dp[x][0] + dp[x][2] + dp[x][2] + dp[x][3]) + dp[n][1] * (dp[x][0] + dp[x][2]);
			dp[n][0] *= (dp[x][0] + dp[x][2] + dp[x][3]);
			dp[n][1] *= (dp[x][0] + dp[x][2] + dp[x][3]);
			//printf("%d %d %d %d\n", dp[n][0], dp[n][1], dp[n][2], dp[n][3]);
		}
}
int main(void)
{
	scanf("%d", &N);
	for(int i = 0, x, y;i+1 < N;++i)
		scanf("%d%d", &x, &y), a[x].push_back(y), a[y].push_back(x);
	dfs();
	printf("%d\n", dp[1][0] + dp[1][2] + dp[1][3] - mint(1));
	return 0;
}