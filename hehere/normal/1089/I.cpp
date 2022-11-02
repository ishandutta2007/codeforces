/* --- author: dxm --- */
#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;

#define INF 1e9
#define Inf 1e18
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;

void qread(int &x){
	int neg=1;x=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')neg=-1;c=getchar();}
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	x*=neg;
}

const int maxn=405;
int test,n,mod;
int dp[maxn][maxn*2],fac[maxn];

int quickpow(int x,int pow){
	int res=1;
	for(;pow;pow>>=1){
		if(pow&1)res=1LL*res*x%mod;
		x=1LL*x*x%mod; 
	}
	return res;
}

void work(){
	REP(i,400)dp[i][i+400]=1;
	REP(i,400){
		int inv=quickpow(dp[i][i],mod-2);
		for(int j=i+1;j<=2*400;j++)dp[i][j]=1LL*dp[i][j]*inv%mod;
		dp[i][i]=1;
		for(int j=i+1;j<=400;j++){
			for(int k=i+1;k<=2*400;k++)dp[j][k]=(dp[j][k]-1LL*dp[j][i]*dp[i][k]%mod+mod)%mod;
			dp[j][i]=0;
		}
	}
}

int main(){
#ifdef FILE
	freopen("FILE.in","r",stdin);
	freopen("FILE.out","w",stdout);
#endif
	scanf("%d%d",&test,&mod);
	fac[0]=1;
	REP(i,400)fac[i]=1LL*fac[i-1]*i%mod;
	REP(i,400){
		dp[i][1]=fac[i];
		for(int k=2;k<=i;k++){
			for(int m=0;m<=i-k;m++)dp[i][k]=(dp[i][k]+1LL*fac[m+1]*dp[i-m-1][k-1]%mod)%mod;
		}
	}
	work();
	while(test--){
		scanf("%d",&n);
		if(n==2){
			puts("2");
			continue;
		}
		int ans=((mod-dp[n][401])%mod+((n&1)?2:-2)+mod)%mod;
		printf("%d\n",ans);
	}
#ifdef TIME
	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
#endif
	return 0;
}

/*
Input:
-----------------
Output:
*/