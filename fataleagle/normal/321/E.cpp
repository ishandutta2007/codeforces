#include <iostream>
#include <cstdio>

using namespace std;

int N, K;
int sum[4001][4001];
int dp[801][4001];

int get(int l, int r)
{
    return (sum[r][r]-sum[l-1][r]-sum[r][l-1]+sum[l-1][l-1])>>1;
}

int work(int k, int n, int a, int b)
{
    dp[k][n]=0x3f3f3f3f;
    int idx=-1;
    for(int i=a; i<=b; i++)
    {
        int val=dp[k-1][i-1]+get(i, n);
        if(val<dp[k][n])
            dp[k][n]=val, idx=i;
    }
    return idx;
}

void solve(int k, int l, int r, int a, int b)
{
    if(l==r)
        work(k, l, a, b);
    else if(l<r)
    {
        int mid=(l+r)/2;
        int idx=work(k, mid, a, b);
        solve(k, l, mid-1, a, idx);
        solve(k, mid+1, r, idx, b);
    }
}

int main()
{
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
        {
            getchar();
            sum[i][j]=getchar()-'0';
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    for(int i=1; i<=N; i++)
        dp[0][i]=0x3f3f3f3f;
    for(int i=1; i<=K; i++)
        solve(i, 1, N, 1, N);
    printf("%d\n", dp[K][N]);
    return 0;
}