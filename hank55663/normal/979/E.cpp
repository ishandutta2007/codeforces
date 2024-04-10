#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 100005
LL dp[60][60][60][2];//num  0 1 
int C[60][60];
int mod=1e9+7;
void build(){
	for(int i=0;i<60;i++){
		C[i][0]=C[i][i]=1;
	}
	for(int i = 1;i<60;i++){
		for(int j=1;j<i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
}
int main(){
	build();
	int n,p;
	scanf("%d %d",&n,&p);
	int c[55];
	for(int i=0;i<n;i++)
		scanf("%d",&c[i]);
	dp[0][0][0][0]=1;
	for(int i=0;i<n;i++){
		if(c[i]==0||c[i]==-1){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
				//	if(dp[i][j][k][0]||dp[i][j][k][1])
					//printf("%d %d %d %lld %lld\n",i,j,k,dp[i][j][k][0],dp[i][j][k][1]);
					for(int l=0;l<=k;l++){
						if(l%2==0){
							dp[i+1][j+1][k][1]+=dp[i][j][k][0]*C[k][l]%mod*((1ll<<(i-k))%mod);
							dp[i+1][j+1][k][0]+=dp[i][j][k][1]*C[k][l]%mod*((1ll<<(i-k))%mod);
							dp[i+1][j+1][k][1]%=mod;
							dp[i+1][j+1][k][0]%=mod;
						}
						else{
							dp[i+1][j][k][0]+=dp[i][j][k][0]*C[k][l]%mod*((1ll<<(i-k))%mod);
							dp[i+1][j][k][1]+=dp[i][j][k][1]*C[k][l]%mod*((1ll<<(i-k))%mod);
							dp[i+1][j][k][1]%=mod;
							dp[i+1][j][k][0]%=mod;
						}

					}
				}
			}
		}
		if(c[i]==1||c[i]==-1){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
				//	if((c[i]==1)&&(dp[i][j][k][0]||dp[i][j][k][1]))
				//	printf("%d %d %d %lld %lld\n",i,j,k,dp[i][j][k][0],dp[i][j][k][1]);
					for(int l=0;l<=j;l++){
						if(l%2==0){
							dp[i+1][j][k+1][1]+=dp[i][j][k][0]*C[j][l]%mod*((1ll<<(i-j))%mod);
							dp[i+1][j][k+1][0]+=dp[i][j][k][1]*C[j][l]%mod*((1ll<<(i-j))%mod);
							dp[i+1][j][k+1][1]%=mod;
							dp[i+1][j][k+1][0]%=mod;
						}
						else{
							dp[i+1][j][k][0]+=dp[i][j][k][0]*C[j][l]%mod*((1ll<<(i-j))%mod);
							dp[i+1][j][k][1]+=dp[i][j][k][1]*C[j][l]%mod*((1ll<<(i-j))%mod);
							dp[i+1][j][k][1]%=mod;
							dp[i+1][j][k][0]%=mod;
						}
					}
				}
			}
		}
	}
	LL ans=0;
	for(int j=0;j<=n;j++){
		for(int k =0;k<=n;k++){
			//if(dp[n][j][k][0]||dp[n][j][k][1])
		//	printf("%d %d %d %lld %lld\n",n,j,k,dp[n][j][k][0],dp[n][j][k][1]);
			ans+=dp[n][j][k][p];
		}
	}
	printf("%lld\n",ans%mod);
}