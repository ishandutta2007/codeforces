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
#define hell        998244353
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,cnt;
vi a[300005],vis;
int dfs(int node,int f){
    cnt++;
    int ans=1+f;
    vis[node]=1+f;
    for(auto i:a[node]){
        if(vis[i]==0){
            ans=ans*dfs(i,!f)%hell;
        }
        else if(vis[i]!=1+!f) return 0;
    }
    return ans;
}
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
void solve(){
    cin>>n>>m;
    vis.clear();
    vis.resize(n+1);
    rep(i,1,n+1) a[i].clear();
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    int ans=1;
    rep(i,1,n+1){
        if(!vis[i]){
            cnt=0;
            int cur=dfs(i,0);
            cur=(cur+expo(2,cnt,hell)*expo(cur,hell-2,hell))%hell;
            ans=ans*cur%hell;
        }
    }
    cout<<ans<<endl;
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