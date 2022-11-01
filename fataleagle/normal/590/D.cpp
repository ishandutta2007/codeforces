#include <bits/stdc++.h>

using namespace std;

int N, K, S;
int A[151];
int dp[151][11176];
int ndp[151][11176];

int main()
{
    scanf("%d%d%d", &N, &K, &S);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    if(S>N*(N-1)/2)
    {
        sort(A, A+N);
        int sum=0;
        for(int i=0; i<K; i++)
            sum+=A[i];
        printf("%d\n", sum);
        return 0;
    }
    int sum=0;
    for(int i=0; i<N; i++)
        sum+=A[i];
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<=min(i, K); j++)
            for(int l=0; l<=min(S, i*(i-1)/2); l++)
            {
                ndp[j+1][l+i-j]=max(ndp[j+1][l+i-j], dp[j][l]);
                ndp[j][l]=max(ndp[j][l], dp[j][l]+A[i]);
            }
        for(int j=0; j<=min(i+1, K); j++)
            for(int l=0; l<=min(S, i*(i+1)/2); l++)
                dp[j][l]=ndp[j][l];
    }
    int ans=0;
    for(int i=0; i<=S; i++)
        ans=max(ans, dp[K][i]);
    printf("%d\n", sum-ans);
    return 0;
}