#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
vector<int> G[maxn];
ll dp[maxn][2],l[maxn],r[maxn];
int _,n;
void dfs(int u,int fa){
    dp[u][0]=dp[u][1]=0;
    for (auto v:G[u]){
        if (v==fa) continue;
        dfs(v,u);
        dp[u][0]+=max(dp[v][0]+abs(l[u]-l[v]),dp[v][1]+abs(l[u]-r[v]));
        dp[u][1]+=max(dp[v][0]+abs(r[u]-l[v]),dp[v][1]+abs(r[u]-r[v]));
    }
}
void solve(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) G[i].clear();
    for (int i=1;i<=n;i++) scanf("%lld%lld",&l[i],&r[i]);
    for (int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        G[u].pb(v); G[v].pb(u);
    }
    dfs(1,0);
    printf("%lld\n",max(dp[1][0],dp[1][1]));
}
int main(){
    scanf("%d",&_);
    while (_--) solve();
}