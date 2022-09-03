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
int mod=998244353;
LL dp[1005][2005][4];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    dp[1][1][0]=dp[1][1][3]=1;
    dp[1][2][1]=dp[1][2][2]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j-1][3])%mod;
            dp[i][j][1]=(dp[i-1][j-1][0]+dp[i-1][j][1]+(j==1?0:dp[i-1][j-2][2])+dp[i-1][j-1][3])%mod;
            dp[i][j][2]=(dp[i-1][j-1][0]+dp[i-1][j][2]+(j==1?0:dp[i-1][j-2][1])+dp[i-1][j-1][3])%mod;
            dp[i][j][3]=(dp[i-1][j][3]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j-1][0])%mod;
           // printf("%d %d ",i,j);
            /*for(int kk=0;kk<4;kk++)
            printf("%d ",dp[i][j][kk]);
            printf("\n");*/
        }
    }
    printf("%lld\n",(dp[n][k][0]+dp[n][k][1]+dp[n][k][2]+dp[n][k][3])%mod);
    return 0;
}