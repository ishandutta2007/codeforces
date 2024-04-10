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
int main(){
    int n,r;
    scanf("%d %d",&n,&r);
    int dp[1005];
    fill(dp,dp+n+1,1e9);
    vector<pii> v;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(x==1){
            v.pb(mp(max(1,i-r+1),min(n,i+r-1)));
        }
    }
    dp[0]=0;
    for(auto it:v){
        for(int j=it.x;j<=it.y;j++){
            dp[j]=min(dp[it.x-1]+1,dp[j]);
        }
    }
    if(dp[n]==1e9)
    printf("-1\n");
    else
    printf("%d\n",dp[n]);
}