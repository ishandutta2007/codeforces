#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> adj[100001];
int color[100001];
bool bad;

void dfs(int u)
{
    for(auto& it: adj[u])
    {
        int v=it.first;
        int c=it.second;
        int ec=color[u]^c;
        if(color[v]==-1)
        {
            color[v]=ec;
            dfs(v);
            if(bad)
                return;
        }
        else if(color[v]!=ec)
        {
            bad=true;
            return;
        }
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    int a, b, c;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        c^=1;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    memset(color, -1, sizeof color);
    int comps=0;
    for(int i=1; i<=N; i++) if(color[i]==-1)
    {
        color[i]=0;
        dfs(i);
        comps++;
    }
    if(bad)
        printf("0\n");
    else
    {
        int ans=1;
        for(int i=1; i<comps; i++)
            ans=2LL*ans%1000000007;
        printf("%d\n", ans);
    }
    return 0;
}