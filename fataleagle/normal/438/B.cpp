#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[100001];
int order[100001];
int idx[100001];
int sz[100001];
vector<int> adj[100001];
int parent[100001];

int find(int u)
{
    if(u!=parent[u])
        parent[u]=find(parent[u]);
    return parent[u];
}

void uni(int u, int v)
{
    u=find(u);
    v=find(v);
    parent[u]=v;
    sz[v]+=sz[u];
}

bool cmp(int a, int b)
{
    return A[a]>A[b];
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i), order[i]=parent[i]=i, sz[i]=1;
    sort(order+1, order+1+N, cmp);
    for(int i=1; i<=N; i++)
        idx[order[i]]=i;
    int a, b;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    long long ans=0;
    vector<int> weights;
    for(int i=1; i<=N; i++)
    {
        int u=order[i];
        weights.clear();
        for(size_t j=0; j<adj[u].size(); j++)
        {
            int v=adj[u][j];
            if(idx[v]<idx[u])
                weights.push_back(find(v));
        }
        sort(weights.begin(), weights.end());
        weights.resize(unique(weights.begin(), weights.end())-weights.begin());
        long long tot=1;
        for(size_t j=0; j<weights.size(); j++)
        {
            int v=weights[j];
            if(v==find(u))
                continue;
            ans+=tot*sz[v]*A[u];
            tot+=sz[v];
            uni(u, v);
        }
    }
    long double dans=ans;
    dans=(dans/N/(N-1))*2;
    cout<<setprecision(8)<<dans<<'\n';
    return 0;
}