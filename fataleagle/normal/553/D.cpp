#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<int> adj[100001];
int gooddeg[100001];
int realdeg[100001];
bool bad[100001];
bool bad2[100001];
int target[100001];
bool seen[100001];
vector<int> group, ans;
bool ingroup[100001];
bool inQ[100001];

bool good(int u)
{
    return !bad[u] && !bad2[u];
}

void dfs(int u)
{
    group.push_back(u);
    seen[u]=true;
    for(auto& v: adj[u]) if(!seen[v] && good(v))
        dfs(v);
}

bool check(double x)
{
    queue<int> Q;
    for(int i=1; i<=N; i++) if(!bad[i])
    {
        target[i]=ceil(x*adj[i].size());
        realdeg[i]=gooddeg[i];
        seen[i]=false;
        if(realdeg[i]<target[i])
            Q.push(i), inQ[i]=true;
        else
            inQ[i]=false;
        bad2[i]=false;
    }
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        bad2[u]=true;
        for(auto& v: adj[u]) if(!bad[v])
        {
            realdeg[v]--;
            if(realdeg[v]<target[v] && !inQ[v])
                Q.push(v), inQ[v]=true;
        }
    }
    for(int i=1; i<=N; i++) if(!seen[i] && good(i))
    {
        group.clear();
        dfs(i);
        for(auto& u: group)
            ingroup[u]=true;
        bool ok=true;
        for(auto& u: group)
        {
            int cnt=0;
            for(auto& v: adj[u])
                cnt+=ingroup[v];
            if(cnt<target[u])
            {
                ok=false;
                break;
            }
        }
        for(auto& u: group)
            ingroup[u]=false;
        if(ok)
        {
            ans.swap(group);
            return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    int a, b;
    for(int i=0; i<K; i++)
    {
        scanf("%d", &a);
        bad[a]=true;
    }
    for(int i=0; i<M; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int u=1; u<=N; u++)
        for(auto& v: adj[u])
            if(!bad[v])
                gooddeg[u]++;
    double lo=0.0, mid, hi=1.0;
    for(int i=0; i<60; i++)
    {
        mid=(lo+hi)/2.0;
        if(check(mid))
            lo=mid;
        else
            hi=mid;
    }
    if(ans.empty())
    {
        printf("1\n");
        for(int i=1; i<=N; i++) if(!bad[i])
            return printf("%d\n", i), 0;
    }
    else
    {
        printf("%d\n", ans.size());
        for(auto& it: ans)
            printf("%d ", it);
        printf("\n");
    }
    return 0;
}