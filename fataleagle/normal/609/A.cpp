#include <bits/stdc++.h>

using namespace std;

const int MAX=100001;
int N, M;
int dp[MAX+1];

int main()
{
    scanf("%d%d", &N, &M);
    memset(dp, 0x3f, sizeof dp);
    dp[0]=0;
    int a;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a);
        for(int j=MAX; j>=a; j--)
            dp[j]=min(dp[j], dp[j-a]+1);
    }
    int ans=0x3f3f3f3f;
    for(int i=M; i<=MAX; i++)
        ans=min(ans, dp[i]);
    printf("%d\n", ans);
    return 0;
}