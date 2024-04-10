#include <bits/stdc++.h>

using namespace std;

int N, M, K, W;
char grid[1000][10][10];
int parent[1001];
bool seen[1001];

int find(int u)
{
    if(u!=parent[u])
        parent[u]=find(parent[u]);
    return parent[u];
}

void uni(int u, int v)
{
    parent[find(u)]=find(v);
}

struct edge
{
    int u, v, c;
    bool operator< (const edge& other) const
    {
        return c<other.c;
    }
};
vector<edge> edges;
vector<int> adj[1001];

int diff(int a, int b)
{
    int ret=0;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            ret+=grid[a][i][j]!=grid[b][i][j];
    return ret;
}

int main()
{
    scanf("%d%d%d%d", &N, &M, &K, &W);
    for(int k=0; k<K; k++)
    {
        parent[k]=k;
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                while((grid[k][i][j]=getchar())<=' ');
    }
    parent[K]=K;
    for(int i=0; i<K; i++)
    {
        edges.push_back((edge){K, i, N*M});
        for(int j=0; j<i; j++)
            edges.push_back((edge){i, j, W*diff(i, j)});
    }
    sort(edges.begin(), edges.end());
    int ans=0;
    for(size_t i=0; i<edges.size(); i++)
    {
        int u=edges[i].u;
        int v=edges[i].v;
        int c=edges[i].c;
        if(find(u)!=find(v))
        {
            uni(u, v);
            ans+=c;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    printf("%d\n", ans);
    queue<int> Q;
    Q.push(K);
    seen[K]=true;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(size_t i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            if(!seen[v])
            {
                if(u==K)
                    printf("%d 0\n", v+1);
                else
                    printf("%d %d\n", v+1, u+1);
                seen[v]=true;
                Q.push(v);
            }
        }
    }
    return 0;
}