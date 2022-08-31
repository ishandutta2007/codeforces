#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int> pi;
const int maxn=1e6+3;
vector <pi> h[maxn];
struct edge{
    int u,v,w,id;
};
bool cmp(edge x,edge y){
    return x.w<y.w;
}
edge a[maxn];
int pre[maxn],n,m,ans[maxn];
int fa[maxn][18],dep[maxn],mx[maxn][18];
int ffind(int x){
    if (pre[x]==x) return x;
    pre[x]=ffind(pre[x]);
    return pre[x];
}
void dfs(int u,int p){
    for (auto x:h[u]){
        int v=x.F;
        if (p==v) continue;
        dep[v]=dep[u]+1;
        fa[v][0]=u;
        mx[v][0]=x.S;
        dfs(v,u);
    }
}
int lca(int u,int v){
    if (dep[u]>dep[v]) swap(u,v);
    for (int i=0;i<18;i++) if ((dep[v]-dep[u])&(1<<i)) v=fa[v][i];
    if (u==v) return u;
    for (int i=17;i>=0;i--) if (fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
int ask(int u,int st){
    int ret=0;
    for (int i=0;i<18;i++) if (st&(1<<i)) ret=max(ret,mx[u][i]),u=fa[u][i];
    return ret;
}
int main(){
    cin >> n >> m;
    for (int i=0;i<m;i++) {
        a[i].id=i;
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    for (int i=1;i<=n;i++) pre[i]=i;
    sort(a,a+m,cmp);
    for (int i=0;i<m;i++){
        int u=ffind(a[i].u),v=ffind(a[i].v);
        if (u!=v) {
            pre[u]=v;
            ans[a[i].id]=-1;
            h[a[i].u].pb((pi){a[i].v,a[i].w});
            h[a[i].v].pb((pi){a[i].u,a[i].w});
        }
    }
    dep[1]=1; dfs(1,0);
    for (int i=1;i<18;i++)
    for (int j=1;j<=n;j++){
        fa[j][i]=fa[fa[j][i-1]][i-1];
        mx[j][i]=max(mx[j][i-1],mx[fa[j][i-1]][i-1]);
    }
    for (int i=0;i<m;i++) if (ans[a[i].id]!=-1){
        int u=a[i].u,v=a[i].v,w=lca(u,v);
        ans[a[i].id]=max(ask(u,dep[u]-dep[w]),ask(v,dep[v]-dep[w]));
    }
    for (int i=0;i<m;i++) if (ans[i]!=-1) cout << ans[i] << endl;
}