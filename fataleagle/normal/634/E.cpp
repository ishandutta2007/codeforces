#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[200001];
int threshold;
multiset<int> disabled[200001];
int gogo[200001];
vector<int> adj[200001];

void dfs(int u, int p)
{
    gogo[u]=1;
    for(auto& v: adj[u]) if(v!=p)
    {
        dfs(v, u);
        if(disabled[v].empty())
            gogo[u]+=gogo[v];
        else
            disabled[u].insert(gogo[v]);
    }
    if(!disabled[u].empty())
        gogo[u]+=*disabled[u].rbegin();
    if(A[u]<threshold)
    {
        gogo[u]=0;
        disabled[u].insert(0);
    }
}

void moveroot(int u, int v)
{
    if(disabled[v].empty())
    {
        if(A[u]>=threshold)
            gogo[u]-=gogo[v];
        if(disabled[u].empty())
            gogo[v]+=gogo[u];
        else
        {
            if(!disabled[v].empty())
                gogo[v]-=*disabled[v].rbegin();
            disabled[v].insert(gogo[u]);
            gogo[v]+=*disabled[v].rbegin();
        }
    }
    else
    {
        if(!disabled[u].empty())
            gogo[u]-=*disabled[u].rbegin();
        disabled[u].erase(disabled[u].find(gogo[v]));
        if(!disabled[u].empty())
            gogo[u]+=*disabled[u].rbegin();
        if(A[u]<threshold)
            gogo[u]=0;
        if(disabled[u].empty())
            gogo[v]+=gogo[u];
        else
        {
            if(!disabled[v].empty())
                gogo[v]-=*disabled[v].rbegin();
            disabled[v].insert(gogo[u]);
            gogo[v]+=*disabled[v].rbegin();
        }
    }
    if(A[u]<threshold)
        gogo[u]=0;
    if(A[v]<threshold)
        gogo[v]=0;
}

int dfs2(int u, int p)
{
    int ret=gogo[u];
    for(auto& v: adj[u]) if(v!=p)
    {
        moveroot(u, v);
        ret=max(ret, dfs2(v, u));
        moveroot(v, u);
    }
    return ret;
}

int main()
{
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    int a, b;
    for(int i=0; i<N-1; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int lo=1, mid, hi=1000000;
    while(lo<hi)
    {
        mid=(lo+hi+1)/2;
        threshold=mid;
        for(int i=1; i<=N; i++)
            disabled[i].clear();
        dfs(1, 1);
        if(dfs2(1, 1)>=K)
            lo=mid;
        else
            hi=mid-1;
    }
    printf("%d\n", lo);
    return 0;
}