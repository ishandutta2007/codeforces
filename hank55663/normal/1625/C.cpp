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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int dp[505][505];
void solve(){
    int n,l,k;
    scanf("%d %d %d",&n,&l,&k);
    int d[505];
    int a[505];
    for(int i = 0;i<n;i++)scanf("%d",&d[i]);
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    for(int i = 0;i<=n+1;i++){
        for(int j  =0;j<=n+1;j++)dp[i][j]=1e9+7;
    }
    d[n]=l;
    dp[0][1]=0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            for(int k =0;k<j;k++){
                dp[j][i+1]=min(dp[j][i+1],dp[k][i]+(d[j]-d[k])*a[k]);
            }
        }
    }
    int ans=1e9+7;
    for(int i = n-k+1;i<=n+1;i++){
        ans=min(ans,dp[n][i]);
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;0000;
   // scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}