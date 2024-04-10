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
int n,m,k,a[500005],vis[500005],s[500005],p[500005]={1},par[500005];
vi adj[500005];
map<int,vii> edges;
int fp(int x){
    if(par[x]==x) return x;
    else return par[x]=fp(par[x]);
}
void solve(){
    rep(i,1,500001) p[i]=2*p[i-1]%hell;
    cin>>n>>m>>k;
    rep(i,1,n+1) cin>>a[i];
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        edges[a[u]^a[v]].pb({u,v});
    }
    int ans=(p[k]+hell-sz(edges))*p[n]%hell;
    for(auto i:edges){
        unordered_set<int> st;
        for(auto j:i.y){
            st.insert(j.x);
            st.insert(j.y);
            par[j.x]=j.x;
            par[j.y]=j.y;
            vis[j.x]=0;
            vis[j.y]=0;
        }
        int cnt=n-sz(st);
        for(auto j:i.y){
            j.x=fp(j.x);
            j.y=fp(j.y);
            par[j.x]=j.y;
        }
        for(auto j:i.y){
            j.x=fp(j.x);
            j.y=fp(j.y);
            if(vis[j.x]==0) cnt++,vis[j.x]=1;
            if(vis[j.y]==0) cnt++,vis[j.y]=1;
        }
        ans=(ans+p[cnt])%hell;
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