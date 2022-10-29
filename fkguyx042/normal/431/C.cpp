#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>

#define LL __int64
#define MOD 1000000007
#define mt(a,b) memset(a,b,sizeof(a))
using namespace std;

LL dp[123][2];

int main(){
    int n,k,d;
    while(~scanf("%d%d%d",&n,&k,&d)){
        mt(dp,0);
        dp[0][0] = 1;
        for(int i=0;i<n;i++){
            for(int j=1;j<=k;j++){
                if(i+j>n) continue;

                if(j<d) dp[i+j][0] += dp[i][0];
                else    dp[i+j][1] += dp[i][0];

                dp[i+j][1] += dp[i][1];

                dp[i+j][0] %= MOD;
                dp[i+j][1] %= MOD;
            }
        }

        printf("%I64d\n",dp[n][1]);

    }
    return 0;
}