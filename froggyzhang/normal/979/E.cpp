#include<bits/stdc++.h>
using namespace std;
#define N 55
const int mod=1e9+7;
typedef long long ll;
int pw2[N],C[N][N],n,c[N],zz;
int dp[N][N][N][N];
void init(int n){
	pw2[0]=C[0][0]=1;
	for(int i=1;i<=n;++i){
		C[i][0]=1;
		(pw2[i]=pw2[i-1]<<1)%=mod;
		for(int j=1;j<=i;++j){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>zz;
	for(int i=1;i<=n;++i){
		cin>>c[i];	
	}
	init(n);
	dp[0][0][0][0]=1;
	#define update(x,y) x=(x+y)%mod
	for(int i=1;i<=n;++i){
		for(int j=0;j<i;++j){
			int k=i-1-j;
			for(int x=0;x<=j;++x){
				for(int y=0;y<=k;++y){
					int w=dp[i-1][j][x][y];
					if(!w)continue;
					//black
					if(c[i]!=1){
						update(dp[i][j+1][x][y],1LL*w*pw2[j]%mod*pw2[k-y]%mod*(!y?0:pw2[y-1]));
						update(dp[i][j+1][x+1][y],1LL*w*pw2[j]%mod*pw2[k-y]%mod*(!y?1:pw2[y-1]));
					}
					//white
					if(c[i]!=0){
						update(dp[i][j][x][y],1LL*w*pw2[k]%mod*pw2[j-x]%mod*(!x?0:pw2[x-1]));
						update(dp[i][j][x][y+1],1LL*w*pw2[k]%mod*pw2[j-x]%mod*(!x?1:pw2[x-1]));
					}
				}
			}	
		}	
	}
	int ans=0;
	for(int j=0;j<=n;++j){
		for(int x=0;x<=j;++x){
			for(int y=0;y<=n-j;++y){
				if(((x^y)&1)==zz)update(ans,dp[n][j][x][y]);
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}