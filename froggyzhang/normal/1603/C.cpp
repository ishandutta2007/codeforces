#include<bits/stdc++.h>
using namespace std;
#define N 100030
const int mod=998244353;
typedef long long ll;
int n,a[N];
vector<pair<int,int> > dp[2];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];	
	}
	dp[0].clear(),dp[1].clear();
	dp[0].emplace_back(0,0);
	int ans=0;
	for(int i=1;i<=n;++i){
		int j=0;
		dp[i&1].clear();
		for(int l=1,r=1;l<=a[i]-1;l=r+1){
			r=min((a[i]-1)/((a[i]-1)/l),a[i]/(a[i]/l));
			while(dp[i&1^1][j].first>=a[i]/l){
				++j;
			}
			dp[i&1].emplace_back((a[i]-1)/l,(1LL*(l-1)*i+dp[i&1^1][j].second)%mod);
		}
		dp[i&1].emplace_back(0,(1LL*(a[i]-1)*i+dp[i&1^1].back().second)%mod);
		ans=(ans+dp[i&1][0].second)%mod;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}