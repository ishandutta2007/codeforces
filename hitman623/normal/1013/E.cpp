#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,a[5005],dp[5005][5005][2];
void solve(){
	cin>>n;
	rep(i,1,n+1){
		cin>>a[i];
	}
	a[n+1]=a[n]-1;
	a[0]=a[1]-1;
	memset(dp,1,sizeof dp);
	dp[0][0][0]=0;
	rep(i,1,n+1){
		rep(j,0,n+1){
			if(j==0) dp[i][j][0]=0;
			else{
				if(i==1){
					if(j==1) dp[i][j][1]=max(0LL,a[2]-a[1]+1);
				}
				else{
					dp[i][j][0]=min(dp[i-1][j][0],dp[i-1][j][1]);
					dp[i][j][1]=dp[i-2][j-1][0]+max(0LL,a[i-1]-a[i]+1)+max(0LL,a[i+1]-a[i]+1);
					int cur=min(a[i-2]-1,a[i-1]);
					dp[i][j][1]=min(dp[i][j][1],dp[i-2][j-1][1]+max(0LL,cur-a[i]+1)+max(0LL,a[i+1]-a[i]+1));
				}
			}
		}
	}
	rep(i,1,(n+1)/2+1) cout<<min(dp[n][i][0],dp[n][i][1])<<" ";
	cout<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
    // cin>>t;
	while(t--){
		solve();
	}
	return 0;
}