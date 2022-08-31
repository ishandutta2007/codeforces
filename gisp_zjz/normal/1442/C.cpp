#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,int>pi;
const int maxn=1e6+100;
const int M=998244353;
vector<int> h[maxn],g[maxn];
const int inf=1e9+7;
const int E=4;
int n,m,l[2][maxn],base,d[25][maxn];
bool vis[25][maxn];
priority_queue<pi, vector<pi>, greater<pi> > q;
int main(){
    cin >> n >> m; base=n*2;
    for (int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        h[u].pb(v); g[v].pb(u);
    }
    memset(d,-1,sizeof(d));
    memset(l,-1,sizeof(l));
    q.push((pi){0,1});
    while (!q.empty()){
        pi tmp=q.top(); q.pop();
        int u=tmp.S; ll id=tmp.F;
        int layer=id/base,dis=id%base;
        int r=(layer<E)?layer:E+layer%2;
        if (vis[r][u]) continue;
        vis[r][u]=1;
        d[r][u]=dis;
        if (layer>=E) l[layer%2][u]=layer;
        if (layer%2==0){
            for (auto v:h[u]) q.push((pi){id+1,v});
            for (auto v:g[u]) q.push((pi){id+1+base,v});
        } else {
            for (auto v:g[u]) q.push((pi){id+1,v});
            for (auto v:h[u]) q.push((pi){id+1+base,v});
        }
        q.push((pi){id+base,u});
    }
    int ans=inf;
    for (int i=0;i<E;i++) if (d[i][n]!=-1) ans=min(ans,d[i][n]+(1<<i)-1);
    if (ans==inf){
        if (l[0][n]<l[1][n]){
            ans=1;
            for (int i=0;i<l[0][n];i++) ans=ans*2%M;
            ans--;
            ans=(ans+d[E][n])%M;
        } else {
            ans=1;
            for (int i=0;i<l[1][n];i++) ans=ans*2%M;
            ans--;
            ans=(ans+d[E+1][n])%M;
        }
    }
    printf("%d\n",ans);
    return 0;
}