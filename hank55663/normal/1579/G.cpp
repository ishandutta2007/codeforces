#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define MXN 1005
int dp[10005][2005];
int pre[10005];
void solve(){
    int n;
    scanf("%d",&n);
    int a[10005];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        pre[i]=pre[i-1]+a[i];
    }    
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=2000;j++)dp[i][j]=1e9;
    }
    dp[1][0]=a[1];
    for(int i=2;i<=n;i++){
        for(int j=0;j<=2000;j++){
            if(j+a[i]<=2000){
                dp[i][j+a[i]]=min(dp[i][j+a[i]],max(j+a[i],dp[i-1][j]));
            }
            if(j-a[i]>=0){
                dp[i][j-a[i]]=min(dp[i][j-a[i]],dp[i-1][j]);
            }
            else{
                dp[i][0]=min(dp[i][0],dp[i-1][j]+a[i]-j);
            }
        }
    }
    int ans=1e9;
    for(int j=0;j<=2000;j++)ans=min(ans,dp[n][j]);
    printf("%d\n",ans);
}
int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        //cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*

*/