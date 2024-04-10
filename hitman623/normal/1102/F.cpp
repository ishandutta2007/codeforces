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
int n,m,a[20][10004];
int dp[1<<16][16][16];
int cost[20][20]={0};
int last[20][20]={0};
void pre(){
	rep(i,0,n){
		rep(j,0,n){
			cost[i][j]=last[i][j]=hell;
			rep(k,1,m+1) cost[i][j]=min(cost[i][j],abs(a[i][k]-a[j][k]));
			rep(k,2,m+1) last[i][j]=min(last[i][j],abs(a[i][k]-a[j][k-1]));
		}
	}
}
int sol(int mask,int la,int fi){
	if(mask==((1<<n)-1)) return last[fi][la];
	int &ans=dp[mask][la][fi];
	if(ans!=-1) return ans;
	ans=0;
	rep(i,0,n){
		if((mask>>i)&1);
		else ans=max(ans,min(cost[la][i],sol(mask^(1<<i),i,fi)));
	}
	return ans;
}
void solve(){
	cin>>n>>m;
	rep(i,0,n){
		rep(j,1,m+1){
			cin>>a[i][j];
		}
	}
	pre();
	memset(dp,-1,sizeof dp);
	int ans=0;
	rep(i,0,n) ans=max(ans,sol(1<<i,i,i));
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