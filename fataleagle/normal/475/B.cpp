#include <bits/stdc++.h>

using namespace std;

int N, M;
char H[25];
char V[25];
int dist[400][400];
bool seen[400];
vector<int> adj[400];

int code(int x, int y)
{
    return x*M+y;
}

void dfs(int u)
{
    seen[u]=true;
    for(auto v: adj[u])
        if(!seen[v])
            dfs(v);
}

int main()
{
    scanf("%d%d%s%s", &N, &M, H, V);
    for(int i=0; i<N; i++)
        if(H[i]=='<')
            for(int j=M-1; j>0; j--)
                adj[code(i, j)].push_back(code(i, j-1));
        else
            for(int j=0; j<M-1; j++)
                adj[code(i, j)].push_back(code(i, j+1));
    for(int i=0; i<M; i++)
        if(V[i]=='^')
            for(int j=N-1; j>0; j--)
                adj[code(j, i)].push_back(code(j-1, i));
        else
            for(int j=0; j<N-1; j++)
                adj[code(j, i)].push_back(code(j+1, i));
    for(int i=0; i<N*M; i++)
    {
        memset(seen, 0, sizeof seen);
        dfs(i);
        if(count(seen, seen+N*M, true)!=N*M)
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}