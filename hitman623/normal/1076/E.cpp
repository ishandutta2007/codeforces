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
vi a[300005];
vii upd[300005];
int n,q,del[300005],ans[300005],bit[300015];
void update(int x,int y=1){
    for(;x<=300010;x+=x&(-x)) bit[x]+=y;
}
int query(int x){
    int res=0;
    for(;x>0;x-=x&(-x)) res+=bit[x];
    return res;
}
void dfs(int node,int par,int d){
    for(auto i:upd[node]){
        update(d,i.y);
        update(d+i.x+1,-i.y);
    }
    ans[node]=query(d);
    for(auto i:a[node]){
        if(i!=par){
            dfs(i,node,d+1);
        }
    }
    for(auto i:upd[node]){
        update(d,-i.y);
        update(d+i.x+1,i.y);
    }
}
void solve(){
    cin>>n;
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    cin>>q;
    while(q--){
        int v,d,x;
        cin>>v>>d>>x;
        d=min(d,n);
        upd[v].pb({d,x});
    }
    dfs(1,0,1);
    rep(i,1,n+1) cout<<ans[i]<<" ";
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