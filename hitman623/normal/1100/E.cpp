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
int n,m,x[100005],y[100005],w[100005],vis[100005],pos[100005],lo=-1,hi=hell;
vi a[100005],stk,ans;
void dfs(int node){
    vis[node]=1;
    for(auto i:a[node]) if(!vis[i]) dfs(i);
    stk.pb(node);
}
bool check(int mid){
    stk.clear();
    rep(i,1,n+1) a[i].clear(),vis[i]=0;
    rep(i,0,m) if(w[i]>mid) a[x[i]].pb(y[i]);
    rep(i,1,n+1) if(!vis[i]) dfs(i);
    rep(i,0,sz(stk)) pos[stk[i]]=i;
    rep(i,0,m) if(w[i]>mid and pos[x[i]]<pos[y[i]]) return 0;
    return 1;
}
void solve(){
    cin>>n>>m;
    rep(i,0,m) cin>>x[i]>>y[i]>>w[i];
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(check(mid)) hi=mid;
        else lo=mid;
    }
    check(hi);
    rep(i,0,m) if(pos[x[i]]<pos[y[i]]) ans.pb(i+1);
    cout<<hi<<" "<<sz(ans)<<endl;
    for(auto i:ans) cout<<i<<" ";
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