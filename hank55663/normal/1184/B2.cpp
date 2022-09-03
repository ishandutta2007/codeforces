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
vector<int> v[1005];
int match[1005];
int vis[1005];
bool dfs(int x){
    if(vis[x])return false;
    vis[x]=1;
    for(auto it:v[x]){
        if(match[it]==-1||dfs(match[it])){
            match[it]=x;
            return true;
        }
    }
    return false;
}
int max_match(int n){
    int res=0;
    MEMS(match);
    for(int i = 0;i<n;i++){
        MEM(vis);
        if(dfs(i)){
            res++;
        }
    }
    return res;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int dis[105][105];
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++)
            dis[i][j]=1e9;
        dis[i][i]=0;
    }
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        dis[x][y]=dis[y][x]=1;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            for(int k = 1;k<=n;k++){
                dis[j][k]=min(dis[j][i]+dis[i][k],dis[j][k]);
            }
        }
    }
    int s,b,k,h;
    scanf("%d %d %d %d",&s,&b,&k,&h);
    int x[1005],a[1005],f[1005];
    for(int i = 0;i<s;i++){
        scanf("%d %d %d",&x[i],&a[i],&f[i]);
    }
    int x2[1005],d[1005];
    for(int i = 0;i<b;i++){
        scanf("%d %d",&x2[i],&d[i]);
    }
    for(int i=0;i<s;i++){
        for(int j=0;j<b;j++){
            if(dis[x[i]][x2[j]]<=f[i]&&d[j]<=a[i]){
                v[i].pb(j);
              //  printf("!%d %d\n",i,j);
            }
        }
    }
    int res=max_match(s);
    printf("%lld\n",min((LL)res*k,(LL)s*h));
}