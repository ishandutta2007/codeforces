#include<iostream>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
int n,k;
ll a[51];
ll sum[51];
bool dp[63][51][51];
int main(){
	cin >> n >> k;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		sum[i]=sum[i-1]+a[i];
	}
	ll ans=0;
	for(int cur=62; cur>=0 ;cur--){
		ans|=(1LL<<cur);
		dp[cur][0][0]=true;
		for(int i=1; i<=n ;i++){
			for(int j=1; j<=k ;j++){
				for(int prv=0; prv<i ;prv++){
					if(((sum[i]-sum[prv])&ans)!=ans) continue;
					dp[cur][i][j]|=dp[cur][prv][j-1];
				}
			}
		}
		if(!dp[cur][n][k]) ans^=(1LL<<cur);
	}
	cout << ans << endl;
}