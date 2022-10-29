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
int n,k,ans,cnt,vis[100005];
vi a[100005];
void dfs(int node){
	vis[node]=1;
	cnt++;
	for(auto i:a[node]){
		if(vis[i]==0){
			dfs(i);
		}
	}
}
void solve(){
    cin>>n>>k;
    rep(i,0,k){
    	int x,y;
    	cin>>x>>y;
    	a[x].pb(y);
    	a[y].pb(x);
    }
    rep(i,1,n+1){
    	if(vis[i]==0){
    		cnt=0;
    		dfs(i);
    		ans+=cnt-1;
    	}
    }
    cout<<k-ans<<endl;
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