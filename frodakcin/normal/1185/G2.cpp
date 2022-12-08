#include <cstdio>
//#define NDEBUG
#include <cassert>
#include <vector>

using ll = long long;
const int MOD = 1e9+7;
struct mint
{
public:
	int v;
	mint(int _v=0):v(_v){}
	mint& operator += (mint o) {if((v+=o.v)>=MOD) v-=MOD;return *this;}
	mint& operator -= (mint o) {if((v-=o.v)<0) v+=MOD;return *this;}
	mint& operator *= (mint o) {v=(int)((ll)v*o.v%MOD); return *this;}

	friend mint operator + (mint a, mint b){return a+=b;}
	friend mint operator - (mint a, mint b){return a-=b;}
	friend mint operator * (mint a, mint b){return a*=b;}

	template<typename T> friend mint pow(mint b, T p) {mint r(1);for(;p;p>>=1,b*=b)if(p&1)r*=b; return r;}//T should only ever be int/ll/__int128_t
	explicit operator int() const {return v;}
	explicit operator bool() const {return (bool)v;}
};

const int MN = 51;
const int MT = 2.5e3+150;

int N, T;
std::vector<int> a[3];
mint F[MN], f, cnt[MN][MN][MN], dp[MN][MN][MT], dp2[MN][MT];
//cnt[cur][][]
//NOTE: cnt ACCOUNTS FOR ORDERING!!! DON'T REMULTIPLY BY FACTORIAL
int main()
{
	cnt[1][0][0] = mint(1);
	F[0]=mint(1);
	for(int i=0;i+1<MN;++i)
		F[i+1]=mint(i+1)*F[i];
	for(int s=1;s<MN;++s)
		for(int i=1;i<=s;++i)
			for(int j=0;i+j<=s;++j)
			{
				int k=s-i-j;
				cnt[j+1][k][i] += cnt[i][j][k];
				cnt[k+1][i][j] += cnt[i][j][k];
			}
	for(int i=0;i<MN;++i)
		for(int j=i;j<MN;++j)
			for(int k=i+(j>i);k<MN;++k)
				cnt[i][j][k] = cnt[j][k][i] = cnt[k][i][j] = (cnt[i][j][k] + cnt[j][k][i] + cnt[k][i][j])*F[i]*F[j]*F[k];
	scanf("%d%d", &N, &T);
	for(int i=0,t,g;i<N;++i)
	{
		scanf("%d%d", &t, &g);
		a[--g].push_back(t);
	}
	dp[0][0][0] = mint(1);
	for(int v:a[0])
		for(int i=a[0].size()-1;i>=0;--i)
			for(int j=0;j+v<=T;++j)
				dp[i+1][0][j+v] += dp[i][0][j];
	for(int v:a[1])
		for(int i=a[0].size();i>=0;--i)
			for(int j=a[1].size()-1;j>=0;--j)
				for(int k=0;k+v<=T;++k)
					dp[i][j+1][k+v] += dp[i][j][k];
	dp2[0][0] = mint(1);
	for(int v:a[2])
		for(int i=a[2].size()-1;i>=0;--i)
			for(int j=0;j+v<=T;++j)
				dp2[i+1][j+v] += dp2[i][j];
	for(int i=0;i<=a[0].size();++i)
		for(int j=0;j<=a[1].size();++j)
			for(int t=0;t<=T;++t)
				if(dp[i][j][t])
					for(int k=0;k<=a[2].size();++k)
						if(dp2[k][T-t])
							f += dp[i][j][t]*dp2[k][T-t]*cnt[i][j][k];
	printf("%d\n", f);
	return 0;
}