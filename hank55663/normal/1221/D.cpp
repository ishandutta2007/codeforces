#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 1500
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int n;
        scanf("%d",&n);
        LL a[300005],b[300005];
        for(int i = 0;i<n;i++){
            scanf("%lld %lld",&a[i],&b[i]);
        }
        LL dp[300005][3];
        dp[0][0]=0;
        dp[0][1]=b[0];
        dp[0][2]=b[0]*2;
        for(int i = 1;i<n;i++){
            dp[i][0]=dp[i][1]=dp[i][2]=1e18;
            for(int j = 0;j<3;j++){
                for(int k = 0;k<3;k++){
                    if(a[i-1]+k!=a[i]+j)
                    dp[i][j]=min(dp[i-1][k]+j*b[i],dp[i][j]);
                }
            }
           // printf("%d %d %d\n",dp[i][0],dp[i][1],dp[i][2]);
        }
        printf("%lld\n",min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2])));
    }
    return 0;
}
/*
5 5
 _ _ _ _ _
|_ _  |_  |
|  _| |  _|
| |_   _| |
|    _ _  |
|_|_ _ _|_|

*/