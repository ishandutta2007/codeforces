#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

const int MOD=1000000007;
int N, K;
vector<pair<int, int>> ban;
vector<int> adj[100001];
int P[18][100001];
int level[100001];
int up[100001];
int down[100001];
int p2[1000001];

void dfs(int u, int p)
{
    P[0][u]=p;
    for(int i=1; i<=17; i++)
        P[i][u]=P[i-1][P[i-1][u]];
    for(auto& v: adj[u]) if(v!=p)
    {
        level[v]=level[u]+1;
        dfs(v, u);
    }
}

int get_lca(int u, int v)
{
    if(level[u]<level[v])
        swap(u, v);
    for(int i=17; i>=0; i--) if(level[P[i][u]]>=level[v])
        u=P[i][u];
    if(u==v)
        return u;
    for(int i=17; i>=0; i--) if(P[i][u]!=P[i][v])
        u=P[i][u], v=P[i][v];
    return P[0][u];
}

void dfs2(int u, int p)
{
    for(auto& v: adj[u]) if(v!=p)
    {
        dfs2(v, u);
        up[u]+=up[v];
        down[u]+=down[v];
    }
}

int main()
{
    p2[0]=1;
    for(int i=1; i<=1000000; i++)
        p2[i]=2LL*p2[i-1]%MOD;
    scan(N);
    int a, b, c;
    for(int i=1; i<N; i++)
    {
        scan(a); scan(b); scan(c);
        if(c==1)
            ban.push_back({a, b});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    scan(K);
    int u=1, v;
    for(int i=0; i<K; i++)
    {
        scan(v);
        int w=get_lca(u, v);
        up[u]++;
        up[w]--;
        down[v]++;
        down[w]--;
        u=v;
    }
    dfs2(1, 1);
    long long ans=0;
    for(auto& it: ban)
    {
        u=it.first, v=it.second;
        swap(u, v);
        if(level[u]<level[v])
            ans=(ans+p2[down[v]]-1+MOD)%MOD;
        else
            ans=(ans+p2[up[u]]-1+MOD)%MOD;
    }
    printf("%lld\n", ans);
    return 0;
}