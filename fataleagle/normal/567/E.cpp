#include <bits/stdc++.h>

using namespace std;

const int MOD0=1000000007;
const int MOD1=1000000009;
const int MOD2=1000000021;

struct Integer
{
    int a0, a1, a2;
    Integer()
    {
        //
    }
    Integer(int x)
    {
        *this=x;
    }
    Integer& operator= (const int x)
    {
        a0=a1=a2=x;
        return *this;
    }
    Integer operator+ (const Integer& other) const
    {
        Integer ret;
        ret.a0=a0+other.a0;
        if(ret.a0>=MOD0)
            ret.a0-=MOD0;
        ret.a1=a1+other.a1;
        if(ret.a1>=MOD1)
            ret.a1-=MOD1;
        ret.a2=a2+other.a2;
        if(ret.a2>=MOD2)
            ret.a2-=MOD2;
        return ret;
    }
    Integer operator* (const Integer& other) const
    {
        Integer ret;
        ret.a0=1LL*a0*other.a0%MOD0;
        ret.a1=1LL*a1*other.a1%MOD1;
        ret.a2=1LL*a2*other.a2%MOD2;
        return ret;
    }
    bool operator== (const Integer& other) const
    {
        return a0==other.a0 && a1==other.a1 && a2==other.a2;
    }
};

int N, M, S, T;
vector<pair<int, int>> adj1[100001];
vector<pair<int, int>> adj2[100001];
vector<pair<pair<int, int>, int>> edges;
long long dist1[100001];
long long dist2[100001];
Integer ways1[100001];
Integer ways2[100001];

struct node
{
    int u;
    long long c;
    bool operator< (const node& other) const
    {
        return c>other.c;
    }
};

void dijkstra(vector<pair<int, int>> adj[], long long dist[], Integer ways[], int src)
{
    for(int i=1; i<=N; i++)
        dist[i]=0x3f3f3f3f3f3f3f3fLL;
    dist[src]=0;
    ways[src]=1;
    priority_queue<node> pq;
    pq.push((node){src, 0});
    while(!pq.empty())
    {
        int u=pq.top().u;
        long long c=pq.top().c;
        pq.pop();
        if(c!=dist[u])
            continue;
        for(auto& it: adj[u])
        {
            int v=it.first, w=it.second;
            if(c+w<dist[v])
            {
                dist[v]=c+w;
                ways[v]=ways[u];
                pq.push((node){v, c+w});
            }
            else if(c+w==dist[v])
                ways[v]=ways[v]+ways[u];
        }
    }
}

int main()
{
    scanf("%d%d%d%d", &N, &M, &S, &T);
    int a, b, c;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        adj1[a].push_back({b, c});
        adj2[b].push_back({a, c});
        edges.push_back({{a, b}, c});
    }
    dijkstra(adj1, dist1, ways1, S);
    dijkstra(adj2, dist2, ways2, T);
    for(auto& it: edges)
    {
        int u=it.first.first;
        int v=it.first.second;
        int c=it.second;
        if(dist1[T]==dist1[u]+dist2[v]+c && ways1[u]*ways2[v]==ways1[T])
            printf("YES\n");
        else if(c-(dist1[T]-dist1[u]-dist2[v]-1)<c)
            printf("CAN %lld\n", c-(dist1[T]-dist1[u]-dist2[v]-1));
        else
            printf("NO\n");
    }
    return 0;
}