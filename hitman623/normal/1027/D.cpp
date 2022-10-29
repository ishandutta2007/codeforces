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
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,c[200005],vis[200005],par[200005],ans;
vi a[200005];
void dfs(int node,int p){
    vis[node]=1;
    par[node]=p;
    for(auto i:a[node]){
        if(vis[i]==0){
            dfs(i,node);
        }
        else if(vis[i]==1){
            int s=c[i];
            int cur=node;
            while(cur!=i){
                s=min(s,c[cur]);
                cur=par[cur];
            }
            ans+=s;
        }
    }
    vis[node]=2;
}
void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>c[i];
    }
    rep(i,1,n+1){
        int x;
        cin>>x;
        a[i].pb(x);
    }
    rep(i,1,n+1){
        if(!vis[i]){
            dfs(i,-1);
        }
    }
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