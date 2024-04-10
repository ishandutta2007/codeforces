#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int N;
vector<int> adj[200001];
bool seen[200001];
int V, E;
bool loop;

void dfs(int u)
{
    seen[u]=true;
    V++;
    E+=adj[u].size();
    for(auto& v: adj[u])
    {
        if(v==u)
            loop=true;
        if(!seen[v])
            dfs(v);
    }
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans=1;
    for(int i=1; i<=2*N; i++) if(!seen[i])
    {
        V=0, E=0, loop=false;
        dfs(i);
        E/=2;
        if(loop)
            continue;
        if(V==E)
            ans=2LL*ans%MOD;
        else
            ans=1LL*ans*V%MOD;
    }
    printf("%d\n", ans);
    return 0;
}