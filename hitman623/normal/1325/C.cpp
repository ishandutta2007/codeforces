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
int n;
vi a[100005];
map<pii,int> mp;
vii edges;
void solve(){
    cin>>n;
    rep(i,0,n-1){
    	int u,v;
    	cin>>u>>v;
    	a[u].pb(v);
    	a[v].pb(u);
    	edges.pb({u,v});
    }
    int st=1;
    rep(i,1,n+1){
    	if(sz(a[i])>2){
    		st=i;
    		break;
    	}
    }
    int cur=0;
    rep(_,0,n){
    	for(auto i:a[st]){
    		if(mp.count({st,i})==0){
	    		mp[{st,i}]=cur++;
	    		mp[{i,st}]=cur-1;
    		}
    	}
    	st++;
    	if(st>n) st=1;
    }
    for(auto i:edges) cout<<mp[i]<<endl;
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