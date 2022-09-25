#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,a[N],dp[N][512];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=0;i<=n;++i){
		memset(dp[i],0x3f,sizeof(dp[i]));		
	}
	dp[0][0]=-1;
	vector<int> ans;
	for(int i=1;i<=n;++i){
		for(int j=0;j<512;++j){
			dp[i][j]=min(dp[i][j],dp[i-1][j]);
			if(dp[i-1][j]<a[i]){
				dp[i][j^a[i]]=min(dp[i][j^a[i]],a[i]);
			}
		}
	}
	for(int i=0;i<512;++i){
		if(dp[n][i]<inf)ans.push_back(i);	
	}
	cout<<ans.size()<<'\n';
	for(auto x:ans){
		cout<<x<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	while(T--)Solve();
	return 0;
}