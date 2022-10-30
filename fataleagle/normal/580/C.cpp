#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[100001];
vector<int> adj[100001];
pair<int, int> dp[100001];

void dfs(int u, int p)
{
    dp[u].first=max(dp[u].first, dp[u].second);
    for(auto& v: adj[u]) if(v!=p)
    {
        dp[v].first=dp[u].first;
        if(A[v])
            dp[v].second=dp[u].second+1;
        else
            dp[v].second=0;
        dfs(v, u);
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    int a, b;
    for(int i=1; i<N; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(A[1])
        dp[1]=make_pair(1, 1);
    dfs(1, 1);
    int ans=0;
    for(int i=2; i<=N; i++) if(adj[i].size()==1)
        ans+=dp[i].first<=M;
    printf("%d\n", ans);
    return 0;
}