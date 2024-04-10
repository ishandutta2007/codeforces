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
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,a[13][2002],cost[2002][1<<12];
int dp[2002][1<<12];
void solve(){
	cin>>n>>m;
	rep(i,1,n+1){
		rep(j,1,m+1){
			cin>>a[i][j];
		}
	}
	memset(cost,0,sizeof cost);
	rep(i,1,m+1){
		rep(j,0,1<<n){
			rep(k,0,n){
				if((j>>k)&1){
					cost[i][j]+=a[k+1][i];
				}
			}
		}
		rep(j,0,1<<n){
			int mx=cost[i][j],cur=j;
			rep(k,0,n){
				cur=(cur>>1)+(cur%2)*(1<<(n-1));
				mx=max(mx,cost[i][cur]);
			}
			cost[i][j]=mx;
		}
	}
	memset(dp,-127,sizeof dp);
	dp[0][0]=0;
	rep(i,1,m+1){
		rep(mask,0,1<<n){
			dp[i][mask]=dp[i-1][mask];
			for(int sub=mask;sub>=0;sub=mask&(sub-1)){
				dp[i][mask]=max(dp[i][mask],dp[i-1][sub]+cost[i][sub^mask]);
				if(sub==0) break;
			}
		}
	}
	cout<<dp[m][(1<<n)-1]<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}