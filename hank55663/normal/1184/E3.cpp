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
#define MXN 10005
#define less Less
int f[100005];
vector<pii> v[100005];
int par[100005][20];
int val[100005][20];
int dis[100005];
vector<pii> go[100005];
void dfs(int x,int f){
    dis[x]=dis[f]+1;
    for(auto it:v[x]){
        if(it.x!=f){
            par[it.x][0]=x;
            val[it.x][0]=it.y;
            dfs(it.x,x);
        }
    }
}
void build(int n){
    for(int i =1;i<20;i++){
        for(int j = 1;j<=n;j++){
            par[j][i]=par[par[j][i-1]][i-1];
            val[j][i]=max(val[par[j][i-1]][i-1],val[j][i-1]);
        }
    }
}
map<pii,int> findindex;
int ans[1000005];
vector<int> Erase[100005];
multiset<int> dfs2(int x,int f){
    multiset<int> tmp;
    for(auto it:go[x]){
        Erase[it.y].pb(it.x);
        tmp.insert(it.x);
    }

    for(auto it:v[x]){
        if(it.x!=f){
            auto s=dfs2(it.x,x);
            if(s.size())
            ans[findindex[mp(x,it.x)]]=*s.begin();
            else
            ans[findindex[mp(x,it.x)]]=1e9;
            if(tmp.size()<s.size())
            swap(s,tmp);
            for(auto it:s)
            tmp.insert(it);
        }
    }
    for(auto it:Erase[x]){
        tmp.erase(tmp.find(it));
    }
    
    return tmp;
}

int lca(int x,int y,int value){
   // printf("%d %d\n",x,y);
    int dx=dis[x];
    int dy=dis[y];
    int tx=x;
    int ty=y;
    if(dx>dy){
        swap(dx,dy);
        swap(x,y);
        swap(tx,ty);
    }
    int xx=dy-dx;
    int res=0;
    for(int i = 19;i>=0;i--){
        if(xx&(1<<i)){
            res=max(res,val[y][i]);
            //printf("%d %d %d\n",y,i,val[y][i]);
            y=par[y][i];
        }
    }
    go[tx].pb(mp(value,x));
    go[ty].pb(mp(value,y));
    if(x==y)return res;
    for(int i = 19;i>=0;i--){
        if(par[x][i]!=par[y][i]){
            res=max(res,val[x][i]);
            res=max(res,val[y][i]);
            x=par[x][i];
            y=par[y][i];
        }
    }
    res=max(res,val[x][0]);
    res=max(res,val[y][0]);
    go[tx].pb(mp(value,par[x][0]));
    go[ty].pb(mp(value,par[x][0]));
    return res;
}
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
pair<pair<int,pii>,int> p[1000005];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++)
    f[i]=i;
    for(int i =0;i<m;i++){
        int a,b,e;
        scanf("%d %d %d",&a,&b,&e);
        p[i]=mp(mp(e,mp(a,b)),i);
    }
    sort(p,p+m);
    vector<pair<pair<int,pii>,int> > no;
    for(int i = 0;i<m;i++){
        auto pp=p[i].x;
        int x=Find(pp.y.x);
        int y=Find(pp.y.y);
        if(x!=y){
            f[x]=y;
            v[pp.y.x].pb(mp(pp.y.y,pp.x));
            v[pp.y.y].pb(mp(pp.y.x,pp.x));
            findindex[pp.y]=p[i].y;
            findindex[mp(pp.y.y,pp.y.x)]=p[i].y;
        }
        else{
            no.pb(p[i]);
        }
     //   printf("%d\n",i);
    }
    dfs(1,0);
    build(n);
   
    for(auto it:no){
        int index=it.y;
        auto pp=it.x;
        int x=pp.y.x;
        int y=pp.y.y;
        ans[index]=lca(x,y,pp.x);
    }//printf("?\n");
    dfs2(1,0); 
    for(int i = 0;i<m;i++){
        printf("%d\n",ans[i]);
    }
}