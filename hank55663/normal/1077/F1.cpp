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
#define hash Hash
#define LL long long
LL dp[5005][5005];
int main(){
    int n,k,x;
    scanf("%d %d %d",&n,&k,&x);
    MEM(dp);
    int a[5005];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    deque<pll> q[5005];
    q[0].pb(mp(0,0));
    for(int i=1;i<=n;i++){
        dp[i][0]=-1e18;
        for(int j=1;j<=i;j++){
            if(q[j-1].front().x<i-k)q[j-1].pop_front();
            assert(q[j-1].size());
            dp[i][j]=q[j-1].front().y+a[i];//max(dp[i-1][j-1]~dp[i-k][j-1])+a[i];
         //   printf("%lld ",dp[i][j]);
        }
       // printf("\n");
        for(int j=0;j<=i;j++){
            while(!q[j].empty()&&dp[i][j]>=q[j].back().y)q[j].pop_back();
            q[j].pb(mp(i,dp[i][j]));
        }
    }
    LL ans=-1;
    for(int i=n-k+1;i<=n;i++)
    ans=max(ans,dp[i][x]);
    printf("%lld\n",ans);
}