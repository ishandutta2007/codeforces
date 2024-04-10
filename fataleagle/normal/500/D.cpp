#include <bits/stdc++.h>

using namespace std;

int N, Q;
vector<pair<int, int>> adj[100001];
int U[100001];
int V[100001];
int C[100001];
int sz[100001];
long long sum[100001];
long long ans;

void dfs(int u, int p)
{
    sz[u]=1;
    for(auto& it: adj[u])
    {
        int v=it.first;
        int c=it.second;
        if(v==p)
            continue;
        dfs(v, u);
        sz[u]+=sz[v];
        sum[u]+=sum[v]+1LL*c*sz[v];
    }
}

inline void moveroot(int u, int v, int c)
{
    sum[u]-=sum[v]+1LL*c*sz[v];
    sz[u]-=sz[v];
    sz[v]+=sz[u];
    sum[v]+=sum[u]+1LL*c*sz[u];
}

void dfs2(int u, int p)
{
    ans+=sum[u];
    for(auto& it: adj[u])
    {
        int v=it.first;
        int c=it.second;
        if(v==p)
            continue;
        moveroot(u, v, c);
        dfs2(v, u);
        moveroot(v, u, c);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d", &N);
    int a, b, c;
    for(int i=1; i<N; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        U[i]=a;
        V[i]=b;
        C[i]=c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }
    dfs(1, -1);
    dfs2(1, -1);
    scanf("%d", &Q);
    long long pairs=1LL*N*(N-1);
    cout<<fixed<<setprecision(8);
    for(int i=0; i<Q; i++)
    {
        scanf("%d%d", &a, &b);
        long long tmp=min(sz[U[a]], sz[V[a]]);
        tmp=tmp*(N-tmp);
        ans-=tmp*(C[a]-b)*2;
        C[a]=b;
        cout<<((long double)ans*3.0L/pairs)<<'\n';
    }
    return 0;
}