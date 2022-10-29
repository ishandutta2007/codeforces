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
int n,m,k,p[300005],d[300005],vis[300005];
vi a[300005],leaves;
void dfs(int node,int par){
    p[node]=par;
    d[node]=d[par]+1;
    vis[node]=1;
    bool isleaf=1;
    for(auto i:a[node]){
        if(!vis[i]){
            dfs(i,node);
            isleaf=0;
        }
    }
    if(isleaf) leaves.pb(node);
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
    rep(i,1,n+1){
        if(1LL*d[i]*k>=n){
            cout<<"PATH"<<endl;
            cout<<d[i]<<endl;
            while(i){
                cout<<i<<" ";
                i=p[i];
            }
            return;
        }
    }
    cout<<"CYCLES"<<endl;
    for(auto i:leaves){
        if(k--==0) return;
        int x=0,y=0;
        for(auto j:a[i]){
            if(j==p[i]) continue;
            if(!x) x=j;
            else if(!y) y=j;
            else break;
        }
        if(d[x]<d[y]) swap(x,y);
        if((d[i]-d[y]+1)%3) x=y;
        if((d[i]-d[x]+1)%3){
            cout<<d[i]-d[x]+1<<endl;
            while(i!=p[x]){
                cout<<i<<" ";
                i=p[i];
            }
            cout<<endl;
        }
        else{
            cout<<d[x]-d[y]+2<<endl;
            cout<<i<<" ";
            while(x!=p[y]){
                cout<<x<<" ";
                x=p[x];
            }
            cout<<endl;
        }
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