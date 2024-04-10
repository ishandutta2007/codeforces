#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
const int MV = 1<<3*2;
const int MOD = 998244353;
const int MN = 1e3 + 100;

bool f[3][3];
struct ST
{
	ll v[1<<3*2][1<<3*2];
	ST(void)
	{
		for(int i = 0;i < 1<<3*2;i++)
			for(int j = 0;j < 1<<3*2;j++)
				v[i][j] = 0;
	}
	ST(ST *a, ST *b)
	{
		for(int i = 0;i < MV;i++)
			for(int j = 0;j < MV;j++)
			{
				v[i][j] = 0;
				for(int k = 0;k < MV;k++)
					v[i][j] += a->v[i][k]*b->v[k][j]%MOD;
				v[i][j]%=MOD;
			}
	}
};
ST jmp[33];
ST jc[3];
int mex[3][MV];//mex of color i, given last 3 pos's mex's

bool app[6];
void mad(int x) {app[x] = 1;}
int gmex(void)
{
	int r;
	for(int i = 4;i>=0;i--)
		if(!app[i])
			r = i;
		else
			app[i] = 0;
	return r;
}

struct FX
{
	int x, c;
	bool operator < ( const FX& o) const {return x < o.x;}
};
int N, M;
int a[MN];
vector<FX> cut[MN];

ll dp[2][4];
ll tmp[2][64];
ll tv[4];

int main(void)
{
	scanf("%d", &N);
	for(int i = 0;i < N;i++)
		scanf("%d", a+i);
	scanf("%d",&M);
	for(int i = 0, x, y, c;i < M;i++)
	{
		scanf("%d%d%d", &x, &y, &c);
		cut[--x].push_back({y,--c});
	}
	for(int i = 0;i < N;i++)
		sort(cut[i].begin(), cut[i].end());
	for(int i = 0;i < 3;i++)
		for(int j = 0, k;j < 3;j++)
			scanf("%d", &k), f[i][j]=k;

	for(int i = 0;i < 3;i++)
		for(int j = 0;j < MV;j++)
		{
			for(int k = 0;k < 3;k++)
				if(f[i][k])
					mad(j>>k*2&3);
			mex[i][j] = gmex();
			++jmp[0].v[j][63&j<<2|mex[i][j]];
			++jc[i].v[j][63&j<<2|mex[i][j]];
		}
	for(int i = 0;i < 32;i++)
		jmp[i+1] = ST(jmp+i, jmp+i);

	bool c = 0, d = 0;
	for(int i = 1;i <= 3;i++)
		dp[c][i] = 0LL;
	dp[c][0] = 1LL;
	for(int i = 0, n;i < N;++i, c=!c)
	{
		auto mmul = [&](ST * a)
		{
			for(int j = 0;j < 64;++j)
			{
				tmp[!d][j] = 0LL;
				for(int k = 0;k < 64;++k)
					tmp[!d][j] = (tmp[!d][j] + tmp[d][k]*a->v[k][j])%MOD;
			}
			d = !d;
		};
		auto jmp1 = [&](int z)
		{
			for(int i = 0;z;++i,z>>=1)
				if(z&1)
					mmul(jmp+i);
		};
		n = 1;
		for(int j = 0;j < 63;j++)
			tmp[d][j] = 0LL;
		tmp[d][63] = 1LL;
		for(FX &z : cut[i])
		{
			jmp1(z.x-n);
			mmul(jc+z.c);
			n = z.x+1;
		}
		if(n <= a[i])
			jmp1(a[i]-n+1);

		for(int j = 0;j < 4;j++)
			dp[!c][j] = 0LL, tv[j] = 0LL;
		for(int j = 0;j < 64;j++)
			tv[j&3] = (tv[j&3] + tmp[d][j])%MOD;
		for(int j = 0;j < 4;j++)
			for(int k = 0;k < 4;k++)
				dp[!c][j^k] = (dp[!c][j^k]+dp[c][j]*tv[k])%MOD;
	}
	printf("%lld\n", dp[c][0]);
	return 0;
}