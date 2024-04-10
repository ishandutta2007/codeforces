#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
int mod=998244353;
int f[1005];
int ok[1005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
struct GenMatch { // 1-base
    static const int MAXN = 1005;
    int V;
    bool el[MAXN][MAXN];
    int pr[MAXN];
    bool inq[MAXN],inp[MAXN],inb[MAXN];
    queue<int> qe;
    int st,ed;
    int nb;
    int bk[MAXN],djs[MAXN];
    int ans;
    void init(int _V) {
        V = _V;
        MEM(el); MEM(pr);
        MEM(inq); MEM(inp); MEM(inb);
        MEM(bk); MEM(djs);
        ans = 0;
    }
    void add_edge(int u, int v) {
        el[u][v] = el[v][u] = 1;
    }
    int lca(int u,int v) {
        memset(inp,0,sizeof(inp));
        while(1) {
            u = djs[u];
            inp[u] = true;
            if(u == st) break;
            u = bk[pr[u]];
        }
        while(1) {
            v = djs[v];
            if(inp[v]) return v;
            v = bk[pr[v]];
        }
        return v;
    }
    void upd(int u) {
        int v;
        while(djs[u] != nb) {
            v = pr[u];
            inb[djs[u]] = inb[djs[v]] = true;
            u = bk[v];
            if(djs[u] != nb) bk[u] = v;
        }
    }
    void blo(int u,int v) {
        nb = lca(u,v);
        memset(inb,0,sizeof(inb));
        upd(u); upd(v);
        if(djs[u] != nb) bk[u] = v;
        if(djs[v] != nb) bk[v] = u;
        for(int tu = 1; tu <= V; tu++)
        if(inb[djs[tu]]) {
            djs[tu] = nb;
            if(!inq[tu]){
                qe.push(tu);
                inq[tu] = 1;
            }
        }
    }
    void flow() {
        memset(inq,false,sizeof(inq));
        memset(bk,0,sizeof(bk));
        for(int i = 1; i <= V;i++)
        djs[i] = i;
        while(qe.size()) qe.pop();
        qe.push(st);
        inq[st] = 1;
        ed = 0;
        while(qe.size()) {
            int u = qe.front(); qe.pop();
            for(int v = 1; v <= V; v++)
            if(el[u][v] && (djs[u] != djs[v]) && (pr[u] !=
            v)) {
                if((v == st) || ((pr[v] > 0) && bk[pr[v]] >
                0))
                blo(u,v);
                else if(bk[v] == 0) {
                    bk[v] = u;
                    if(pr[v] > 0) {
                        if(!inq[pr[v]]) qe.push(pr[v]);
                        } else {
                        ed = v;
                        return;
                    }
                }
            }
        }
    }
    void aug() {
        int u,v,w;
        u = ed;
        while(u > 0) {
            v = bk[u];
            w = pr[v];
            pr[v] = u;
            pr[u] = v;
            u = w;
        }
    }
    int solve() {
        memset(pr,0,sizeof(pr));
        for(int u = 1; u <= V; u++)
        if(pr[u] == 0) {
            st = u;
            flow();
            if(ed > 0) {
                aug();
                ans ++;
            }
        }
        return ans;
    }
}gp;
struct Scc{
    int n, nScc, vst[MXN], bln[MXN];
    vector<int> E[MXN], rE[MXN], vec;
    void init(int _n){
        n = _n;
        for (int i=0; i<MXN; i++){
            E[i].clear();
            rE[i].clear();
        }
    }
    void add_edge(int u, int v){
        E[u].pb(v);
        rE[v].pb(u);
    }
    void DFS(int u){
        vst[u]=1;
        for (auto v : E[u])
        if (!vst[v]) DFS(v);
        vec.pb(u);
    }
    void rDFS(int u){
        vst[u] = 1;
        bln[u] = nScc;
        for (auto v : rE[u])
        if (!vst[v]) rDFS(v);
    }
    void solve(){
        nScc = 0;
        vec.clear();
        MEM(vst);
        for (int i=0; i<n; i++)
        if (!vst[i]) DFS(i);
        reverse(vec.begin(),vec.end());
        MEM(vst);
        for (auto v : vec){
            if (!vst[v]){
                rDFS(v);
                nScc++;
            }
        }
    }
}g,g2;
vector<int> v[1005];
int use[1005];
void solve(){
    int n;
    scanf("%d",&n);
    int a[1005][505];
    for(int i = 0;i<2*n;i++){
        v[i].clear();
        ok[i]=1;f[i]=i;
        use[i]=0; 
        for(int j=0;j<n;j++)scanf("%d",&a[i][j]);
    }
    gp.init(2*n);
    g.init(4*n);
    g2.init(2*n);
    for(int i = 0;i<2*n;i++){
        for(int j = i+1;j<2*n;j++){
            int ok=0;
            for(int k = 0;k<n;k++){
                if(a[i][k]==a[j][k]){
                    ok=1;
                   // printf("%d\n",k);
                    break;
                }
            }
            if(ok){
                gp.add_edge(i+1,j+1);
                g.add_edge(i,j+2*n);
                g.add_edge(j,i+2*n);
                v[i].pb(j);
                v[j].pb(i);
             //   printf("%d %d\n",i,j);
            }
        }
    }
    assert(gp.solve()==n);
    for(int i = 1;i<=2*n;i++){
        g.add_edge(i-1+2*n,gp.pr[i]-1);
    }
    g.solve();
    for(int i = 0;i<2*n;i++){
        if(g.bln[i]>g.bln[i+2*n])use[i]=1;
    }
    vector<pii> edge;
    for(int i=0;i<2*n;i++){
        if(!use[i]){
            for(auto it:v[i]){
                if(use[it]){
                   // printf("%d %d\n",gp.pr[i+1],it+1);
                    g2.add_edge(gp.pr[i+1]-1,it);
                    edge.pb(mp(gp.pr[i+1]-1,it));
                    int a=Find(it),b=Find(gp.pr[i+1]-1);
                    f[a]=b;
                }
            }
        }
    }
    g2.solve();
    int ok2[1005];
    fill(ok2,ok2+2*n+1,1);
    for(int i = 0;i<2*n;i++){
        if(!use[i]){
            for(auto it:v[i]){
                if(!use[it]){
                  //  printf("%d %d\n",i+1,it+1);
                    if(g2.bln[gp.pr[i+1]-1]==g2.bln[gp.pr[it+1]-1]){ok2[g2.bln[gp.pr[i+1]-1]]=0;
                   // printf("%d %d %d\n",gp.pr[i+1]-1,i+1,it+1);
                    }
                  //  int a=(gp.pr[i+1]-1),b=Find(gp.pr[it+1]-1);

                    //if(a==b)ok[a]=0;
                }
            }
        }
    }
    for(auto it:edge){
        if(g2.bln[it.x]!=g2.bln[it.y])ok2[g2.bln[it.x]]=0;
    }
    LL ans=1;
    for(int i = 0;i<2*n;i++){
        if(use[i]&&ok2[g2.bln[i]]){
            //printf("%d %d\n",i,g);
            ans=ans*2%mod;
            ok2[g2.bln[i]]=0;
        }
    }
    printf("%lld\n",ans);
    for(int i = 0;i<2*n;i++){
        if(use[i])printf("%d ",i+1);
    }
    printf("\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}