#include <bits/stdc++.h>

using namespace std;

int N;
long long K;
long long dp[51];
int A[51];

int main()
{
    dp[0]=1;
    dp[1]=1;
    for(int i=2; i<=50; i++)
        dp[i]=dp[i-2]+dp[i-1];
    scanf("%d%lld", &N, &K);
    K--;
    for(int i=0; i<N; i++)
        A[i]=i+1;
    for(int i=0; i<N; i++)
    {
        int n=N-i;
        if(K>=dp[n-1])
            swap(A[i], A[i+1]), i++, K-=dp[n-1];
    }
    for(int i=0; i<N; i++)
        printf("%d%c", A[i], " \n"[i==N-1]);
    return 0;
}