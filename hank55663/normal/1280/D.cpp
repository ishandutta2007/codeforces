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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
pll dp[3005][3005];
int Size[3005];
LL val[3005];
vector<int> v[3005];
void dfs(int x,int f){
    Size[x]=1;
    dp[x][1]=mp(0,val[x]);
    pll tmp[3005];
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            for(int i = 0;i<=Size[x]+Size[it];i++)tmp[i]=mp(0,-1e18);
            for(int i = 1;i<=Size[x];i++){
                for(int j = 1;j<=Size[it];j++){
                    tmp[i+j]=max(tmp[i+j],mp(dp[x][i].x+dp[it][j].x+(dp[it][j].y>0),dp[x][i].y));
                    tmp[i+j-1]=max(tmp[i+j-1],mp(dp[x][i].x+dp[it][j].x,dp[x][i].y+dp[it][j].y));
                }
            }
            Size[x]+=Size[it];
            for(int i = 1;i<=Size[x];i++){
                dp[x][i]=tmp[i];
            }
        }
    }
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        int b[3005],w[3005];
        for(int i = 1;i<=n;i++)scanf("%d",&b[i]);
        for(int i = 1;i<=n;i++)scanf("%d",&w[i]),val[i]=w[i]-b[i];
        for(int i = 1;i<=n;i++)v[i].clear();
        for(int i = 1;i<n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            v[x].pb(y);
            v[y].pb(x);
        }
        dfs(1,0);
        printf("%d\n",dp[1][m].x+(dp[1][m].y>0));
    }
}
/*
int main(){

"RGGGGRRRRG", "RG"
}*/