#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int maxn=1e6+10;
vector<int> G[maxn];
int n,k,cnt,f[maxn],a[maxn],dep[maxn],nxt[maxn],mx[maxn];
ll ans;
void dfs(int u,int fa){
    mx[u]=dep[u];
    for (auto v:G[u]){
        if (v==fa) continue;
        dep[v]=dep[u]+1; f[u]=1;
        dfs(v,u);
        if (mx[v]>=mx[u]){
            mx[u]=mx[v];
            nxt[u]=v;
        }
    }
    if (!f[u]) ++cnt;
}
void dfs2(int u,int fa,int x){
    if (!f[u]) a[u]=x;
    for (auto v:G[u]){
        if (v==fa) continue;
        if (v==nxt[u]) dfs2(v,u,x+1);
        else dfs2(v,u,1);
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        G[u].pb(v);G[v].pb(u);
    }
    dfs(1,0);
    dfs2(1,0,1);
    sort(a+1,a+n+1);
    if (cnt>k){
        int sum=0;
        for (int i=n;i>n-k;i--) sum+=a[i];
        ll ans=1e12;
        for (int j=0;j<=n-sum;j++) ans=min(ans,1ll*(n-k-j)*(k-j));
        printf("%lld\n",ans);
    } else {
        ll ans=-1e12;
        for (int i=cnt;i<=k;i++) ans=max(ans,1ll*i*(n-i));
        printf("%lld\n",ans);
    }
}