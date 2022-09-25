#include<bits/stdc++.h>
using namespace std;
#define N 55
#define M 2505
typedef long long ll;
const int mod=1e9+7;
int n,T,ans;
vector<int> pro[3];
int dp[3][N][M],g[N][N][N][3],cnt[3],sum[3],fac[N],s[N][N][N];
inline int Plus(int x,int y){
	return x+y>=mod?x+y-mod:x+y;
}
inline void update(int &x,int y){
	x=Plus(x,y);	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>T;
	for(int i=0;i<3;++i){
		dp[i][0][0]=1;
	}
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
		int x,t;
		cin>>x>>t;
		--t;
		++cnt[t],sum[t]+=x;
		for(int j=cnt[t];j>=1;--j){
			for(int k=sum[t];k>=x;--k){
				update(dp[t][j][k],dp[t][j-1][k-x]);		
			}
		}
	}
	g[1][0][0][0]=g[0][1][0][1]=g[0][0][1][2]=1;
	for(int i=0;i<=cnt[0];++i){
		for(int j=0;j<=cnt[1];++j){
			for(int k=0;k<=cnt[2];++k){
				update(g[i+1][j][k][0],Plus(g[i][j][k][1],g[i][j][k][2]));
				update(g[i][j+1][k][1],Plus(g[i][j][k][0],g[i][j][k][2]));
				update(g[i][j][k+1][2],Plus(g[i][j][k][0],g[i][j][k][1]));
				s[i][j][k]=1LL*fac[i]*fac[j]%mod*fac[k]%mod*Plus(Plus(g[i][j][k][0],g[i][j][k][1]),g[i][j][k][2])%mod;
			}
		}
	}
	for(int i1=0;i1<=cnt[0];++i1){
		for(int j1=0;j1<=sum[0];++j1){
			if(!dp[0][i1][j1])continue;
			int w1=dp[0][i1][j1];
			for(int i2=0;i2<=cnt[1];++i2){
				for(int j2=0;j2<=min(T-j1,sum[1]);++j2){
					if(!dp[1][i2][j2])continue;
					int w2=dp[1][i2][j2];
					for(int i3=0;i3<=cnt[2];++i3){
						ans=(ans+1LL*s[i1][i2][i3]*w1%mod*w2%mod*dp[2][i3][T-j1-j2])%mod;
					}
				}
			}		
		}
	}
	cout<<ans<<'\n';
	return 0;
}