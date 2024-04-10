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
int n,p[2002],c[2002],root,val[2002];
vi a[2002];
vii v;
void go(int node){
	v.pb({val[node],node});
	for(auto i:a[node]) go(i);
}
void dfs(int node){
	for(auto i:a[node]) dfs(i);
	v.clear();
	for(auto i:a[node]) go(i);
	if(c[node]>sz(v)){
		cout<<"NO"<<endl;
		exit(0);
	}
	sort(all(v));
	rep(i,c[node],sz(v)) v[i].x+=2,val[v[i].y]+=2;
	if(c[node]) val[node]=v[c[node]-1].x+1;
	else val[node]=1;
}
void solve(){
    cin>>n;
    rep(i,1,n+1){
    	cin>>p[i]>>c[i];
    	if(p[i]) a[p[i]].pb(i);
    	else root=i;
    }
    dfs(root);
    cout<<"YES"<<endl;
    rep(i,1,n+1) cout<<val[i]<<" ";
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