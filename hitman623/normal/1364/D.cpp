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
int n,m,k,vis[100005],h[100005],p[100005];
vi a[100005],y[2];
void dfs(int node,int par){
    h[node]=h[par]+1;
    y[h[node]%2].pb(node);
    p[node]=par;
    vis[node]=1;
    vii v;
    for(auto i:a[node]){
        if(vis[i]==2) continue;
        if(vis[i]==0) dfs(i,node);
        else if(h[i]<h[node] and h[node]-h[i]+1>2) v.pb({h[node]-h[i]+1,i});
    }
    sort(all(v));
    if(sz(v) and v[0].x<=k){
        int cur=node;
        vi res;
        while(cur!=v[0].y){
            res.pb(cur);
            cur=p[cur];
        }
        res.pb(cur);
        cout<<2<<endl;
        cout<<sz(res)<<endl;
        for(auto i:res) cout<<i<<" ";
        cout<<endl;
        exit(0);
    }
    else if(sz(v)){
        int cur=node;
        vi res;
        while(cur!=v[0].y){
            res.pb(cur);
            cur=p[cur];
        }
        res.pb(cur);
        cout<<1<<endl;
        int f=1,w=(k+1)/2;
        for(auto i:res){
            if(f and w){
                cout<<i<<" ";
                w--;
            }
            f^=1;
        }
        cout<<endl;
        exit(0);
    }
    vis[node]=2;
}
void solve(){
    cin>>n>>m>>k;
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }
    dfs(1,0);
    k=(k+1)/2;
    if(sz(y[0])>=k){
        cout<<1<<endl;
        rep(i,0,k) cout<<y[0][i]<<" ";
        cout<<endl;
    }
    else{
        cout<<1<<endl;
        rep(i,0,k) cout<<y[1][i]<<" ";
        cout<<endl;
    }
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