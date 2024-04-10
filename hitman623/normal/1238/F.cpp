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
int n,dp[300005],ans,deg[300005];
vi a[300005];
void dfs(int node,int par){
	dp[node]=1;
	vi v;
	for(auto i:a[node]){
		if(i!=par){
			dfs(i,node);
			dp[node]=max(dp[node],dp[i]+deg[node]-(par!=-1));
			v.pb(dp[i]);
		}
	}
	ans=max(ans,dp[node]);
	sort(all(v));
	if(sz(v)>1) ans=max(ans,v.back()+v[sz(v)-2]+deg[node]-1);
}
void solve(){
	ans=0;
    cin>>n;
    rep(i,1,n+1){
    	dp[i]=0;
    	a[i].clear();
    	deg[i]=0;
    }
    rep(i,0,n-1){
    	int x,y;
    	cin>>x>>y;
    	a[x].pb(y);
    	a[y].pb(x);
    	deg[x]++;
    	deg[y]++;
    }
    dfs(1,-1);
    cout<<ans<<endl;
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