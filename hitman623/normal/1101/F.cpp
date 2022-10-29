#include <bits/stdc++.h>

#define ll          long long
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
#define M 			250005
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,a[404];
int dp[404][404][404];
void solve(){
	cin>>n>>m;
	rep(i,1,n+1) cin>>a[i];
	rep(k,0,n+1){
		rep(i,1,n+1){
			rep(j,i,n+1){
				if(k==0) dp[i][j][k]=a[j]-a[i];
				else if(k>j-i-1) dp[i][j][k]=dp[i][j][k-1];
				else{
					int lo=i,hi=j-1;
					while(hi-lo>1){
						int mid=(lo+hi)/2;
						if(dp[i][mid][k-1]<=a[j]-a[mid]) lo=mid;
						else hi=mid;
					}
					dp[i][j][k]=min({max(dp[i][lo][k-1],a[j]-a[lo]),max(dp[i][hi+1][k-1],a[j]-a[hi+1]),max(dp[i][hi][k-1],a[j]-a[hi])});
				}
			}
		}
	}
	ll ans=0;
	rep(i,0,m){
		int s,f,c,r;
		cin>>s>>f>>c>>r;
		ans=max(ans,1LL*dp[s][f][r]*c);
	}
	cout<<ans<<endl;
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