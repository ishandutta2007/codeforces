#include <cstdio>

using ll = long long;

const int MN = 4e3;
const int MOD = 998244353;

ll pw(ll b, int p)
{
	ll r = 1LL;
	for(;p;p>>=1,b=b*b%MOD) if(p&1) r=r*b%MOD;
	return r;
}
ll C[MN][MN], F[2][MN], I[MN];
void pcpm(int S = MN-1)
{
	I[1] = 1LL;
	for(int i = 2;i <= S;++i)
		I[i] = MOD-I[MOD%i]*(MOD/i)%MOD;
	F[0][0] = F[1][0] = 1LL;
	for(int i = 1;i <= S;++i)
		F[0][i] = F[0][i-1]*i%MOD, F[1][i] = F[1][i-1]*I[i]%MOD;
	C[0][0] = 1LL;
	for(int i = 1;i <= S;++i)
	{
		C[i][0] = C[i][i] = 1;
		for(int j = 1;j < i;++j)
			C[i][j] = (C[i-1][j]+C[i-1][j-1])%MOD;
	}
}

int H[2], N;
int dp[2][MN][MN/2], u[2][MN], v[2];
ll f;

int main(void)
{
	pcpm();
	scanf("%d%d%d", H, H+1, &N);
	v[0] = v[1] = N;
	for(int i = 0, w, x, y, z;i < N;++i)
	{
		scanf("%d%d%d%d", &w, &x, &y, &z);
		u[0][w] = u[0][y] = u[1][x] = u[1][z] = 1;
		++v[w==y];
	}
	for(int i = 0;i < 2;++i)
	{
		dp[i][0][0] = dp[i][1][0] = 1;
		for(int j = 2;j <= H[i];++j)
		{
			dp[i][j][0] = 1;
			for(int k = 1;k*2 <= j;++k)
				if(!u[i][j]&&!u[i][j-1])
					dp[i][j][k] = (dp[i][j-1][k]+dp[i][j-2][k-1])%MOD;
				else
					dp[i][j][k] = dp[i][j-1][k];
		}
	}
	for(int r = 0;r <= H[1];++r)
		for(int c = 0;c <= H[0];++c)
			if(H[0]>=r*2+c+v[0] && H[1]>=c*2+r+v[1])
				f = (f+dp[0][H[0]][r]*C[H[0]-v[0]-r*2][c]%MOD*dp[1][H[1]][c]%MOD*C[H[1]-v[1]-c*2][r]%MOD*F[0][r]%MOD*F[0][c])%MOD;
	printf("%lld\n", f);
	return 0;
}