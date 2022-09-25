#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200020
int n,k,a[N],c[N];
const int mod=998244353;
int Solve(int n){
	static int dp[N][2];
	memset(dp,0,sizeof(dp));
	int ans=1;
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		cerr<<" "<<c[i]<<endl;
		if(~c[i]){
			ans=1LL*ans*dp[i-1][0]%mod;
			for(int j=i+1;;++j){
				if(j>n||~c[j]){
					if(j<=n&&c[i]==c[j])dp[i][1]=1;
					else dp[i][0]=1;
					break;
				}
			}
		}
		else if(i==1){
			dp[i][1]=1,dp[i][0]=k-1;	
		}
		else{
			dp[i][1]=dp[i-1][0];
			dp[i][0]=(1LL*dp[i-1][0]*(k-2)+1LL*dp[i-1][1]*(k-1))%mod;
		}
	}
	ans=1LL*ans*(dp[n][0]+dp[n][1])%mod;
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;i+=2){
		c[i/2+1]=a[i];
	}
	int ans=Solve((n+1)/2);
	for(int i=2;i<=n;i+=2){
		c[i/2]=a[i];
	}
	ans=1LL*ans*Solve(n/2)%mod;
	cout<<ans<<'\n';
	return 0;
}