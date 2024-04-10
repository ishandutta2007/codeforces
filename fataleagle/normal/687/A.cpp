#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adj[100001];
int seen[100001];
vector<int> ans[2];

void dfs(int u, int c)
{
    seen[u]=c;
    ans[c].push_back(u);
    for(auto& v: adj[u])
    {
        if(seen[v]==-1)
            dfs(v, c^1);
        else if(seen[v]!=(seen[u]^1))
        {
            printf("-1\n");
            exit(0);
        }
    }
}

int main()
{
    memset(seen, -1, sizeof seen);
    scanf("%d%d", &N, &M);
    int a, b;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=N; i++) if(seen[i]==-1)
        dfs(i, 0);
    for(int i=0; i<2; i++)
    {
        printf("%d\n", ans[i].size());
        for(auto& it: ans[i])
            printf("%d ", it);
        printf("\n");
    }
    return 0;
}