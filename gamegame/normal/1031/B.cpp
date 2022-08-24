#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,m;
int a[1000001],b[100001];
int dp[100001][4];
int main(){
	ios::sync_with_stdio(false);
	//int t;cin >> t;while(t--) solve();
	cin >> n;
	for(int i=1; i<n ;i++) cin >> a[i];
	for(int i=1; i<n ;i++) cin >> b[i];
	dp[1][0]=dp[1][1]=dp[1][2]=dp[1][3]=1;
	for(int i=2; i<=n ;i++){
		for(int j=0; j<4 ;j++){
			for(int k=0; k<4 ;k++){
				if((j|k)!=a[i-1]) continue;
				if((j&k)!=b[i-1]) continue;
				dp[i][k]|=dp[i-1][j];
			}
		}
	}
	int x=0;
	for(int i=1; i<4 ;i++) if(dp[n][i]) x=i;
	if(!dp[n][x]) return cout << "NO\n",0;
	vector<int>ans;
	ans.push_back(x);
	for(int i=n-1; i>=1 ;i--){
		for(int j=0; j<4 ;j++){
			int k=x;
		//	cout << j << ' ' << k << endl;
			if((j|k)!=a[i]) continue;
			if((j&k)!=b[i]) continue;
			//cout << "hih" << endl;
			if(!dp[i][j]) continue;
		//	cout << dp[i][j] << endl;
			ans.push_back(j);
			x=j;
			break;
		}
		//cout << ans.size() << endl;
	}
	cout << "YES\n";
	reverse(ans.begin(),ans.end());
	for(auto cur:ans) cout << cur << ' ';
}