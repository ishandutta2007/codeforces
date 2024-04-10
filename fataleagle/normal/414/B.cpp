#include <bits/stdc++.h>

using namespace std;

int N, K;
int dp[2001][2002];

int main()
{
    cin>>N>>K;
    for(int i=1; i<=N; i++)
        dp[i][1]=1;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=K; j++)
            for(int k=1; k*i<=N; k++)
                dp[k*i][j+1]=(dp[k*i][j+1]+dp[i][j])%1000000007;
    int suma=0;
    for(int i=1; i<=N; i++)
        suma=(suma+dp[i][K])%1000000007;
    printf("%d\n", suma);

    return 0;
}