#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=1e6+10;
const int M=998244353;
vi G[maxn],H[maxn];
int f[maxn],g[maxn],_,n,sf[maxn],sg[maxn],cnt,p[maxn];
void dfs(int u,int fa){
    sf[u]=sg[u]=0;
    f[u]^=g[u];
    for (auto v:G[u]){
        if (v==fa) continue;
        g[v]=g[u]^1; 
        dfs(v,u);
        sf[u]+=sf[v];
        sg[u]+=sg[v];
    }
    sf[u]+=f[u]; sg[u]+=g[u];
    if (!fa) return;
    if (sf[u]-sg[u]==1) H[u].pb(fa);
    else if (sg[u]-sf[u]==1) H[fa].pb(u);
    else cnt++;
}
void _push(int u){
    if (p[u]==H[u].size()) return;
    int v=H[u][p[u]]; p[u]++;
    if (f[v]) _push(v);
    printf("%d %d\n",u,v);
    f[u]^=1; f[v]^=1;
    _push(v);
}
void solve(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) G[i].clear(),H[i].clear();
    for (int i=1;i<=n;i++) p[i]=f[i]=g[i]=0;
    for (int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        G[u].pb(v); G[v].pb(u);
        f[u]^=1; f[v]^=1;
    }
    cnt=0;
    dfs(1,0);
    if (sf[1]!=sg[1]||cnt){puts("NO");return;}
    puts("YES");
    for (int i=1;i<=n;i++) if (f[i]) _push(i);
}
int main(){
    scanf("%d",&_);
    while (_--) solve();
}