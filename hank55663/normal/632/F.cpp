#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int a[2505][2505];
vector<pii> v[2505];
int f[2505];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int p[2505][13];
int val[2505][13];
int dis[2505];
void dfs(int x,int f){
    dis[x]=dis[f]+1;
    for(auto it:v[x]){
        if(it.x!=f){
            dfs(it.x,x);
            val[it.x][0]=it.y;
            p[it.x][0]=x;
        }
    }
}
void build(int n){
    for(int i = 1;i<13;i++){
        for(int j = 1;j<=n;j++){
            p[j][i]=p[p[j][i-1]][i-1];
            val[j][i]=max(val[j][i-1],val[p[j][i-1]][i-1]);
        }
    }
}
int lca(int x,int y){
    int res=0;
    if(dis[x]>dis[y]){
        swap(x,y);
    }
    int d=dis[y]-dis[x];
    for(int i = 0;i<13;i++){
        if(d&(1<<i)){
            res=max(res,val[y][i]);
            y=p[y][i];
        }
    }
    if(x==y)return res;
    for(int i = 12;i>=0;i--){
        if(p[x][i]!=p[y][i]){
            res=max(res,val[x][i]);
            res=max(res,val[y][i]);
            x=p[x][i];
            y=p[y][i];
        }
    }
    res=max(res,val[x][0]);
    res=max(res,val[y][0]);
    return res;
}
int main(){
    vector<pair<int,pii> > E;
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
        f[i]=i;
    }
    for(int i = 1;i<=n;i++){
        if(a[i][i]){
            printf("NOT MAGIC\n");
            return 0;
        }
        for(int j = i+1;j<=n;j++){
            if(a[i][j]!=a[j][i]){
                printf("NOT MAGIC\n");
                return 0;
            }
            E.pb(mp(a[i][j],mp(i,j)));
        }
    }
    sort(E.begin(),E.end());
    for(auto it:E){
        int a=Find(it.y.x),b=Find(it.y.y);
        if(a!=b){
            f[a]=b;
            v[it.y.x].pb(mp(it.y.y,it.x));
            v[it.y.y].pb(mp(it.y.x,it.x));
        }
    }
    dfs(1,0);
    build(n);
    for(int i = 1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(lca(i,j)<a[i][j]){
                printf("NOT MAGIC\n");
                return 0;
            }
        }
    }
    printf("MAGIC\n");
}