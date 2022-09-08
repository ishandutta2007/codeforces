#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
int f[200005];
vector<int> v[200005];
int vis[200005];
pii p[200005];
int dis[200005];
void dfs(int x,int ff){
    vis[x]=1;
    f[x]=ff;
    dis[x]=dis[ff]+1;
    for(auto it:v[x]){
        if(!vis[it]){
            dfs(it,x);
        }
    }
}
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++)v[i].clear(),vis[i]=0;
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    set<int> s;
    vector<pii> edge;
    for(int i =0;i<m;i++){
        if(f[p[i].x]==p[i].y||f[p[i].y]==p[i].x);
        else{
            edge.pb(p[i]);
            s.insert(p[i].x);
            s.insert(p[i].y);
        }
    }
    if(s.size()==3&&m==n+2){
        int a=edge[0].x;
        if(dis[edge[0].y]>dis[a]){
            f[edge[0].y]=a;
        }else f[a]=edge[0].y;
        //printf("?\n");
    }
    for(int i = 0;i<m;i++){
        if(f[p[i].x]==p[i].y||f[p[i].y]==p[i].x)printf("1");
        else{
            printf("0");
        }
    }
    printf("\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve();
    }
   // printf("%d\n",s.size());
}

/*
3 5 7 8
4999850001
6
1 8 4 6 8 10
2 1
3 1
4 3
5 4
6 3
1 2 1
1 3 1
3 4 1
4 5 1
3 6 1
*/