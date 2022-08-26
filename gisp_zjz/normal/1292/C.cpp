#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=3050;
ll dp[3005][3005],ans;
int n,pre[maxn],sz[maxn],up[maxn][maxn];
bool anc[maxn][maxn];
vector <int> h[maxn];
void dfs(int u,int fa){
    pre[u]=fa; sz[u]=1;
    for (auto v:h[u]){
        if (v==fa) continue;
        dfs(v,u); sz[u]+=sz[v];
    }
}
ll solve(int u,int v){
    if (u>v) swap(u,v);
    if (anc[u][v]) swap(u,v);
    if (dp[u][v]!=-1) return dp[u][v];
    ll ret=1;
    if (anc[v][u]){
        int val=(n-sz[up[v][u]])*sz[v];
        if (u!=1) ret=max(ret,solve(v,pre[u])+val);
        for (auto w:h[u]) if (w!=up[v][u]&&w!=pre[u]) ret=max(ret,solve(w,v)+val);
        for (auto w:h[v]) if (w!=pre[v]) ret=max(ret,solve(w,u)+val);
    } else {
        int val=sz[u]*sz[v];
        for (auto w:h[u]) if (w!=pre[u]) ret=max(ret,solve(w,v)+val);
        for (auto w:h[v]) if (w!=pre[v]) ret=max(ret,solve(u,w)+val);
    }
    dp[u][v]=ret;
    //cout<<u<<' '<<v<<' '<<dp[u][v]<<endl;
    return ret;
}
int main(){
    cin >> n;
    for (int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        h[u].pb(v); h[v].pb(u);
    }
    dfs(1,0);
    for (int i=1;i<=n;i++)
        for (int last=i,j=pre[i];j;last=pre[last],j=pre[j]) anc[i][j]=1,up[i][j]=last;
    memset(dp,-1,sizeof(dp));
    for (int i=1;i<=n;i++)
        for (auto j:h[i])
            ans=max(ans,solve(i,j));
    cout << ans << endl;
    return 0;
}