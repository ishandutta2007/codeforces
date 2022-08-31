#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=605;
typedef pair<int,int>pi;
int bid[maxn][maxn];
int par[maxn],pre[maxn],link[maxn]; //
int n,N,ans;  
deque<int> q;
vector<int> g[maxn]={};
int ty[maxn];  //
int findp(int x){return x==par[x]?x:par[x]=findp(par[x]);}  //
int Ti=0,times[maxn]={}; //
int lca(int x,int y){
    for(Ti++;times[x]!=Ti;x^=y^=x^=y)  //x^=y^=x^=yxy
        if(x) times[x]=Ti,x=findp(pre[link[x]]);
    return x; 
}
void blossom(int x,int y,int p){   //
    while(findp(x)!=p){
        pre[x]=y;
        y=link[x];
        par[x]=par[y]=p;
        if(ty[y]==1) ty[y]=2,q.push_back(y);
        x=pre[y];
    }
}
bool Match(int x){
    for(int i=0;i<=N;i++) ty[i]=0,par[i]=i;
    q.clear();
    ty[x]=2,q.push_back(x);     //bfs 
    while(q.size()){
        x=q.front(),q.pop_front();
        for(int u:g[x])
            if(ty[u]==0){
                ty[u]=1;
                pre[u]=x;
                if(link[u]) q.push_back(link[u]),ty[link[u]]=2; 
                else {                   // 
                    for(;x;u=x){
                        x=link[pre[u]];
                        link[u]=pre[u];
                        link[link[u]]=u;
                    }
                    return 1;
                }
            }
            else if(ty[u]==2&&findp(u)!=findp(x)){  // 
                int p=lca(x,u);
                blossom(x,u,p),blossom(u,x,p);
            }
    }
    return 0;
}
bool ok[300005];
int m,a[300005],pos[300005];
int Pre[maxn];
void work1(int x,int u){
    if (a[pos[x]]==u){
        a[pos[x]+1]=u;
    } else {
        a[pos[x+1]-1]=u;
    }
    ok[u]=1;
}
vector<pi>G[605];
void dfs(int u,int fa){
    for (auto e:G[u]){
        int v=e.F;
        if (v==fa) continue;
        work1(e.S,v);
        dfs(v,u);
    }
}
void add_edge(int u,int v,int id){
    G[u].pb((pi){v,id});
    G[v].pb((pi){u,id});
}
void add_edge2(int u,int v,int id){
    bid[u][v]=id;
    bid[v][u]=id;
    g[u].pb(v); g[v].pb(u);
}
int ffind(int x){
    if (Pre[x]==x) return x;
    return Pre[x]=ffind(Pre[x]);
}
int main(){
    scanf("%d",&n); m=0;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    int s=0,t=0;
    for (int i=1;i<=n;i++){
        if (!a[i]) continue;
        if (!s) s=i; t=i;
    }
    if (!s){
        for (int i=1;i<=n;i++) printf("%d ",(i+1)/2); puts("");
        return 0;
    }
    if ((s-1)&1) a[s-1]=a[s];
    if ((n-t)&1) a[t+1]=a[t];
    for (int i=1;i<n;i++) if (a[i]!=0&&a[i]==a[i+1]) ok[a[i]]=1;
    for (int i=1;i<=n;i++) if (a[i]!=0) pos[++m]=i;
    N=min(n,600);
    for (int i=1;i<=N;i++) Pre[i]=i;
    for (int i=1;i<m;i++){
        int x=pos[i],y=pos[i+1];
        if (y-x==1) continue;
        if ((y-x-1)&1){
            int u=a[x],v=a[y];
            if (ok[u]&&ok[v]) continue;
            if (ok[u]){
                work1(i,v); dfs(v,0);
            } else if (ok[v]){
                work1(i,u); dfs(u,0);
            } else {
                if (ffind(u)!=ffind(v)){
                    Pre[ffind(u)]=Pre[ffind(v)];
                    add_edge(u,v,i);
                } else {
                    dfs(u,0);
                    work1(i,u);
                }
            }
        }
    }    
    for (int i=1;i<m;i++){
        int x=pos[i],y=pos[i+1];
        if (y-x==1) continue;
        if (!((y-x-1)&1)){
            int u=a[x],v=a[y];
            if (ok[u]||ok[v]) continue;
            if (ffind(u)==ffind(v)) continue;
            add_edge2(ffind(u),ffind(v),i);
        }
    }    
    
    int ans=0;
    for (int i=1;i<=N;i++) 
        if(!link[i]&&Match(i)) ans++;
    for (int i=1;i<=N;i++) if (ffind(i)==i){
        if (ok[i]) continue;
        if (link[i]>0){
            int u,j;
            j=bid[i][link[i]];
            if (ffind(a[pos[j]])==i) u=a[pos[j]]; else u=a[pos[j+1]];
            work1(j,u); dfs(u,0);
        } else {
            dfs(i,0);
        }
    }
    int cur=1;
    for (int i=1;i<n;i++){
        if (a[i]==0&&a[i+1]==0){
            while (ok[cur]) ++cur;
            a[i]=a[i+1]=cur; cur++;
        }
    }
    for (int i=1;i<=n;i++) if (a[i]==0) a[i]=n;
    for (int i=1;i<=n;i++) printf("%d ",a[i]);puts("");
    return 0;
}