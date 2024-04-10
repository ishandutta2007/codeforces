#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<int> vi;
const int maxn=3e5+12;
const int E=400;
queue <int> q[maxn];
vi h[maxn];
int LL[maxn],RR[maxn],L[maxn],R[maxn],pre[maxn][18],tot,k,n,m,a[maxn],s[maxn],b[maxn],color[maxn],dep[maxn],dis[maxn],id[maxn],p[maxn];
int LCA[E+5],gid[maxn],sol[E+5][E+5];
void dfs(int u,int fa){
    id[u]=L[u]=++tot;
    pre[u][0]=fa;
    for (auto v:h[u]){
        if (v==fa) continue;
        dep[v]=dep[u]+1; dfs(v,u);
    }
    R[u]=tot;
}
int lca(int u,int v){
    if (dep[u]<dep[v]) swap(u,v);
    int dif=dep[u]-dep[v];
    for (int i=0;i<18;i++) if ((dif>>i)&1) u=pre[u][i];
    if (u==v) return u;
    for (int i=17;i>=0;i--) if (pre[u][i]!=pre[v][i]) u=pre[u][i],v=pre[v][i];
    return pre[u][0];
}
bool cmp(int u,int v){
    return id[a[u]]<id[a[v]];
}
int go(int u,int v,int w){
    int len=dep[u]+dep[v]-2*dep[w]-1;
    int p=gid[u],q=gid[v];
    if (p>q) return len-go(v,u,w);
    int round=len/(s[p]+s[q]);
    return round*s[p]+min(s[p],len%(s[p]+s[q]));
}
bool cmp2(int u,int v,int to){
    int w=lca(u,v);
    if (v==-1) return 1;
    return dep[u]<=go(u,v,w)+dep[to];
}
int solve(int l,int r){
    //cout<<l<<' '<<r<<endl;
    if (l==r) return sol[l][r]=a[p[l]];
    int u=lca(a[p[l]],a[p[r]]);
    int st=l;
    vector <int> f; f.clear();
    for (int i=l;i<r;i++) if (LCA[i]==u){
        f.pb(solve(st,i));
        st=i+1;
    }
    f.pb(solve(st,r));
    int ans=-1;
    for (auto x:f) if (cmp2(x,ans,u)) ans=x;
    /*
    for (auto x:f) if (x!=ans){
        int up=go(x,ans,u),y=x;
        for (int j=0;j<18;j++) if ((up>>j)&1) y=pre[y][j];
        LL[gid[x]]=L[y];
        RR[gid[x]]=R[y];
    }
    */
    return sol[l][r]=ans;
}
void solve2(int l,int r,int top){
    if (top!=-1){
        int x=sol[l][r];
        if (x!=top){
            int up=go(x,top,lca(x,top)),y=x;
            for (int j=0;j<18;j++) if ((up>>j)&1) y=pre[y][j];
            LL[gid[x]]=L[y];
            RR[gid[x]]=R[y];
        }
    }
    if (l==r) return;
    int u=lca(a[p[l]],a[p[r]]);
    int st=l;
    vector <int> f; f.clear();
    for (int i=l;i<r;i++) if (LCA[i]==u) f.pb(sol[st][i]),st=i+1;
    f.pb(solve(st,r));
    int ans=top;
    for (auto x:f) if (cmp2(x,ans,u)) ans=x;
    st=l;
    for (int i=l;i<r;i++) if (LCA[i]==u) solve2(st,i,ans),st=i+1;
    solve2(st,r,ans);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        h[u].pb(v); h[v].pb(u);
    }
    dfs(1,0);
    for (int i=1;i<18;i++)
        for (int j=1;j<=n;j++)
            pre[j][i]=pre[pre[j][i-1]][i-1];
    int _; scanf("%d",&_);
    while (_--){
        scanf("%d%d",&k,&m);
        for (int i=1;i<=k;i++) scanf("%d%d",&a[i],&s[i]);
        for (int i=1;i<=m;i++) scanf("%d",&b[i]);
        if (k<=E){
            for (int i=1;i<=k;i++) p[i]=i,gid[a[i]]=i;
            sort(p+1,p+1+k,cmp);
            for (int i=1;i<k;i++) LCA[i]=lca(a[p[i]],a[p[i+1]]);
            int u=solve(1,k);
            LL[gid[u]]=1; RR[gid[u]]=n;
            solve2(1,k,-1);
            for (int i=1;i<=m;i++){
                int u=b[i],ans=0;
                for (int j=1;j<=k;j++) if (LL[j]<=id[u]&&id[u]<=RR[j]){
                    if (LL[j]>LL[ans]) ans=j;
                }
                printf("%d ",ans);
            }
            puts("");
        } else {
            for (int i=1;i<=n;i++) color[i]=0;
            for (int i=1;i<=k;i++) {
                while (!q[i].empty()) q[i].pop();
                dis[a[i]]=0; color[a[i]]=i; q[i].push(a[i]);
            }
            int cc=k;
            for (int it=0;;it++){
                for (int i=1;i<=k;i++){
                    while (!q[i].empty()&&dis[q[i].front()]/s[i]==it){
                        int u=q[i].front(); q[i].pop();
                        for (auto v:h[u]){
                            if (color[v]) continue;
                            color[v]=color[u];
                            dis[v]=dis[u]+1;
                            q[i].push(v); cc++;
                        }
                    }
                }
                if (cc==n) break;
            }
            for (int i=1;i<=m;i++) printf("%d ",color[b[i]]); puts("");
        }
    }
}