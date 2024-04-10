#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int MOD=1000000007;
int N, D;
int A[2001];
vector<int> adj[2001];
bool visit[2001][2001];
int dp[2001];
int root;

void dfs(int u, int p)
{
    dp[u]=0;
    if(visit[root][u] || A[u]<A[root] || A[u]>A[root]+D)
        return;
    visit[root][u]=visit[u][root]=true;
    dp[u]=1;
    for(auto& v: adj[u])
    {
        if(v==p)
            continue;
        dfs(v, u);
        dp[u]=((long long)dp[u]*(dp[v]+1))%MOD;
    }
}

int main()
{
    scanf("%d%d", &D, &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    int a, b;
    for(int i=1; i<N; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans=0;
    for(root=1; root<=N; root++)
    {
        dfs(root, -1);
        ans=(ans+dp[root])%MOD;
    }
    printf("%d\n", ans);
    return 0;
}