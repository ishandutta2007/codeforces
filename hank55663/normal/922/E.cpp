#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
LL dp[1005][10005];
int main(){
    LL n,w,b,x;
    scanf("%lld %lld %lld %lld",&n,&w,&b,&x);
    for(int i = 0;i<=n;i++)
        for(int j =0;j<=10000;j++)
            dp[i][j]=-1e18;
    dp[0][0]=w;
    LL c[1005],cost[1005];
    for(int i=1;i<=n;i++)
        scanf("%lld",&c[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&cost[i]);
    for(int i=1;i<=n;i++){
        deque<pll> q;
        //dp[i][0] = w;
        //q.push_back(mp(dp[i][0],0));
        for(int j = 0 ; j <= 10000 ; j++){
            while(!q.empty()&&q.back().x<=dp[i-1][j]+cost[i]*j){
                q.pop_back();
            }
            q.push_back(mp(dp[i-1][j]+cost[i]*j,j));
            while(j-q.front().y>c[i])q.pop_front();
            dp[i][j] = q.front().x-cost[i]*j;
            if(dp[i][j]<0){
                dp[i][j]=-1e18;
            }
            else{
                dp[i][j]+=x;
                dp[i][j]=min(dp[i][j],w+b*j);
            }
           // printf("%lld %lld %lld ",q.front().x,q.front().y,dp[i][j]);
        }
      //  printf("\n");
    }
    for(int i = 10000;i>=0;i--){
        if(dp[n][i]>=0){
          //  printf("%d\n",dp[n][i]);
            printf("%d\n",i);
            break;
        }
    }
}