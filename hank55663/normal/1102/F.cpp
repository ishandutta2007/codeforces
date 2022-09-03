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
#define EPS 1e-7
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define Line pair<pii,pii> 
typedef long long LL;
#define hash Hash
vector<pii> v[20];
int dp[20][1<<16][20];
int DP(int a,int k,int b){
    if(dp[a][k][b]!=-1)return dp[a][k][b];
    if(a==b)return 0;
    dp[a][k][b]=0;
    for(auto it:v[b]){
        if(k&(1<<it.x)){
            dp[a][k][b]=max(dp[a][k][b],min(DP(a,k-(1<<b),it.x),it.y));
        }
    }
    return dp[a][k][b];
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[20][10005];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int dis[20][20];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int Min=1e9;
            for(int k=0;k<m;k++){
                Min=min(Min,abs(a[i][k]-a[j][k]));
            }
            v[i].pb(mp(j,Min));
            v[j].pb(mp(i,Min));
           // printf("%d %d %d\n",i,j,Min);
        }
        for(int j=0;j<n;j++){
            int Min=1e9;
            for(int k=0;k<m-1;k++){
                Min=min(Min,abs(a[i][k]-a[j][k+1]));
            }
            dis[i][j]=Min;
        }
    }
    MEMS(dp);
    for(int i=0;i<n;i++){
        dp[i][1<<i][i]=1e9;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
         //   printf("%d %d %d\n",i,j,DP(i,(1<<n)-1,j));
            ans=max(ans,min(DP(i,(1<<n)-1,j),dis[i][j]));
        }
    }
    printf("%d\n",ans);
}