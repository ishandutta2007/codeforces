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
int n,m,a,b,vis[200005];
vi adj[200005];
int bfs(int node){
    rep(i,1,n+1) vis[i]=0;
    int restr=a+b-node;
    queue<int> q;
    q.push(node);
    vis[node]=1;
    while(!q.empty()){
        int d=q.front();
        q.pop();
        for(auto i:adj[d]){
            if(vis[i] or i==restr) continue;
            q.push(i);
            vis[i]=1;
        }
    }
    int w=0;
    rep(i,1,n+1) w+=(vis[i]==0);
    return w-1;
}
void solve(){
    cin>>n>>m>>a>>b;
    rep(i,1,n+1) adj[i].clear();
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int cnta=bfs(a);
    int cntb=bfs(b);
    cout<<1LL*cnta*cntb<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}