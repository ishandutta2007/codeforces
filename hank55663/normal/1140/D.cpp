#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<double,null_type,less<double>,rb_tree_tag,tree_order_statistics_node_update> set_t;
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
#define MXN 3000
LL dp[505][505];
int n;
LL DP(int l,int r){
    if(l%n+1==r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    dp[l][r]=1e18;
    for(int i = l+1;i!=r;i=i%n+1){
        dp[l][r]=min(dp[l][r],l*r*i+DP(l,i)+DP(i,r));
    }
    return dp[l][r];
}
int main(){
    scanf("%d",&n);
    LL ans=1e18;
    MEMS(dp);
    for(int i = 2;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ans=min(ans,i*j+DP(1,i)+DP(i,j)+DP(j,1));
        }
    }
    printf("%lld\n",ans);
}