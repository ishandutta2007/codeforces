#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
//#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
typedef long long LL;
vector<pii> v[100005];
int f[100005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int pa[100005][20];
LL d[100005];
int dd[100005];
void dfs(int x,int f){
    pa[x][0]=f;
    dd[x]=dd[f]+1;
    for(auto it:v[x]){
        if(it.x!=f){
            d[it.x]=d[x]+it.y;
            dfs(it.x,x);
        }
    }
}
int lca(int x,int y){
    if(dd[x]>dd[y]){
        swap(x,y);
    }
    for(int i=19;i>=0;i--){
        if(dd[x]<=dd[pa[y][i]])
            y=pa[y][i];
    }
    if(x==y)return x;
    for(int i=19;i>=0;i--){
        if(pa[x][i]!=pa[y][i]){
            x=pa[x][i];
            y=pa[y][i];
        }
    }
    return pa[x][0];
}
typedef long long LL;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    pair<int,pii> p[100005];
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        p[i]=mp(w,mp(u,v));
    }
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    sort(p,p+m);
    vector<pair<int,pii> >edge;
    set<int> node;
    for(int i=0;i<m;i++){
        int x=p[i].y.x;
        int y=p[i].y.y;
        int w=p[i].x;
        int fx=Find(x);
        int fy=Find(y);
        if(fx!=fy){
            f[fx]=fy;
            v[x].pb(mp(y,w));
            v[y].pb(mp(x,w));
        }
        else{
            edge.pb(p[i]);
            node.insert(x);
            node.insert(y);
        }
    }
    dfs(1,0);
    for(int i=1;i<20;i++){
        for(int j=1;j<=n;j++){
            pa[j][i]=pa[pa[j][i-1]][i-1];
        }
    }
    int transform[45];
    int inv[100005];
    int index=0;
    for(auto it:node){
        transform[index]=it;
        inv[it]=index++;
    }
    LL dis[45][45];
    for(auto it:node){
        for(auto it2:node){
            dis[inv[it]][inv[it2]]=d[it]+d[it2]-2*d[lca(it,it2)];
        }
    }
    for(auto it:edge){
        int x=inv[it.y.x];
        int y=inv[it.y.y];
        int w=it.x;
        dis[x][y]=min(dis[x][y],(LL)w);
        dis[y][x]=min(dis[y][x],(LL)w);
    }
    for(int i=0;i<index;i++){
        for(int j=0;j<index;j++)
            for(int k=0;k<index;k++){
                dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
            }
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int a,b;
        scanf("%d %d",&a,&b);
        LL dis1[45];
        LL dis2[45];
        for(int i=0;i<index;i++){
            dis1[i]=d[a]+d[transform[i]]-2*d[lca(transform[i],a)];
            dis2[i]=d[b]+d[transform[i]]-2*d[lca(transform[i],b)];
        }
        LL ans=d[a]+d[b]-2*d[lca(a,b)];
        for(int i=0;i<index;i++)
            for(int j=0;j<index;j++){
                ans=min(ans,dis1[i]+dis2[j]+dis[i][j]);
               // printf("%d %d %d %d %d\n",transform[i],transform[j],dis1[i],dis2[j],dis[i][j]);
            }
        printf("%lld\n",ans);
    }
    return 0;
}