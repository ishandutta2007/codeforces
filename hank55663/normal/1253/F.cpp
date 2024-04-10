#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 300000
#define N 100005
vector<pii> v[100005];
vector<pll> vv[100005];
int f[100005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int p[100005][20];
LL val[100005][20];
int dis[100005];
void dfs(int x,int f){
    dis[x]=dis[f]+1;
    for(auto it:vv[x]){
        if(it.x!=f){
            p[it.x][0]=x;
            val[it.x][0]=it.y;
         //printf("%d %d\n",it.x,it.y);
            dfs(it.x,x);
        }
    }
}
void build(int n){
    for(int i=1;i<20;i++){
        for(int j=1;j<=n;j++){
            p[j][i]=p[p[j][i-1]][i-1];
            val[j][i]=max(val[j][i-1],val[p[j][i-1]][i-1]);
            //printf("%d ",p[j][i]);
        }
     //   printf("\n");
    }
}
LL query(int u,int v){
    LL res=0;
    if(dis[u]>dis[v])swap(u,v);
    int d=dis[v]-dis[u];
   // printf("%d %d %d\n",d,v,val[v][1]);
    for(int i =0;i<20;i++){
        if(d&(1<<i)){
            res=max(res,val[v][i]);
            v=p[v][i];
        }
    }
    if(u==v)return res;
    for(int i = 19;i>=0;i--){
        if(p[u][i]!=p[v][i]){
            res=max(res,val[u][i]);
            res=max(res,val[v][i]);
            u=p[u][i];
            v=p[v][i];
        }
    }
    res=max(res,val[u][0]);
    res=max(res,val[v][0]);
    return res;
}
int main(){
    int n,m,k,q;
    scanf("%d %d %d %d",&n,&m,&k,&q);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        v[a].pb(mp(b,c));
        v[b].pb(mp(a,c));
    }
    for(int i = 1;i<=k;i++)f[i]=i;
    priority_queue<pair<LL,pll>,vector<pair<LL,pll> >,greater<pair<LL,pll> > > pq;
    for(int i = 1;i<=k;i++){
        pq.push(mp(0,mp(i,i)));
    }
    pll dis[100005];
    MEMS(dis);
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        if(dis[p.y.x].x!=-1)continue;
        dis[p.y.x]=mp(p.x,p.y.y);
        for(auto it:v[p.y.x]){
            if(dis[it.x].x==-1){
                pq.push(mp(it.y+p.x,mp(it.x,p.y.y)));
            }
        }
    }
    vector<pair<LL,pii> > tmp; 
    for(int i = 1;i<=n;i++){
        for(auto it:v[i]){
            if(dis[i].y!=dis[it.x].y){
                tmp.pb(mp(dis[i].x+dis[it.x].x+it.y,mp(dis[i].y,dis[it.x].y)));
            }
        }
    }
    sort(tmp.begin(),tmp.end());
    for(auto it:tmp){
        int a=it.y.x,b=it.y.y;
        int fa=Find(a),fb=Find(b);
        if(fa!=fb){
            f[fa]=fb;
           // printf("%d %d %d\n",a,b,it.x);
            vv[it.y.x].pb(mp(it.y.y,it.x));
            vv[it.y.y].pb(mp(it.y.x,it.x));
        }
    }
    dfs(1,0);
    build(k);
    while(q--){
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%lld\n",query(a,b));
    }
}