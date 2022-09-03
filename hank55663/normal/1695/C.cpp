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
#define index Index
#define MXN 1000000
int a[1005][1005];
int dp[1005][1005][2];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    if((n+m-1)%2){
        printf("No\n");
        return;
    }
    for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++){
            if(i==0&&j==0){
                dp[i][j][0]=dp[i][j][1]=a[i][j];
            }
            else if(i==0){
                dp[i][j][0]=dp[i][j-1][0]+a[i][j];
                dp[i][j][1]=dp[i][j-1][1]+a[i][j];
            }
            else if(j==0){
                 dp[i][j][0]=dp[i-1][j][0]+a[i][j];
                dp[i][j][1]=dp[i-1][j][1]+a[i][j];
            }
            else{
                dp[i][j][0]=min(dp[i-1][j][0],dp[i][j-1][0])+a[i][j];
                dp[i][j][1]=max(dp[i-1][j][1],dp[i][j-1][1])+a[i][j];
            }
        }
    }
    if(dp[n-1][m-1][1]>=0&&dp[n-1][m-1][0]<=0)printf("Yes\n");
    else printf("No\n");
}
int main(){
 //   srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);
    //int res=0;
   
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}