#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL dp[2][405][405][3];
LL val[405][405];
const int mod=998244353;
void solve(){
	int n;
	scanf("%d",&n);
	dp[0][0][0][0]=1;
	for(int i = 1;i<=n;i++){
		MEM(dp[i&1]);
		for(int j = 0;j<=i;j++){
			for(int k =0;k<=i;k++){
				int a=(i&1)^1;
				if(i==n/2+1||i==1){
					dp[i&1][j][k][0]=(dp[a][j][k][1]*24+dp[a][j][k][2]*24+dp[a][j][k][0]*24)%mod;
					if(j!=0)
					dp[i&1][j][k][1]=(dp[a][j-1][k][0]+dp[a][j-1][k][2]+dp[a][j-1][k][1])%mod;
					if(k!=0)
					dp[i&1][j][k][2]=(dp[a][j][k-1][0]+dp[a][j][k-1][1]+dp[a][j][k-1][2])%mod;
				}
				else{
					dp[i&1][j][k][0]=(dp[a][j][k][1]*24+dp[a][j][k][2]*24+dp[a][j][k][0]*23)%mod;
					if(j!=0)
					dp[i&1][j][k][1]=(dp[a][j-1][k][0]+dp[a][j-1][k][2])%mod;
					if(k!=0)
					dp[i&1][j][k][2]=(dp[a][j][k-1][0]+dp[a][j][k-1][1])%mod;
				}
				if(i==n){
					val[j][k]+=dp[i&1][j][k][0]+dp[i&1][j][k][1]+dp[i&1][j][k][2];
					val[j][k]%=mod;
				}
			//	printf("%d %d %d %d %d %d\n",i,j,k,dp[i&1][j][k][0],dp[i&1][j][k][1],dp[i&1][j][k][2]);
			}
		}
	}
	for(int j = n-1;j>=0;j--){
		for(int k = 0;k<=n;k++)val[j][k]=(val[j][k]+val[j+1][k])%mod;
	}
	for(int j=0;j<=n;j++){
		for(int k = n-1;k>=0;k--)val[j][k]=(val[j][k]+val[j][k+1])%mod;
	}
	int c[26];
	for(int j = 0;j<26;j++)scanf("%d",&c[j]);
	LL ans=val[0][0];
	//printf("%lld\n",ans);
	for(int j = 0;j<26;j++){
		ans-=val[c[j]+1][0];
	}
	for(int j = 0;j<26;j++){
		for(int k = j+1;k<26;k++){
			ans+=val[c[j]+1][c[k]+1];
		}
	}
	ans=(ans%mod+mod)%mod;
	printf("%lld\n",ans);
}
int main(){
    int t=1;00000;//00000;
  //  scanf("%d",&t);
    while(t--)solve();
}
/*
1 2 3 4 5 6 7
1 3 5 7 2 4 6
0 3 6 2 5 1 4
*/