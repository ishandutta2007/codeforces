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
int n,s[300005],leaf[300005];
vi a[300005];
void dfs(int node){
	leaf[node]=sz(a[node])==0;
	for(auto i:a[node]){
		dfs(i);
		leaf[node]+=leaf[i];
	}
}
int dfs2(int node){
	int w=leaf[node];
	int cur=1;
	for(auto i:a[node]){
		int v=dfs2(i);
		if(s[node]==0) cur+=v-1;
		else cur=max(cur,w-leaf[i]+v);
	}
	return cur;
}
void solve(){
    cin>>n;
    rep(i,1,n+1) cin>>s[i];
    rep(i,2,n+1){
    	int x;
    	cin>>x;
    	a[x].pb(i);
    }
    dfs(1);
    cout<<dfs2(1)<<endl;
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