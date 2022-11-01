#include <bits/stdc++.h>

using namespace std;

int A[100001];
int dp[100001];

int main()
{
    int N;
    scanf("%d", &N);
    int ans=0;
    for(int i=1; i<=N; i++)
    {
        scanf("%d", A+i);
        if(i>1 && A[i-1]<A[i])
            dp[i]=dp[i-1]+1;
        else
            dp[i]=1;
        ans=max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}