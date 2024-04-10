#include <cstdio>

using ll = long long;
const int MOD = 1e9+7;
struct mint
{
public:
	int v;
	mint(int _v=0):v(_v){}
	operator int() const {return v;}
	mint& operator += (mint o) {if((v+=o.v)>=MOD) v-=MOD; return *this;}
	mint& operator -= (mint o) {if((v-=o.v)<0) v+=MOD; return *this;}
	mint& operator *= (mint o) {v=(int)((ll)v*o.v%MOD); return *this;}

	friend mint operator + (mint a, mint b) {return a+=b;}
	friend mint operator - (mint a, mint b) {return a-=b;}
	friend mint operator * (mint a, mint b) {return a*=b;}
};

const int MV=2e5+2000, MV2=MV*2+10000;
int a,b,k,t;
mint dp[MV2], ans, p[MV2+1], pi[MV2+1];
int main(void)
{
	scanf("%d%d%d%d", &a, &b, &k, &t);
	k*=2;
	dp[a-b+MV]=mint(1);
	for(;t--;)
	{
		for(int i=0;i<MV2;++i)
		{
			p[i+1]=p[i]+dp[i];
			pi[i+1]=pi[i]+dp[i]*mint(i);
		}
		for(int i=k+1;i+k<MV2;++i)
		{
			dp[i] = pi[i]-pi[i-k]-(p[i]-p[i-k])*mint(i-k-1);//[-k, 0)
			dp[i]+= (p[i+k+1]-p[i])*mint(i+k+1)-(pi[i+k+1]-pi[i]);//[0, k]
			//if(dp[i]) printf("%d: %d\n", i, dp[i]);
		}
	}
	for(int i=MV+1;i+k<MV2;++i)
		ans+=dp[i];
	printf("%d\n", ans);
	return 0;
}