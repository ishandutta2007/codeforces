#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[100001];
int sz[100001];
double dp[100001];

void dfs(int u)
{
    sz[u]=1;
    for(auto& v: adj[u])
    {
        dfs(v);
        sz[u]+=sz[v];
    }
}

void dfs2(int u)
{
    for(auto& v: adj[u])
    {
        dp[v]=dp[u]+1+(sz[u]-sz[v]-1)/2.0;
        dfs2(v);
    }
}

int main()
{
    scanf("%d", &N);
    for(int i=2; i<=N; i++)
    {
        int a;
        scanf("%d", &a);
        adj[a].push_back(i);
    }
    dfs(1);
    dp[1]=1.0;
    dfs2(1);
    for(int i=1; i<=N; i++)
        printf("%.6f ", dp[i]);
    printf("\n");
    return 0;
}