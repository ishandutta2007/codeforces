#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cassert>
#include <map>
#include <string>
#include <set>
#define MOD 1000000007LL

using namespace std;

char s[2005];
long long dp[2005][5005];
long long sum[2005][5005];
int n, k;

int main()
{
    scanf("%d%d%s", &n, &k, s);
    for(int i=0; i <= n; ++i)
        for(int j=0; j <= k; ++j)
            dp[i][j]=0;
    for(int i=0; i <= n; ++i)
        for(int j=0; j <= k; ++j)
            sum[i][j]=0;
    sum[0][0]=0;
    dp[0][0]=1;
    for(int i=0; i < n; ++i)
        for(int j=0; j <= k; ++j){
            long long diff=s[i]-'a';
            sum[i][j]=(sum[i][j]+dp[i][j])%MOD;
            dp[i+1][j]=(dp[i+1][j]+sum[i][j]*diff)%MOD;
            sum[i+1][j]=(sum[i+1][j]+sum[i][j])%MOD;
            int last=0;
            for(int m=0; i+m < n && j+(m+1)*(n-i-m) <= k; ++m){
                last=m;
                long long diff='z'-s[i+m];
                dp[i+m+1][j+(m+1)*(n-i-m)]=(dp[i+m+1][j+(m+1)*(n-i-m)]+dp[i][j]*(diff))%MOD;
            }
            for(int m=n-i-1; m > last && j+(m+1)*(n-i-m) <= k; --m){
                long long diff='z'-s[i+m];
                dp[i+m+1][j+(m+1)*(n-i-m)]=(dp[i+m+1][j+(m+1)*(n-i-m)]+dp[i][j]*(diff))%MOD;
            }
            /*diff=s[i+1]-'a';
            dp[i+1][j]=(dp[i+1][j]+dp[i][j]*(diff))%MOD;*/
        }
    long long ans=(sum[n][k]+dp[n][k])%MOD;
    printf("%I64d\n", ans);
    return 0;
}