#include<bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
vector<int> v[100005];
int p[100005];
int Size[100005];
int h[100005];
int ok;
int g[100005],b[100005];
void dfs(int x,int f){
    Size[x]=p[x];
    int sumg=0,sumb=0;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            Size[x]+=Size[it];
            sumg+=g[it];
            sumb+=b[it];
        }
    }
    g[x]=(h[x]+Size[x])/2;
    b[x]=Size[x]-g[x];
    if((h[x]+Size[x])&1)ok=0;
    //printf("%d %d %d %d %d %d\n",x,sumg,sumb,g[x],b[x],ok);
    if(g[x]<sumg||sumg+sumb+p[x]!=Size[x]||g[x]<0||b[x]<0){
        ok=0;
    }
}/*
void dfs2(int x,int f){
    int totp=Size[x]-p[x];
    int sumg=0
}*/
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i = 1;i<=n;i++)scanf("%d",&p[i]);
        for(int i = 1;i<=n;i++)scanf("%d",&h[i]);
        for(int i = 1;i<=n;i++)v[i].clear();
        for(int i = 1;i<n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            v[x].pb(y);
            v[y].pb(x);
        }
        ok=1;
        dfs(1,0);
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
}