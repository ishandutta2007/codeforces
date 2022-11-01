#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int N, K;
int dp[100001][2];
int S[100001];

int main()
{
    scanf("%d%d", &N, &K);
    dp[0][0]=0;
    dp[0][1]=1;
    for(int i=1; i<=100000; i++)
    {
        if(i-K>=0)
            dp[i][0]=(dp[i-K][0]+dp[i-K][1])%MOD;
        dp[i][1]=(dp[i-1][0]+dp[i-1][1])%MOD;
        S[i]=(S[i-1]+(dp[i][0]+dp[i][1])%MOD)%MOD;
    }
    int a, b;
    for(int i=0; i<N; i++)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", (S[b]-S[a-1]+MOD)%MOD);
    }
    return 0;
}