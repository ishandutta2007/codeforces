#include <bits/stdc++.h>

using namespace std;

int N;
int A[101];
int dp[101][3];

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    for(int i=1; i<=N; i++)
    {
        dp[i][0]=max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        int x=A[i]&1;
        dp[i][1]=max({dp[i-1][0]+x, dp[i-1][1], dp[i-1][2]+x});
        x=(A[i]>>1)&1;
        dp[i][2]=max({dp[i-1][0]+x, dp[i-1][1]+x, dp[i-1][2]});
    }
    printf("%d\n", N-max({dp[N][0], dp[N][1], dp[N][2]}));
    return 0;
}