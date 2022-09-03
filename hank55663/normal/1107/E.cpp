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
LL dp[105][105][105];
char c[105];
LL point[105];
LL DP(int l,int r,int cnt){
    if(l>r)return point[cnt];
    if(dp[l][r][cnt]!=-1)return dp[l][r][cnt];
    if(c[r-1]==c[r])return dp[l][r][cnt]=DP(l,r-1,cnt+1);
    dp[l][r][cnt]=DP(l,r-1,0)+point[cnt+1];
    for(int i=l;i<r;i++){
        if(c[i]==c[r]&&c[i+1]!=c[r]){
            dp[l][r][cnt]=max(dp[l][r][cnt],DP(l,i,cnt+1)+DP(i+1,r-1,0));
        }
    }
   // printf("%d %d %d %d\n",l,r,cnt,dp[l][r][cnt]);
    return dp[l][r][cnt];
}
int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",c);
    for(int i=1;i<=n;i++){
        scanf("%lld",&point[i]);
        for(int j=1;j<i;j++){
           point[i]=max(point[i],point[j]+point[i-j]);
        }
      //  printf("%lld ",point[i]);
    }
    MEMS(dp);
    printf("%lld\n",DP(0,n-1,0));
}