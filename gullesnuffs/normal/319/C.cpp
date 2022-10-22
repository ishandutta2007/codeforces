#include <stdio.h>
#include <algorithm>
#include <queue>
#define mod 1000000007

using namespace std;

int n;
long long a[100005], b[100005];
int start[100005];
long long dp[100005];

int get(int x, int m){
    int Min=-1, Max=m;
    while(Max-Min>1){
        int test=(Max+Min)/2;
        if(start[test] > x)
            Max=test;
        else
            Min=test;
    }
    return Min;
}

long long getCost(int x, int m){
    int s = get(x, m);
    long long c=dp[s]+b[s]*a[x];
    return c;
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i < n; ++i){
        scanf("%d", a+i);
    }
    for(int i=0; i < n; ++i){
        scanf("%d", b+i);
        dp[i] = 1LL<<61;
    }
    dp[0]=0;
    start[0]=1;
    
    for(int i=1; i < n; ++i){
        dp[i] = getCost(i, i);
        int Min=i-1, Max=n;
        while(Max-Min>1){
            int test=(Max+Min)/2;
            if(dp[i]+b[i]*a[test] > getCost(test, i))
                Min=test;
            else
                Max=test;
        }
        start[i] = Max;
        for(int j=i-1; start[j] > start[i]; --j){
            start[j] = Max;
        }
    }
    printf("%I64d", dp[n-1]);
    return 0;
}