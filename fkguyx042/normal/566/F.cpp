#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#define LL long long
#define INF 0x3f3f3f3f

using namespace std;

int dp[1111111];

int main()
{
    memset(dp,0,sizeof(dp));
    int n,x,mm = 0,i,j;
    scanf("%d",&n);
    for(i = 0; i < n; ++i)
    {
        scanf("%d",&x);
        mm = max(mm,dp[x]+1);
        for(j = 2; j*x <= 1000000; ++j)
        {
            dp[j*x] = max(dp[j*x],dp[x]+1);
        }
        dp[x]++;
    }
    printf("%d\n",mm);
    return 0;
}