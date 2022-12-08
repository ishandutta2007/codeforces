#include <cstdio>
#include <cstring>

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

		friend mint operator + (mint a, const mint& b) {return a+=b;}
		friend mint operator - (mint a, const mint& b) {return a-=b;}
		friend mint operator * (mint a, const mint& b) {return a*=b;}

		template<typename T> friend mint pow(mint b, T p)
		{
			mint f(1);
			for(;p;p>>=1, b*=b)
				if(p&1)
					f*=b;
			return f;
		}
};

const int Z = 26;

int main()
{
	int N, c[Z];

	scanf("%d", &N);
	for(int i=0;i<Z;++i) scanf("%d", c+i);

	mint f(26*26);
	for(int i=2;i<N;++i) f*=mint(25);

	{ // 1 too many
		mint dp[N+1][4][N+1]; memset(dp, 0, sizeof dp);
		dp[0][0][0]=mint(1);
		for(int i=1;i<=N;++i)
			for(int j=0;j<N;++j)
				for(int k=0;k<2;++k) // other
				{
					//place:
					dp[i][k|2][j+1] += dp[i-1][k<<1][j];

					//do not place:
					dp[i][k][j] += dp[i-1][k<<1][j]*mint(24); // did not place
					if(i==1||i==2) dp[i][k][j] += dp[i-1][k<<1][j]; // no worry about duplicate for first one
					dp[i][k][j] += dp[i-1][1|k<<1][j]*mint(25); // had placed
				}
		for(int i=0;i<Z;++i)
			for(int j=c[i]+1;j<=N;++j) // can be done in psum in O(1), but no need. bottleneck is below
				for(int k=0;k<4;++k)
					f -= dp[N][k][j];
	}

	//printf("%d\n", f);

	{ //2 too many
		int X = N/2+5;
		mint dp[2][X][X][3][3]; memset(dp[0], 0, sizeof*dp);
		dp[0][0][0][0][0]=mint(1);
		for(int i=1;i<=N;++i)
		{
			memset(dp[1], 0, sizeof*dp);
			for(int c1=0;c1+1<X;++c1)
				for(int c2=0;c2+1<X;++c2)
					for(int k=0;k<3;++k)
					{
						//do not place:
						dp[1][c1][c2][k][0]+=dp[0][c1][c2][0][k]*mint(23);
						if(i==1||i==2) dp[1][c1][c2][k][0]+=dp[0][c1][c2][0][k]; // no worry about overlap for first number
						dp[1][c1][c2][k][0]+=dp[0][c1][c2][1][k]*mint(24);
						dp[1][c1][c2][k][0]+=dp[0][c1][c2][2][k]*mint(24);

						//place c1
						dp[1][c1+1][c2][k][1]+=dp[0][c1][c2][0][k]+dp[0][c1][c2][2][k];

						//place c2
						dp[1][c1][c2+1][k][2]+=dp[0][c1][c2][0][k]+dp[0][c1][c2][1][k];
					}
			memcpy(dp[0], dp[1], sizeof*dp);
		}
		mint p[X+1][X+1]; memset(p, 0, sizeof p);
		for(int i=0;i<X;++i)
			for(int j=0;j<X;++j)
				for(int k=0;k<9;++k)
					p[i][j] += dp[0][i][j][k%3][k/3];
		for(int i=X-1;i>=0;--i)
			for(int j=X-1;j>=0;--j)
				p[i][j] += p[i][j+1]+p[i+1][j]-p[i+1][j+1];

		for(int i=0;i<Z;++i)
			for(int j=i+1;j<Z;++j)
				if(c[i]<X&&c[j]<X)
					f += p[c[i]+1][c[j]+1];
	}

	printf("%d\n", f);
	return 0;
}