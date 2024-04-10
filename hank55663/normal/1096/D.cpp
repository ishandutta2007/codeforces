
#pragma GCC optimize("Ofast") 
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
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
int mod=998244353;
LL dp[100005][5];
int main(){
    int n;
    char c[100005];
    scanf("%d",&n);
    scanf("%s",c+1);
    int val[100005];
    for(int i=1;i<=n;i++)
    scanf("%d",&val[i]);
    char hard[10]="hard";

    MEM(dp);
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        fill(dp[i],dp[i]+5,1e18);
        for(int j=0;j<4;j++){
            if(c[i]==hard[j]){
                dp[i][j+1]=min(dp[i-1][j],dp[i-1][j+1]);
                dp[i][j]=min(dp[i-1][j]+val[i],dp[i][j]);
            }
            else{
                dp[i][j]=min(dp[i-1][j],dp[i][j]);
            }
        }
    }
    printf("%lld\n",min(min(dp[n][3],dp[n][0]),min(dp[n][1],dp[n][2])));
}