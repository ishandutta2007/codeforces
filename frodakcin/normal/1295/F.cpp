#include <cstdio>
#include <algorithm>

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)

const int MOD = 998244353;
const int INF = 1e9;
const int MN = 60;

struct mint
{
public:
	int v;
	mint(int init = 0) : v(init)
	{
		if(v < 0) v = ti((v+tl(MOD)*1000)%MOD);
		if(MOD <= v) v %= MOD;
	}
	operator int() const {return v;}
	mint operator + (mint o)const {return mint(v+o.v<MOD?v+o.v:v+o.v-MOD);}
	mint operator - (mint o)const {return mint(v<o.v?v-o.v+MOD:v-o.v);}
	mint operator * (mint o)const {return mint(ti(tl(v)*o.v%MOD));}
	void operator += (mint o){v = v+o.v<MOD?v+o.v:v+o.v-MOD;}
	mint operator *= (mint o){return mint(v = ti(tl(v)*o.v%MOD));}
};
mint inv[MN];
void pcp()
{
	inv[1] = mint(1);
	for(int i = 2;i < MN;++i)
		inv[i] = mint(MOD-MOD/i)*inv[MOD%i];
}
mint pow(mint b, int p)
{
	mint r(1);
	for(;p;p>>=1, b*=b) if(p&1) r*=b;
	return r;
}

int N;
mint dp[MN][MN*2];
int a[MN][2];
int x[MN*2], X;
mint tot, ans;

int main(void)
{
	pcp();
	scanf("%d", &N);
	tot = mint(1);
	for(int i = 0;i < N;++i)
	{
		scanf("%d%d", a[i], a[i]+1);
		x[i<<1] = a[i][0], x[i<<1|1] = ++a[i][1];
		tot *= mint(a[i][1]-a[i][0]);
	}
	x[N*2] = -1;
	std::sort(x, x+(N*2+1));
	X = std::unique(x, x+(N*2+1)) - x;
	x[X] = INF;
	dp[0][X-1] = mint(1);
	for(int i = 0;i < N;++i)//transition i -> i+k
	{
		mint c = dp[i][X-1];
		for(int j = X-2;j >= 0;--j)
		{
			int s = x[j+1]-x[j];
			mint q = c;
			for(int k = i;k < N;++k)
				if(a[k][0] <= x[j] && x[j] < a[k][1])
					dp[k+1][j] += q *= mint(s + k - i) * inv[k - i + 1];
				else
					break;
			c += dp[i][j];
		}
	}
	for(int i = 0;i < X;++i)
		ans += dp[N][i];
	printf("%d\n", ti(ans * pow(tot, MOD-2)));
	return 0;
}