#include <bits/stdc++.h>

using namespace std;

int N, C;
int A[10001];
int B[10001];
long long dp[10001];
long long ndp[10001];

int main()
{
    scanf("%d%d", &N, &C);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    for(int i=0; i<N; i++)
        scanf("%d", B+i);
    memset(dp, 0x3f, sizeof dp);
    dp[0]=A[0];
    dp[1]=B[0];
    for(int i=1; i<N; i++)
    {
        memset(ndp, 0x3f, sizeof ndp);
        for(int j=0; j<=i; j++)
        {
            ndp[j+1]=min(ndp[j+1], dp[j]+B[i]);
            ndp[j]=min(ndp[j], dp[j]+A[i]+1LL*j*C);
        }
        memcpy(dp, ndp, sizeof dp);
    }
    printf("%lld\n", *min_element(dp, dp+N+1));
    return 0;
}