#include <cstdio>
#include <algorithm>
#include <queue>

using ll = long long;

const int MOD = 998244353;

struct mint
{
	public:
		int v;
		mint(int _v=0): v(_v)
		{
			if(v < -MOD || MOD <= v) v%=MOD;
			if(v<0) v+=MOD;
		}
		mint& operator += (const mint& o) {if((v+=o.v)>=MOD) v-=MOD; return *this;}
		mint& operator -= (const mint& o) {if((v-=o.v)<0) v+=MOD; return *this;}
		mint& operator *= (const mint& o) {v=(ll)v*o.v%MOD; return *this;}

		friend mint operator + (mint a, const mint &b) {return a+=b;}
		friend mint operator - (mint a, const mint &b) {return a-=b;}
		friend mint operator * (mint a, const mint &b) {return a*=b;}
};

int main()
{
	int N; scanf("%d", &N);

	int a[N]; for(int i=0;i<N;++i) scanf("%d", a+i);
	std::sort(a, a+N);

	int cnt[N];
	for(int i=0,j=0;i<N;++i)
	{
		for(;j<i && a[j]*2<=a[i];++j);
		cnt[i]=j;
	}

	mint dp[N+1][N+1], p[N];
	dp[0][0]=mint(1);
	for(int i=0,x=0;i<N;++i)
	{
		for(;x<=cnt[i];++x)
			for(int j=0;j<=x;++j)
				p[j] += dp[x][j];
		for(int j=0;j<=cnt[i];++j)
			dp[i+1][j+1] = dp[i+1][j]*mint(cnt[i]-j+1)+p[j];
	}

	printf("%d\n", dp[N][N]);

	return 0;
}