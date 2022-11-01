#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N, M;
vector<int> adj[100001];
vector<int> adj2[100001];
bool seen[100001];
vector<int> comp;
int idx[100001];
int low[100001];
int now;
vector<int> S;
bool onS[100001];
bool flag;

void dfs(int u)
{
    comp.push_back(u);
    seen[u]=true;
    for(auto& v: adj2[u])
        if(!seen[v])
            dfs(v);
}

void dfs2(int u)
{
    idx[u]=low[u]=++now;
    onS[u]=true;
    size_t n=S.size();
    S.push_back(u);
    for(auto& v: adj[u])
    {
        if(!idx[v])
        {
            dfs2(v);
            low[u]=min(low[u], low[v]);
        }
        else if(onS[v])
            low[u]=min(low[u], idx[v]);
    }
    if(idx[u]==low[u])
    {
        int cnt=0;
        while(S.size()!=n)
        {
            cnt++;
            onS[S.back()]=false;
            S.pop_back();
        }
        flag|=cnt>1;
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
        adj2[a].push_back(b);
        adj2[b].push_back(a);
    }
    int ans=0;
    for(int i=1; i<=N; i++)
        if(!seen[i])
        {
            comp.clear();
            dfs(i);
            flag=false;
            for(auto& u: comp)
                if(!idx[u])
                    dfs2(u);
            if(flag)
                ans+=comp.size();
            else
                ans+=comp.size()-1;
        }
    printf("%d\n", ans);
    return 0;
}