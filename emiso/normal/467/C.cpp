#include <stdio.h>
#include <algorithm>

using namespace std;

long long dp[5050][5050],p[5050];

int main() {
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++) {
        scanf("%I64d",&p[i]);
    }

    for(int i=0;i<n;i++) {
        dp[i][0] = 0;
    }

    for(int i=1;i<=k;i++) {
        long long sum = 0;
        for(int j = n-m;j<n;j++) {
            sum += p[j];
        }
        for(int j = n-m; j >= 0; j--) {
            dp[j][i] = max(dp[j+1][i],dp[j+m][i-1] + sum);
            sum -= p[j+m-1];
            if(j) sum += p[j-1];
        }
    }
    printf("%I64d\n",dp[0][k]);
    return 0;
}