#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
const int maxn=1e6+10;
vector<pi>G[maxn];
bool vis[maxn];
int n,m,c[maxn],x[maxn],y[maxn],z[maxn],p[maxn],flag,_;
void dfs(int u,int o){
    c[u]=o; vis[u]=1;
    for (auto e:G[u]){
        int v=e.F;
        if (!vis[v]) dfs(v,o^e.S);
        else if ((c[u]^c[v])!=e.S) flag=0;
    }
}
void solve(){
    scanf("%d%d",&n,&m); flag=1;
    for (int i=1;i<=n;i++) G[i].clear(),vis[i]=0;
    for (int i=1;i<n;i++){
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
        if (z[i]!=-1){
            int u=x[i],v=y[i],w=__builtin_popcount(z[i])&1;
            G[u].pb((pi){v,w});
            G[v].pb((pi){u,w});
        }
    }
    for (int i=0;i<m;i++){
        int u,v,w; scanf("%d%d%d",&u,&v,&w);
        G[u].pb((pi){v,w});
        G[v].pb((pi){u,w});
    }
    for (int i=1;i<=n;i++) if (!vis[i]) dfs(i,0);
    if (!flag){puts("NO");return;}
    puts("YES");
    for (int i=1;i<n;i++) {
        if (z[i]==-1) z[i]=c[x[i]]^c[y[i]];
        printf("%d %d %d\n",x[i],y[i],z[i]);
    }
}
int main(){
    cin >> _;
    while (_--) solve();
}