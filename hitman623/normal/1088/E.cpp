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
#define hell        1000000000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,val[300005],ans[300005],cnt,mx=-hell;
vi a[300005];
void dfs(int node,int par){
	ans[node]=val[node];
	for(auto i:a[node]){
		if(i!=par){
			dfs(i,node);
			ans[node]+=max(0LL,ans[i]);
		}
	}
}
void dfs2(int node,int par){
	ans[node]=val[node];
	for(auto i:a[node]){
		if(i!=par){
			dfs2(i,node);
			ans[node]+=max(0LL,ans[i]);
		}
	}
	if(ans[node]==mx) cnt++,ans[node]=0;
}
void solve(){
    cin>>n;
    rep(i,1,n+1) cin>>val[i];
    rep(i,0,n-1){
    	int u,v;
    	cin>>u>>v;
    	a[u].pb(v);
    	a[v].pb(u);
    }
    dfs(1,-1);
    rep(i,1,n+1) mx=max(mx,ans[i]);
    dfs2(1,-1);
    cout<<mx*cnt<<" "<<cnt<<endl;
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