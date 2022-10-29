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
int n,x[100005],val[100005],ans,h[100005];
vi a[100005];
vii v[100005];
void dfs(int node,int par){
    if(par!=-1) h[node]=h[par]+1,v[node]=v[par];
    v[node].pb({node,x[node]});
    for(auto &j:v[node]) j.y=__gcd(j.y,x[node]);
    int last=-1;
    vii vv;
    for(auto i:v[node]){
        if(i.y!=last){
            vv.pb(i);
            last=i.y;
        }
    }
    v[node]=vv;
    val[node]=x[node]%hell;
    int cur=h[node];
    reverse(all(v[node]));
    for(auto i:v[node]){
        val[node]=(val[node]+(cur-h[i.x])*(i.y%hell)%hell)%hell;
        cur=h[i.x];
    }
    reverse(all(v[node]));
    for(auto i:a[node]){
        if(i!=par){
            dfs(i,node);
        }
    }
    ans=(ans+val[node])%hell;
}
void solve(){
    cin>>n;
    rep(i,1,n+1) cin>>x[i];
    rep(i,0,n-1){
        int xx,y;
        cin>>xx>>y;
        a[xx].pb(y);
        a[y].pb(xx);
    }
    dfs(1,-1);
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