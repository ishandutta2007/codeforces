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
int n,a[200005],b[200005],c[200005],ans;
vi adj[200005];
pii dfs(int node,int par,int val){
    val=min(val,a[node]);
    pii w={0,0};
    if(b[node]!=c[node]){
        if(b[node]==0) w.x++;
        else w.y++;
    }
    for(auto i:adj[node]){
        if(i!=par){
            pii d=dfs(i,node,val);
            w.x+=d.x;
            w.y+=d.y;
        }
    }
    int g=min(w.x,w.y);
    ans+=val*g;
    w.x-=g;
    w.y-=g;
    return w;
}
void solve(){
    cin>>n;
    rep(i,1,n+1) cin>>a[i]>>b[i]>>c[i];
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    pii w=dfs(1,-1,hell);
    if(w.x or w.y) cout<<-1<<endl;
    else cout<<ans*2<<endl;
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