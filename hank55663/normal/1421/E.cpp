#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL dp[200005][3][2];
void solve(){
    int n;
    scanf("%d",&n);
    int a[200005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n==1){
        printf("%d\n",a[1]);
        return;
    }

    dp[0][0][1]=-1e18;
    for(int j = 0;j<3;j++){
        for(int k = 0;k<2;k++){
            dp[0][j][k]=-1e18;
        }
    }
        dp[0][0][0]=0;
    for(int i = 1;i<=n;i++){
        for(int j =0;j<3;j++){
            for(int k = 0;k<2;k++){
                dp[i][j][k]=-1e18;
            }
        }
        for(int j = 0;j<3;j++){
            for(int k =0;k<2;k++){
                dp[i][(j+1)%3][k]=max(dp[i][(j+1)%3][k],dp[i-1][j][k]+a[i]);
                dp[i][(j+2)%3][k]=max(dp[i][(j+2)%3][k],dp[i-1][j][k]-a[i]);
            }
            if(i>=2){
                dp[i][(j+1)%3][1]=max(dp[i][(j+1)%3][1],dp[i-2][j][0]-a[i-1]-a[i]);
                dp[i][(j+2)%3][1]=max(dp[i][(j+2)%3][1],dp[i-2][j][0]+a[i-1]+a[i]);
            }
        }
    }
    printf("%lld\n",dp[n][1][1]);//max(Max[n-1][1][0]+a[n],max(Max[n-1][1][1],head[n-1][1])-a[n]));
}



int main(){
    int t=1;
 //   scanf("%d",&t);
   
    while(t--){
        solve();
    }
}
/*
5 0 5
10 0
-10 0
-20 10
0 30
20 10
*/