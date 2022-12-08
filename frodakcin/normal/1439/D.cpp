#include <cstdio>

using ll = long long;

const int MN = 5e2+10;
const int MM = 5e2+10;
const int MV = 1e3+10;

int P;

struct mint
{
	public:
		int v;
		mint(int _v=0): v(_v) {}
		operator int() const {return v;}

		mint& operator += (const mint& o) {if((v+=o.v)>=P) v-=P; return *this;}
		mint& operator -= (const mint& o) {if((v-=o.v)<0) v+=P; return *this;}
		mint& operator *= (const mint& o) {v=(ll)v*o.v%P; return *this;}

		friend mint operator + (mint a, const mint& b) {return a+=b;}
		friend mint operator - (mint a, const mint& b) {return a-=b;}
		friend mint operator * (mint a, const mint& b) {return a*=b;}
};

int N, M;
mint ch[MV][MV], dp1[MN], cnt1[MN], dp[MN][MM], cnt[MN][MM];

void pcp()
{
	for(int i=0;i<MV;++i)
	{
		ch[i][0]=ch[i][i]=mint(1);
		for(int j=1;j<i;++j)
			ch[i][j]=ch[i-1][j-1]+ch[i-1][j];
	}
}

mint sm2(int v) {return mint(v*(v+1)/2);}

int main()
{
	scanf("%d%d%d", &N, &M, &P); ++N;
	pcp();
	dp1[0]=mint(1);
	for(int i=1;i<=N;++i)
		for(int j=0;j<i;++j)
		{
			mint ways=dp1[j]*dp1[i-1-j]*ch[i-1][j];
			dp1[i]+=ways*mint(i+1);
			cnt1[i]+=mint(i+1)*(cnt1[j]*dp1[i-1-j]+cnt1[i-1-j]*dp1[j])*ch[i-1][j]+ways*(sm2(j)+sm2(i-j-1));
		}

	dp[0][0]=mint(1);
	for(int i=1;i<=N;++i)
		for(int k=0;k<i;++k)
		{
			for(int j=0;j<=k;++j)
			{
				dp[i][k] += dp1[j]*dp[i-1-j][k-j]*ch[k][j];
				cnt[i][k] += ch[k][j]*(cnt[i-1-j][k-j]*dp1[j] + cnt1[j]*dp[i-1-j][k-j]);
			}
			//printf("dp[%d][%d] = %d\n", i, k, dp[i][k]);
			//printf("cnt[%d][%d] = %d\n", i, k, cnt[i][k]);
		}

	printf("%d\n", cnt[N][M]);
	return 0;
}