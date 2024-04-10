#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[200001];
vector<int> adj[200001];
long long ans;

void dfs(int u, int p)
{
    for(auto& v: adj[u]) if(v!=p)
    {
        dfs(v, u);
        A[u]+=A[v];
        ans+=min(A[v], 2*K-A[v]);
    }
}

int main()
{
    scanf("%d%d", &N, &K);
    for(int i=0; i<2*K; i++)
    {
        int a;
        scanf("%d", &a);
        A[a]=1;
    }
    for(int i=0; i<N-1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    printf("%lld\n", ans);
    return 0;
}