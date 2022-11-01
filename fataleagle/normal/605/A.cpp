#include <bits/stdc++.h>

using namespace std;

int N;
int bit[100001];
int dp[100001];

void add(int x, int v)
{
    bit[x]=max(bit[x], v);
}

int get(int x)
{
    return bit[x];
}

int main()
{
    scanf("%d", &N);
    int ans=0;
    for(int i=1; i<=N; i++)
    {
        int a;
        scanf("%d", &a);
        dp[i]=get(a-1)+1;
        add(a, dp[i]);
        ans=max(ans, dp[i]);
    }
    printf("%d\n", N-ans);
    return 0;
}