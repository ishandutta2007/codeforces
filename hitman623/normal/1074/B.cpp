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
int n,a[1001],b[1001],vis[1001],x,k1,k2,root;
vi adj[1001];
int bfs(int node){
    memset(vis,0,sizeof vis);
    queue<int> q;
    q.push(node);
    vis[node]=1;
    while(!q.empty()){
        int g=q.front();
        q.pop();
        if(a[g]) return g;
        vis[g]=1;
        for(auto i:adj[g]){
            if(!vis[i]) q.push(i);
        }
    }
    return -1;
}
void solve(){
    cin>>n;
    rep(i,1,n+1){
        adj[i].clear();
    }
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    rep(i,0,n-1){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cin>>k1;
    rep(i,0,k1){
        cin>>x;
        a[x]=1;
    }
    cin>>k2;
    rep(i,0,k2){
        cin>>x;
        b[x]=1;
        root=x;
    }
    cout<<"B "<<root<<endl;
    cin>>x;
    int d=bfs(x);
    cout<<"A "<<d<<endl;
    cin>>x;
    if(b[x]==1){
        cout<<"C "<<d<<endl;
    }
    else{
        cout<<"C -1"<<endl;
    }
}

signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}