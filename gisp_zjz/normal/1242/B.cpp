#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int maxn=100005;
const int E=4000;
vector <int> h[maxn];
bool f[E+3][E+3],vis[maxn];
int n,m,pre[maxn],ans,d[maxn],id[maxn],tot;
int ffind(int x){
    if (pre[x]!=x) pre[x]=ffind(pre[x]);
    return pre[x];
}
int main(){
    scanf("%d%d",&n,&m);
    if (n<=E){
        memset(f,1,sizeof(f));
        while (m--){
            int u,v;scanf("%d%d",&u,&v);
            if (u>v) swap(u,v);
            f[u][v]=0;
        }
        ans=n-1;
        for (int i=1;i<=n;i++) pre[i]=i;
        for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++) if (f[i][j]){
            int u=ffind(i),v=ffind(j);
            if (u!=v) ans--,pre[v]=u;
        }
        printf("%d\n",ans);
    } else {
        while (m--){
            int u,v;scanf("%d%d",&u,&v);
            h[u].pb(v); h[v].pb(u);
            d[u]++; d[v]++;
        }
        for (int i=1;i<=n;i++) if (d[i]>=n/2) id[i]=++tot;
        for (int i=0;i<=tot;i++) pre[i]=i; ans=tot;
        for (int i=1;i<=n;i++) if (d[i]>=n/2){
            memset(vis,0,sizeof(vis));
            for (auto x:h[i]) vis[x]=1; vis[i]=1;
            for (int j=1;j<=n;j++) if (!vis[j]){
                int u=ffind(id[i]),v=ffind(id[j]);
                if (u!=v) pre[v]=u,ans--;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}