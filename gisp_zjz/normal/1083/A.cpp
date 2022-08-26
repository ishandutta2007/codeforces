#include<bits/stdc++.h>
#define maxn 503000
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<ll,ll>pi;
vector <pi> h[maxn];
ll ans,n,dp[maxn],a[maxn];

void dfs(int u,int fa){
    ll x=0,y=0;
    for (int i=0;i<h[u].size();i++){
        int v=h[u][i].F;
        if (v==fa) continue;
        dfs(v,u);
        ll res=dp[v]-h[u][i].S;
        if (res>x) y=x,x=res;
        else if (res>y) y=res;
    }
    dp[u]=a[u]+x;
    ans=max(ans,a[u]+x+y);
}

int main(){
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<n;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        h[u].push_back({v,w});
        h[v].push_back({u,w});
    }
    dfs(1,0);
    cout << ans << endl;
    return 0;
}