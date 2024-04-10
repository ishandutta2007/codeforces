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
int n,h[100005],leaf[100005],p[100005];
vi a[100005];
void dfs(int node,int par){
	p[node]=par;
	leaf[node]=1;
	h[node]=h[par]+1;
	for(auto i:a[node]){
		if(i!=par){
			leaf[node]=0;
			dfs(i,node);
		}
	}
}
void solve(){
    cin>>n;
    rep(i,0,n-1){
    	int u,v;
    	cin>>u>>v;
    	a[u].pb(v);
    	a[v].pb(u);
    }
    int root=-1;
    rep(i,1,n+1){
    	if(sz(a[i])!=1) root=i;
    }
    dfs(root,0);
    int l=0,r=n-1,o[2]={0};
    vi v;
    rep(i,1,n+1){
    	if(leaf[i]){
    		o[h[i]%2]++;
    		v.pb(p[i]);
    		r--;
    	}
    }
    sort(all(v));
    v.resize(unique(all(v))-v.begin());
    r+=sz(v);
    if(o[0]==0 or o[1]==0) l=1;
    else l=3;
    cout<<l<<" "<<r<<endl;

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