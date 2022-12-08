#include <cstdio>
#include <algorithm>

using ll = long long;
const int MOD = 1e9+7;

struct mint
{
public:
	int v;
	mint(int _v=0): v(_v)
	{
		if(v < -MOD || MOD <= v) v %= MOD;
		if(v<0) v+=MOD;
	}
	mint& operator += (const mint& o) {if((v+=o.v)>=MOD) v-=MOD; return *this;}
	mint& operator -= (const mint& o) {if((v-=o.v)<0) v+=MOD; return *this;}
	mint& operator *= (const mint& o) {v=(ll)v*o.v%MOD; return *this;}

	friend mint operator + (mint a, const mint& b) {return a+=b;}
	friend mint operator - (mint a, const mint& b) {return a-=b;}
	friend mint operator * (mint a, const mint& b) {return a*=b;}
};

const int MN = 2e3+10;

int N, K;
char s[MN];
mint dp[2][MN][MN];

int main()
{
	scanf("%d%d %s", &N, &K, s);
	std::reverse(s, s+N);
	for(int i=0;i<N;++i) s[i] -= 'a';

	dp[0][0][0] = mint(1);
	for(int i=0;i<N;++i)
		for(int j=0;j<=K;++j)
		{
			dp[0][i+1][j] += dp[0][i][j] * mint(s[i]+1);
			dp[0][i+1][j] += dp[1][i][j] * mint(s[i]);

			if(j+i+1 <= K)
			{
				dp[1][i+1][j+i+1] += dp[0][i][j] * mint(25 - s[i]);
				dp[1][i+1][j+i+1] += dp[1][i][j] * mint(25 - s[i]);
			}
			for(int k=1;i+k < N && j+i*k<=K;++k)
			{
				dp[0][i+k+1][j+i*k] += dp[1][i][j] * mint(s[i+k]);
				if(j+i*k+(i+k+1) <= K)
					dp[1][i+k+1][j+i*k+(i+k+1)] += dp[1][i][j] * mint(25 - s[i+k]);
			}
		}

	mint ans = dp[0][N][K];
	for(int i=N;i>=0;--i)
		if(K >= i*(N-i))
			ans += dp[1][i][K - i * (N-i)];
	printf("%d\n", ans.v);
	return 0;
}