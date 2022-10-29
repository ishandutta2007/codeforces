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
int n,m,col[200005];
vii e;
vi a[200005];
void dfs(int node,int c){
    col[node]=c;
    for(auto i:a[node]){
        if(col[i]==0){
            dfs(i,3-c);
        }
        else if(col[i]!=3-c){
            cout<<"NO"<<endl;
            exit(0);
        }
    }
}
void solve(){
    cin>>n>>m;
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
        e.pb({u,v});
    }
    dfs(1,1);
    cout<<"YES"<<endl;
    for(auto i:e) cout<<col[i.x]-1;
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