#include <iostream>
#include <cstdio>

#include <cstring>

using namespace std;

using ll = long long;
const int MOD = 998244353;
const ll MOD2 = static_cast<ll>(MOD)*MOD;
const int MN = 3e3 + 100;
const int CUT = 11;
int N, C, M;
int a[MN];

ll pw(ll b, ll p)
{
	ll r = 1LL;
	for(;p;p>>=1, b=b*b%MOD) if(p&1) r = r*b%MOD;
	return r;
}

ll v[MN][1<<CUT];
ll t[MN];
ll p2[MN][2];
int c[MN];
ll f[MN];
ll dp[MN][MN];
ll T;
void A(void)
{
	dp[0][0] = 1LL;
	for(int i = 1;i <= N;i++)
	{
		T = 1LL;
		int z = 0;
		for(int j = i;j > 0;j--)
			if(c[0]==C)
				t[j] = (a[j]!=a[i]?p2[c[a[j]]+1][0]*p2[c[a[j]]][1]%MOD:1)*t[j+1]%MOD, c[a[j]]++;
			else
			{
				t[j] = 0LL;
				if(!c[a[j]]++)
				{
					if(++c[0]==C)
						t[j] = T, z = j;
				}
				else if(a[j] != a[i])
					T = T*p2[c[a[j]]][0]%MOD*p2[c[a[j]]-1][1]%MOD;
			}
		for(int j = 0;j <= C;j++)
			c[j] = 0;
		for(int j = min(M, i/C);j > 0;j--)
		{
			for(int k = (j-1)*C;k <= z;k++)
			{
				dp[i][j] += dp[k][j-1]*t[k+1];
				if(dp[i][j] >= MOD2) dp[i][j] -= MOD2;
			}
			dp[i][j] %= MOD;
		}
	}
}
void B(void)
{
	dp[0][0] = 1LL;
	v[0][0] = 1LL;
	for(int i = 1;i <= N;i++)
	{
		int to = min(M-1, i/C);
		for(int j = 1;j <= M;j++)
			dp[i][j] = v[j-1][(1<<C)-1^1<<a[i]-1];
		for(int j = 0, x;j <= to;j++)
		{
			x = 1<<a[i]-1;
			for(int k = x;k < 1<<C;k=k+1|x)
				v[j][k] = ((v[j][k]<<1)+v[j][k^x])%MOD;
			v[j][0]=(v[j][0]+dp[i][j])%MOD;
		}
	}
}
int main(void)
{
	scanf("%d%d", &N, &C), M = N/C;
	for(int i = 1;i <= N;i++)
		scanf("%d", a + i);
	p2[0][0] = p2[0][1] = 0;
	for(int i = 1;i <= N;i++)
		p2[i][0] = pw(2, i)-1, p2[i][1] = pw(p2[i][0], MOD-2);
	if(C > CUT) A();
	else B();
	for(int i = 1;i <= N;i++)
		for(int j = 1;j <= M;j++)
			f[j]=(f[j]+dp[i][j]*(p2[N-i][0]+1))%MOD;
	f[0] = pw(2, N)-1;
	for(int i = 0;i <= N;i++)
		printf("%lld%c", (f[i]-f[i+1]+MOD)%MOD, " \n"[i==N]);
	return 0;
}