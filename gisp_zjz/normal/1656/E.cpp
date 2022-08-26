#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=1e6+10;
vi G[maxn];
int _,d[maxn],n,c[maxn];
void dfs(int u,int fa,int o){
    c[u]=o;
    for (auto v:G[u]){
        if (v==fa) continue;
        dfs(v,u,-o);
    }
}
int main(){
    cin >> _;
    while (_--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) G[i].clear(),d[i]=0;
        for (int i=1;i<n;i++){
            int u,v; scanf("%d%d",&u,&v);
            G[u].pb(v); G[v].pb(u);
            d[u]++; d[v]++;
        }
        dfs(1,0,1);
        for (int i=1;i<=n;i++) printf("%d ",d[i]*c[i]);puts("");
    }
    return 0;
}