#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=1e9+7;
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int ans[100005];
    fill(ans,ans+m+1,-1);
    ans[0]=0;
    for(int i = 1;i<=n;i++){
        int dp[100005];
        fill(dp,dp+m+1,-1);
        int t;
        scanf("%d",&t);
        if(t==1){
            LL x,y;
            scanf("%lld %lld",&x,&y);
            x=(x+99999)/100000;
            for(int i = 0;i+x<=m;i++){
                if(ans[i]!=-1){
                    dp[i+x]=y-1;
             //       printf("%d ",i+x);
                }
                else if(dp[i]>0){
                    dp[i+x]=dp[i]-1;
           //         printf("%d ",i+x);
                }
            }
         //   printf("\n");
        }
        else{
            LL x,y;
            scanf("%lld %lld",&x,&y);
            for(int i = 0;(i*x+99999)/100000<=m;i++){
                int yy=(i*x+99999)/100000;
                if(ans[i]!=-1){
                    dp[yy]=max(y-1,dp[yy]*1ll);
                }
                else if(dp[i]>0){
                    dp[yy]=max(dp[i]-1,dp[yy]);
                }
            }
        }
        for(int j=0;j<=m;j++){
            if(ans[j]==-1){
                if(dp[j]!=-1)ans[j]=i;
            }
        }
        //  for(int i=1;i<=m;i++){
      //  printf("%d ",ans[i]);
  //  }
   // printf("\n");
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}