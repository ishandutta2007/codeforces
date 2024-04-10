#include <bits/stdc++.h>

using namespace std;

int N;
int n;
int A[10240];
int B[10240];
int C[10240];

void init(int idx)
{
    if(idx>N)
        return;
    B[idx]+=A[idx];
    B[idx*2]+=B[idx];
    B[idx*2+1]+=B[idx];
    init(idx*2);
    init(idx*2+1);
    C[idx]=B[idx];
    C[idx]=max(C[idx], max(C[idx*2], C[idx*2+1]));
}

long long solve(int idx, int l, int r, int goal, int add)
{
    if(idx>N)
        return 0;
    int ret=goal-C[idx]-add;
    if(idx==1)
        ret=0;
    if(ret<0)
        return 0x3f3f3f3fLL;
    add+=ret;
    int m=(l+r)/2;
    return ret+solve(idx*2, l, m, goal, add)+solve(idx*2+1, m+1, r, goal, add);
}

int main()
{
    scanf("%d", &n);
    N=(1<<(n+1))-1;
    for(int i=2; i<=N; i++)
        scanf("%d", A+i);
    init(1);
    int M=N-(1<<n)+1;
    long long ans=0x3f3f3f3f3f3f3f3fLL;
    for(int i=1; i<=1000; i++)
        ans=min(ans, solve(1, M, N, i, 0));
    printf("%lld\n", ans);
    return 0;
}