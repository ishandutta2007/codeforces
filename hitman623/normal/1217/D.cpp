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
int n,m,vis[5005],col[5005];
vii a[5005];
vi v,colors;
void dfs(int node){
	vis[node]=1;
	for(auto i:a[node]){
		if(vis[i.x]==0){
			dfs(i.x);
		}
	}
	v.pb(node);
}
void solve(){
    cin>>n>>m;
    rep(i,0,m){
    	int x,y;
    	cin>>x>>y;
    	a[x].pb({y,i});
    }
    rep(i,1,n+1){
    	if(vis[i]==0){
    		dfs(i);
    	}
    }
    reverse(all(v));
    memset(vis,0,sizeof vis);
    for(auto i:v){
    	for(auto j:a[i]) col[j.y]=1+vis[j.x];
    	vis[i]=1;
    }
    rep(i,0,m) colors.pb(col[i]);
    sort(all(colors));
    colors.resize(unique(all(colors))-colors.begin());
    cout<<sz(colors)<<endl;
    rep(i,0,m) cout<<col[i]<<" ";
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