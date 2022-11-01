#ifndef MAXFLOW_H_INCLUDED
#define MAXFLOW_H_INCLUDED

#include <vector>

struct FNEdge
{
    int v, c;
    std::size_t o;
    FNEdge(int _v, int _c, std::size_t _o):
        v(_v),
        c(_c),
        o(_o)
    {
        //
    }
};

template<class edge_t>
class FlowNetwork
{
private:
    int src, snk;
public:
    int N;
    std::vector<std::vector<edge_t>> adj;
    std::vector<int> level;
    std::vector<std::size_t> pos;
    std::vector<int> Q;
    int head, tail;
    FlowNetwork(int _N):
        N(_N),
        adj(N+1),
        level(N+1),
        pos(N+1),
        Q(N+1)
    {
        //
    }
    void add_edge(int u, int v, int c)
    {
        adj[u].emplace_back(v, c, adj[v].size());
        adj[v].emplace_back(u, 0, adj[u].size()-1);
    }
    bool bfs()
    {
        for(int i=0; i<=N; i++)
        {
            level[i]=-1;
            pos[i]=0;
        }
        Q[head=0]=src;
        tail=1;
        level[src]=0;
        while(head!=tail)
        {
            int u=Q[head++];
            for(std::size_t i=0; i<adj[u].size(); i++)
            {
                int v=adj[u][i].v;
                int c=adj[u][i].c;
                if(c>0 && level[v]==-1)
                {
                    level[v]=level[u]+1;
                    if(v==snk)
                        return true;
                    Q[tail++]=v;
                }
            }
        }
        return false;
    }
    long long dfs(int u, long long mx)
    {
        if(u==snk)
            return mx;
        long long ret=0;
        for(; pos[u]<adj[u].size(); pos[u]++)
        {
            int v=adj[u][pos[u]].v;
            int& c=adj[u][pos[u]].c;
            int o=adj[u][pos[u]].o;
            if(c>0 && level[v]==level[u]+1)
            {
                long long f=dfs(v, std::min(mx, (long long)c));
                ret+=f;
                adj[v][o].c+=f;
                c-=f;
                mx-=f;
                if(mx==0)
                    break;
            }
        }
        return ret;
    }
    long long maxflow(int _src, int _snk)
    {
        src=_src;
        snk=_snk;
        long long ret=0;
        while(bfs())
            ret+=dfs(src, 0x3f3f3f3f3f3f3f3fLL);
        return ret;
    }
};

using Network=FlowNetwork<FNEdge>;

#endif // MAXFLOW_H_INCLUDED
#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[1000];
int B[1000];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    scanf("%d", &M);
    for(int i=0; i<M; i++)
        scanf("%d", B+i);
    Network G(N+M+20);
    const int src=N+M+1;
    const int snk=N+M+2;
    for(int i=0; i<N; i++)
        G.add_edge(src, i, 1);
    for(int i=0; i<M; i++)
        G.add_edge(N+i, snk, 1);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(abs(A[i]-B[j])<=1)
                G.add_edge(i, N+j, 0x3f3f3f3f);
    printf("%lld\n", G.maxflow(src, snk));
    return 0;
}