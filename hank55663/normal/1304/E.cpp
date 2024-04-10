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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 100005
int dep[100005];
int p[20][100005];
vector<int> v[100005];
void dfs(int x,int f){
    p[0][x]=f;
    dep[x]=dep[f]+1;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
        }
    }
}
void build(int n){
    for(int i = 1;i<20;i++){
        for(int j = 1;j<=n;j++){
            p[i][j]=p[i-1][p[i-1][j]];
        }
    }
}
int lca(int a,int b){
    if(dep[a]<dep[b]){
        swap(a,b);
    }
    int dis=dep[a]-dep[b];
  //  printf("%d %d %d?\n",dep[a],dep[b],p);
    for(int i = 0;i<20;i++){
        if(dis&(1<<i)){
            a=p[i][a];
        }
    }
 //   printf("%d %d\n",a,b);
    if(a==b)return a;
    for(int i = 19;i>=0;i--){
        if(p[i][a]!=p[i][b]){
            a=p[i][a];
            b=p[i][b];
        }
    }
    return p[0][a];
}
int dis(int x,int y){
    int z=lca(x,y);
   // printf("%d %d %d\n",x,y,z);
    return dep[x]+dep[y]-dep[z]*2;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    build(n);
    int q;
    scanf("%d",&q);
    while(q--){
        int x,y,a,b,k;
        int ok=0;
        scanf("%d %d %d %d %d",&x,&y,&a,&b,&k);
        int d=dis(a,b);
      //  printf("%d\n",d);
        if(d<=k&&(d-k)%2==0)ok=1;
        d=dis(a,x)+dis(y,b)+1;
      //  printf("%d\n",d);
        if(d<=k&&(d-k)%2==0)ok=1;
        d=dis(a,y)+dis(b,x)+1;
      //  printf("%d\n",d);
        if(d<=k&&(d-k)%2==0)ok=1;
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
}
/*
6 10
1 1 0 0 0 0 0 0 0 0 
1 1 1 1 0 0 0 0 0 0 
0 0 1 1 0 0 0 0 0 0 
2 2 3 3 0 0 0 0 0 0 
0 0 3 3 4 4 0 0 0 0 

{1}
{1}
{1000000000}
{1000000000}
1

1000000000 
1000
{1000}
{1000000000}
*/