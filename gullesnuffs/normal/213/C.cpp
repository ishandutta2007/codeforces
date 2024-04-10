#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cassert>
#include <map>
#include <string>
#include <set>
#include <cstring>

using namespace std;

int a[305][305];
int dp[2][305][305];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i < n; ++i)
        for(int j=0; j < n; ++j)
            scanf("%d", a[i]+j);
    bool read=0, write=1;
    dp[write][0][0]=a[0][0];
    for(int i=1; i < n; ++i){
        dp[write][i][0]=dp[write][i-1][0]+a[0][i];
        for(int j=1; j <= i; ++j)
            dp[write][i][j]=dp[write][i][j-1];
    }
    for(int b=1; b < n; ++b){
        read^=1;
        write^=1;
        for(int i=0; i < n; ++i)
            for(int j=0; j <= i; ++j){
                dp[write][i][j]=dp[read][i][j];
                dp[write][i][j] += a[b][i];
                if(i != j)
                    dp[write][i][j] += a[b][j];
            }
        for(int i=0; i < n; ++i)
            for(int j=0; j <= i; ++j){
                if(j < i && dp[write][i][j+1] < dp[write][i][j]+(j < i-1?a[b][j+1]:0))
                    dp[write][i][j+1]=dp[write][i][j]+(j < i-1?a[b][j+1]:0);
            }
        for(int i=0; i < n; ++i)
            for(int j=0; j <= i; ++j){
                if(i < n-1 && dp[write][i+1][j] < dp[write][i][j]+a[b][i+1])
                    dp[write][i+1][j]=dp[write][i][j]+a[b][i+1];
                if(i == j && i < n-1 && dp[write][i+1][j+1] < dp[write][i][j]+a[b][i+1])
                    dp[write][i+1][j+1]=dp[write][i][j]+a[b][i+1];
            }
    }
    printf("%d\n", dp[write][n-1][n-1]);
    return 0;
}