#include<stdio.h>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<string.h>
#include<vector>
#define MAXN 210000
using namespace std;
int ptr[410000];
int next[410000];
int zu[410000];
int zeit, dis[MAXN], fin[MAXN], low[MAXN], par[MAXN], dep[MAXN];
int kodat[MAXN], koptr[MAXN + 1];
void dfsInfo(int u, int oy, int d) {
    dis[u] = low[u] = zeit++; par[u] = oy; dep[u] = d;
    int i, v;
    for (i = ptr[u]; ~i; i = next[i]) if ((v = zu[i]) != oy) {
        if (!~dis[v]) {
            dfsInfo(v, u, d + 1);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], dis[v]);
        }
    }
    fin[u] = zeit++;
}
int n;
void dfsInfos() {
    
    memset(dis, ~0, n * 4); zeit = 0;
    for (int u = 0; u < n; ++u) if (!~dis[u]) dfsInfo(u, -1, 0);
    for (int u = 0; u < n; ++u) {
        int &j = koptr[u + 1] = koptr[u];
        for (int i = ptr[u]; ~i; i = next[i]) if (u == par[zu[i]]) kodat[j++] = zu[i];
    }
}
bool produce(int u, int v) {
    return (dis[u] <= dis[v] && fin[u] >= fin[v]);
}
int related(int u, int v) {
    int s = koptr[u], e = koptr[u + 1], h;
    for (; s + 1 < e; ) {
        h = (s + e) >> 1;
        (dis[kodat[h]] <= dis[v]) ? s = h : e = h;
    }
    return kodat[s];
}
bool isBridge(int u, int v) {
    if (dis[u] > dis[v]) swap(u, v);
    return (u == par[v] && dis[v] <= low[v]);
}
bool isFatalEdge(int u, int v, int a, int b) {
    if (dis[u] > dis[v]) swap(u, v);
    return (u == par[v] && dis[v] <= low[v] && produce(v, a) != produce(v, b));
}
bool isFatalPoint(int u, int a, int b) {
    bool ua = produce(u, a), ub = produce(u, b);
    if (!ua && !ub) {
        return 0;
    } else if (ua && ub) {
        int ra = related(u, a), rb = related(u, b);
        return (ra != rb && (dis[u] <= low[ra] || dis[u] <= low[rb]));
    } else {
        if (ub) swap(a, b);
        return (dis[u] <= low[related(u, a)]);
    }
}
int UF[210000];
vector<int>g[210000];
vector<int>g2[210000];
int FIND(int a){
    if(UF[a]<0)return a;
    return UF[a]=FIND(UF[a]);
}
void UNION(int a,int b){
    a=FIND(a);b=FIND(b);if(a==b)return;UF[a]+=UF[b];UF[b]=a;
}
int uf[210000];
int fi(int a){
    if(uf[a]<0)return a;
    return uf[a]=fi(uf[a]);
}
void uni(int a,int b){
    a=fi(a);b=fi(b);if(a==b)return;uf[a]+=uf[b];uf[b]=a;
}

int L[210000];
int R[210000];
int tmp[420000];
int conv[210000];
int bit[2][210000];
int pos[210000];
int rev[210000];
int sz;
int cur;
int sum(int a,int b,int t){
    if(a)return sum(0,b,t)-sum(0,a-1,t);
    int ret=0;
    for(;b>=0;b=(b&(b+1))-1)ret+=bit[t][b];
    return ret;
}
void add(int a,int b,int t){
    for(;a<n;a|=a+1){
        bit[t][a]+=b;
    }
}
int segtree[1048576];
int query(int a,int b,int c,int d,int e){
    if(d<a||b<c)return 99999999;
    if(c<=a&&b<=d)return segtree[e];
    return min(query(a,(a+b)/2,c,d,e*2),query((a+b)/2+1,b,c,d,e*2+1));
}
void update(int a,int b){
    a+=524288;
    while(a){
        segtree[a]=min(segtree[a],b);
        a/=2;
    }
}
void dfs(int a,int b){
    tmp[cur++]=a;
    conv[a]=sz;
    rev[sz++]=a;
    for(int i=0;i<g2[a].size();i++){
        if(g2[a][i]==b)continue;
        dfs(g2[a][i],a);
        tmp[cur++]=a;
    }
}
void dfs2(int a,int b){
    L[a]=cur++;
    for(int i=0;i<g2[a].size();i++){
        if(g2[a][i]==b)continue;
        dfs2(g2[a][i],a);
    }
    R[a]=cur-1;
}
set<pair<int,int> > S;
int P[210000];
int Q[210000];
int A[210000];
int B[210000];
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    for(int i=0;i<a;i++){
        UF[i]=-1;
        uf[i]=-1;
    }
    int m=0;
    n=a;
    for(int i=0;i<410000;i++)ptr[i]=next[i]=-1;
    for(int i=0;i<b;i++){
        scanf("%d%d",P+i,Q+i);
        P[i]--;Q[i]--;
        uni(P[i],Q[i]);
    }
    for(int i=0;i<c;i++){
        scanf("%d%d",A+i,B+i);
        A[i]--;B[i]--;
        if(fi(A[i])!=fi(B[i])){
            printf("No\n");return 0;
        }
    }
    int las=-1;
    for(int i=0;i<a;i++){
        if(uf[i]<0){
            if(~las){
        g[i].push_back(las);
        g[las].push_back(i);
        zu[m]=las;
        next[m]=ptr[i];
        ptr[i]=m++;
        zu[m]=i;
        next[m]=ptr[las];
        ptr[las]=m++;
            }
            las=i;
        }
    }
    for(int i=0;i<b;i++){
    //  int p,q;
    //  scanf("%d%d",&p,&q);
    //  p--;q--;
        int p=P[i];
        int q=Q[i];
        if(S.count(make_pair(min(p,q),max(p,q)))){
            UNION(p,q);continue;
        }
        S.insert(make_pair(min(p,q),max(p,q)));
        g[p].push_back(q);
        g[q].push_back(p);
        zu[m]=q;
        next[m]=ptr[p];
        ptr[p]=m++;
        zu[m]=p;
        next[m]=ptr[q];
        ptr[q]=m++;
    }
    dfsInfos();
    for(int i=0;i<a;i++){
        for(int j=0;j<g[i].size();j++){
            if(!isBridge(i,g[i][j]))UNION(i,g[i][j]);
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<g[i].size();j++){
            if(i<g[i][j]&&FIND(i)!=FIND(g[i][j])){
                g2[FIND(i)].push_back(FIND(g[i][j]));
                g2[FIND(g[i][j])].push_back(FIND(i));
        //      printf("%d %d\n",FIND(i),FIND(g[i][j]));
            }
        }
    }
    dfs(FIND(0),-1);
    for(int i=0;i<cur;i++){
        pos[tmp[i]]=i;
    }
    for(int i=0;i<1048576;i++)segtree[i]=99999999;
    for(int i=0;i<cur;i++){
        update(i,conv[tmp[i]]);
    }
    cur=0;
    dfs2(FIND(0),-1);
    for(int i=0;i<c;i++){
    //  int p,q;
    //  scanf("%d%d",&p,&q);p--;q--;
        int p=A[i];
        int q=B[i];
        p=FIND(p);q=FIND(q);if(p==q)continue;
        int q1=pos[p];
        int q2=pos[q];
        int at=query(0,524287,min(q1,q2),max(q1,q2),1);
    //  if(at<0||at>999999)while(1);
        int lca=rev[at];
        if(p<0||q<0||lca<0)while(1);
        add(L[p],1,0);
        add(L[lca],-1,0);
        add(L[q],1,1);
        add(L[lca],-1,1);
    }
    bool ok=true;
    for(int i=0;i<a;i++){
        if(UF[i]>=0)continue;
        int up=sum(L[i],R[i],0);
        int down=sum(L[i],R[i],1);
        if(up&&down)ok=false;
    }
    if(ok)printf("Yes\n");
    else printf("No\n");
}