#include <bits/stdc++.h>

using namespace std;

int N;
long long A[100001];
long long dp[100001];

int main()
{
    scanf("%d", &N);
    int a;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a);
        A[a]++;
    }
    dp[1]=A[1];
    for(long long i=2; i<=100000; i++)
        dp[i]=max(dp[i-1], dp[i-2]+i*A[i]);
    printf("%lld\n", dp[100000]);
    return 0;
}