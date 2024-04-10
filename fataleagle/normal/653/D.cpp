#ifndef MAXFLOW_H_INCLUDED
#define MAXFLOW_H_INCLUDED

#include <cstring>
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

template<int V, int E>
class FastFlowNetwork
{
private:
    int src, snk;
public:
    int data[2*(E+1)][3], link[2*(E+1)], start[V+1], nedge;
    int level[V+1];
    int pos[V+1];
    int Q[V+1];
    int head, tail;
    FastFlowNetwork()
    {
        memset(start, -1, sizeof start);
    }
    inline void _add_edge(int u, int v, int c, int add)
    {
        data[nedge][0]=v;
        data[nedge][1]=c;
        data[nedge][2]=nedge+add;
        link[nedge]=start[u];
        start[u]=nedge;
        nedge++;
    }
    inline void add_edge(int u, int v, int c)
    {
        _add_edge(u, v, c, 1);
        _add_edge(v, u, 0, -1);
    }
    inline bool bfs()
    {
        memset(level, -1, sizeof level);
        memcpy(pos, start, sizeof pos);
        Q[head=0]=src;
        tail=1;
        level[src]=0;
        while(head!=tail)
        {
            int u=Q[head++];
            for(int i=start[u]; i!=-1; i=link[i])
            {
                int v=data[i][0];
                int c=data[i][1];
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
    inline long long dfs(int u, long long cap)
    {
        if(u==snk)
            return cap;
        long long ret=0;
        for(; pos[u]!=-1; pos[u]=link[pos[u]])
        {
            int v=data[pos[u]][0];
            int& c=data[pos[u]][1];
            int o=data[pos[u]][2];
            if(c>0 && level[v]==level[u]+1)
            {
                long long f=dfs(v, std::min(cap, (long long)c));
                ret+=f;
                data[o][1]+=f;
                c-=f;
                cap-=f;
                if(cap==0)
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

#endif // MAXFLOW_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;

int N, M, X;
int ea[500], eb[500], ec[500];

bool solve(double x)
{
    Network G(N+1);
    for(int i=0; i<M; i++)
    {
        if(ec[i]/x>1e7)
            G.add_edge(ea[i], eb[i], 10000000);
        else
            G.add_edge(ea[i], eb[i], (int)(floor(ec[i]/x)+1e-5));
    }
    return G.maxflow(1, N)>=X;
}

int main()
{
    scanf("%d%d%d", &N, &M, &X);
    for(int i=0; i<M; i++)
        scanf("%d%d%d", ea+i, eb+i, ec+i);
    double lo=0.0, mid, hi=1000000.0;
    for(int i=0; i<100; i++)
    {
        mid=(lo+hi)/2;
        if(solve(mid))
            lo=mid;
        else
            hi=mid;
    }
    printf("%.9f\n", X*(lo+hi)/2);
    return 0;
}