#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cassert>
#include <map>
#include <string>
#include <set>

using namespace std;

int remN, n;
int a[2505];
int nextFixed[2505];
int dp[2505];

int main()
{
    scanf("%d%d", &n, &remN);
    for(int i=0; i < n; ++i){
        scanf("%d", a+i);
    }
    long long Min=-1, Max=2000000005;
    while(Max-Min > 1){
        long long test=(Max+Min)/2;
        int need=0;
        for(int j=0; j <= n; ++j)
            dp[j]=j;
        for(int now=0; now < n; ++now){
            int i;
            for(i=now+1; i < n; ++i){
                if(a[i] == a[now] || (test && (abs(a[i]-a[now])+test-1)/test <= (i-now))){
                    if(dp[i] > dp[now]+i-now-1)
                        dp[i]=dp[now]+i-now-1;
                }
            }
        }
        int best=n;
        for(int j=0; j <= n; ++j)
            if(dp[j]+(n-j-1) < best)
                best=dp[j]+(n-j-1);
        if(best > remN)
            Min=test;
        else
            Max=test;
        
    }
    printf("%d\n", Max);
    return 0;
}