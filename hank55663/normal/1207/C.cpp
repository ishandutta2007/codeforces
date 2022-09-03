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
#define pdd pair<double,double>
#define cpdd const pdd
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,a,b;
        scanf("%d %d %d",&n,&a,&b);
        char c[200005];
        scanf("%s",c+1);
        LL dp[200005][2];
        dp[0][0]=b,dp[0][1]=1e18;
        for(int i = 1;i<=n;i++){
            if(c[i]=='1'||c[i+1]=='1'){
                dp[i][0]=1e18;
                dp[i][1]=min(dp[i-1][0]+a+a+b+b,dp[i-1][1]+a+b+b);
            }
            else{
                dp[i][0]=min(dp[i-1][0]+a+b,dp[i-1][1]+a+a+b);
                dp[i][1]=min(dp[i-1][0]+a+a+b+b,dp[i-1][1]+a+b+b);
            }
           // printf("%lld %lld\n",dp[i][0],dp[i][1]);
        }
        printf("%lld\n",dp[n][0]);
    }
}
/*
100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
24
 */