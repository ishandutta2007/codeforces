#include<bits/stdc++.h>
using namespace std;
#define N 5005
typedef long long ll;
const int mod=998244353;
int n,cnt[N],dp[N][N/2][2],C[N][N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i)cnt[i]=0;
	for(int i=1,x;i<=n;++i){
		cin>>x;
		++cnt[n-x+1];
	}
	dp[0][0][1]=1;
	for(int i=1,now=0;i<=n;++i){
		if(!cnt[i]){
			memcpy(dp[i],dp[i-1],sizeof(dp[i]));
		}
		else{
			memset(dp[i],0,sizeof(dp[i]));
			for(int j=0;j<=n/2;++j){
				if(!dp[i-1][j][0]&&!dp[i-1][j][1])continue;
				int w0=dp[i-1][j][0],w1=dp[i-1][j][1];
				if(cnt[i]<=2*j-now){
					dp[i][j][1]=(dp[i][j][1]+1LL*C[2*j-now][cnt[i]]*w1)%mod;
					dp[i][j][1]=(dp[i][j][1]+1LL*C[2*j-now-1][cnt[i]-1]*w0)%mod;
				}
				if(cnt[i]<2*j-now){
					dp[i][j][0]=(dp[i][j][0]+1LL*C[2*j-now-1][cnt[i]]*w0)%mod;
				}
				if(j<n/2){
					if(cnt[i]-1<=2*j-now-1){
						dp[i][j+1][0]=(dp[i][j+1][0]+1LL*C[2*j-now-1][cnt[i]-1]*w0)%mod;
					}
					if(!j&&cnt[i]-1<=2*j-now){
						dp[i][j+1][0]=(dp[i][j+1][0]+1LL*C[2*j-now][cnt[i]-1]*w1)%mod;
					}
				}
			}
			now+=cnt[i];
		}
	}
	cout<<dp[n][n/2][1]<<'\n';
}
void init(int n){
	C[0][0]=1;
	for(int i=1;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(5000);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}