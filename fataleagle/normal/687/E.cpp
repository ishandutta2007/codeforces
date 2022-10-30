#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adj[5001];
vector<int> adj2[5001];
int idx[5001];
int low[5001];
int now;
vector<int> S;
bool onS[5001];
int comp[5001];
int ncomp;
bool good[5001];
vector<int> elem[5001];
int dist[5001];
int Q[5001], head, tail;

void dfs(int u)
{
    idx[u]=++now;
    low[u]=idx[u];
    S.push_back(u);
    onS[u]=true;
    for(auto& v: adj[u])
    {
        if(idx[v]==-1)
        {
            dfs(v);
            low[u]=min(low[u], low[v]);
        }
        else if(onS[v])
            low[u]=min(low[u], idx[v]);
    }
    if(idx[u]==low[u])
    {
        ncomp++;
        int n;
        do
        {
            n=S.back();
            S.pop_back();
            onS[n]=false;
            comp[n]=ncomp;
            elem[ncomp].push_back(n);
        }
        while(n!=u);
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    int a, b;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
    }
    memset(idx, -1, sizeof idx);
    for(int i=1; i<=N; i++) if(idx[i]==-1)
        dfs(i);
    for(int u=1; u<=N; u++) for(auto& v: adj[u])
    {
        if(comp[u]!=comp[v])
            good[comp[u]]=true;
        else
            adj2[u].push_back(v);
    }
    int ans=N;
    for(int i=1; i<=ncomp; i++) if(!good[i])
    {
        int mdist=0x3f3f3f3f;
        for(auto& u: elem[i])
        {
            memset(dist, 0x3f, sizeof dist);
            dist[u]=0;
            Q[head=0]=u;
            tail=1;
            while(head<tail)
            {
                int x=Q[head++];
                for(auto& y: adj2[x])
                {
                    if(y==u)
                        mdist=min(mdist, dist[x]+1);
                    else if(dist[y]==0x3f3f3f3f)
                    {
                        dist[y]=dist[x]+1;
                        Q[tail++]=y;
                    }
                }
            }
        }
        if(mdist!=0x3f3f3f3f)
            ans+=mdist*998+1;
    }
    printf("%d\n", ans);
    return 0;
}