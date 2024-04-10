#include <bits/stdc++.h>

using namespace std;

int N;
int A[1000001];
int B[1000001];
int X[1000001];
long long dp[1000001];
struct BIT
{
    long long bit[1000001];
    BIT()
    {
        for(int i=0; i<1000001; i++)
            bit[i]=-0x3f3f3f3f3f3f3f3f;
    }
    void update(int x, long long v)
    {
        for(; x<=1000000; x+=x&-x)
            bit[x]=max(bit[x], v);
    }
    long long query(int x)
    {
        long long ans=-0x3f3f3f3f3f3f3f3f;
        for(; x>0; x-=x&-x)
            ans=max(ans, bit[x]);
        return ans;
    }
} small, large;

int conv(int x)
{
    return 1000001-x;
}

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i), X[i]=A[i];
    sort(X+1, X+1+N);
    for(int i=1; i<=N; i++)
        B[i]=lower_bound(X+1, X+1+N, A[i])-X;
    for(int i=1; i<=N; i++)
    {
        dp[i]=dp[i-1];
        dp[i]=max(dp[i], small.query(conv(B[i]))-A[i]);
        dp[i]=max(dp[i], large.query(B[i])+A[i]);
        small.update(conv(B[i]), dp[i-1]+A[i]);
        large.update(B[i], dp[i-1]-A[i]);
    }
    printf("%lld\n", dp[N]);
    return 0;
}