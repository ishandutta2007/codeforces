#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
typedef pair<ll,ll> pll;
const int N=2e6+1;
int n,m;
char c[2003][2003];
int dp2[2003][2003];
int dp3[2003][2003];
int dp[2003][2003];
bool ingrid(int x,int y){
	return x>0 && x<=n && y>0 && y<=m;
}
void solve(){
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> c[i][j];
		}
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			dp2[i][j]=1;
			if(c[i][j]==c[i-1][j-1]) dp2[i][j]+=dp2[i-1][j-1];
			dp3[i][j]=1;
			if(c[i][j]==c[i-1][j+1]) dp3[i][j]+=dp3[i-1][j+1];
		}
	}
	ll ans=0;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			dp[i][j]=dp[i-1][j]+1;
			while(dp[i][j]>1){
				int r=dp[i][j];
				bool ok=true;
				if(!ingrid(i+r-1,j)) ok=false;
				else if(dp2[i+r-1][j]<r || dp3[i+r-1][j]<r) ok=false;
				else if(dp2[i+r-2][j]<r-1 || dp3[i+r-2][j]<r-1) ok=false;
				else if(c[i-1][j]!=c[i+r-1][j] || c[i-1][j]!=c[i+r-2][j]) ok=false;
				//cout << i << ' ' << j << ' ' << ok << endl;
				if(!ok) dp[i][j]--;
				else break;
			}
			ans+=dp[i][j];
		}
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	//int t;cin >> t;while(t--) 
	solve();
}