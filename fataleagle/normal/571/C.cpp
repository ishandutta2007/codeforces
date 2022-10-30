#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> vtoc[200001];
vector<int> vars[200001];
int ans[200001];
int deg[200001];
bool done[200001];
bool seen[200001];
vector<pair<int, int>> adj[200001];
vector<pair<int, int>> adj2[200001];
vector<int> comp;
vector<pair<int, pair<int, int>>> extra_edges;

void dfs(int u, int p, int xx)
{
    comp.push_back(u);
    seen[u]=true;
    assert(!done[u]);
    for(auto& it: adj[u])
    {
        int v=it.first;
        if(v==p && it.second==xx)
            continue;
        if(seen[v])
        {
            extra_edges.clear();
            extra_edges.push_back({u, it});
            extra_edges.push_back({it.first, {u, -it.second}});
            continue;
        }
        adj2[u].push_back(it);
        adj2[it.first].push_back({u, -it.second});
        dfs(v, u, -it.second);
    }
}

void dfs2(int u)
{
    assert(!done[u]);
    for(auto& it: adj2[u])
    {
        int v=it.first;
        int x=it.second;
        if(ans[abs(x)]==-1 && !done[u])
        {
            if(x>0)
                ans[abs(x)]=0;
            else
                ans[abs(x)]=1;
            done[u]=true;
        }
        if(done[v])
            continue;
    }
    assert(done[u]);
    for(auto& it: adj2[u])
    {
        int v=it.first;
        if(done[v])
            continue;
        dfs2(v);
    }
}

int main()
{
    memset(ans, -1, sizeof ans);
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
    {
        int k;
        scanf("%d", &k);
        for(int j=0; j<k; j++)
        {
            int a;
            scanf("%d", &a);
            vars[i].push_back(a);
            vtoc[abs(a)].push_back({i, a});
        }
    }
    queue<pair<int, int>> Q;
    for(int i=1; i<=M; i++)
    {
        if(vtoc[i].size()==1)
            Q.push(vtoc[i][0]);
        if(vtoc[i].size()==2 && (vtoc[i][0].second>0)==(vtoc[i][1].second>0))
            Q.push(vtoc[i][0]);
    }
    while(!Q.empty())
    {
        int u=Q.front().first;
        int x=Q.front().second;
        Q.pop();
        if(done[u])
            continue;
        if(ans[abs(x)]!=-1)
            assert(ans[abs(x)]==(x>0));
        else if(x<0)
            ans[abs(x)]=0;
        else
            ans[abs(x)]=1;
        for(auto& it: vars[u])
        {
            int itt=abs(it);
            for(size_t i=0; i<vtoc[itt].size(); i++) if(vtoc[itt][i].first==u)
            {
                vtoc[itt].erase(vtoc[itt].begin()+i);
                break;
            }
            if(vtoc[itt].size()==1)
                Q.push(vtoc[itt][0]);
            assert(vtoc[itt].size()<=1);
        }
        done[u]=true;
    }
    for(int i=1; i<=M; i++)
    {
        assert(vtoc[i].size()==0 || vtoc[i].size()==2);
        if(vtoc[i].size()==2)
        {
            assert(ans[i]==-1);
            assert(vtoc[i][0].second!=vtoc[i][1].second);
            adj[vtoc[i][0].first].push_back(vtoc[i][1]);
            adj[vtoc[i][1].first].push_back(vtoc[i][0]);
        }
    }
    for(int i=1; i<=N; i++) if(!seen[i] && !done[i])
    {
        comp.clear();
        extra_edges.clear();
        dfs(i, i, 0);
        if(extra_edges.size()==0)
            return printf("NO\n"), 0;
        for(auto& it: extra_edges)
            adj2[it.first].push_back(it.second);
        assert(Q.empty());
        for(auto& it: comp)
        {
            for(auto& it2: adj2[it])
                deg[it2.first]++;
            if(adj2[it].size()==1)
                Q.push({it, -adj2[it][0].second});
        }
        while(!Q.empty())
        {
            int u=Q.front().first;
            Q.pop();
            if(done[u])
                continue;
            bool f=false;
            for(auto& it: adj2[u])
            {
                int x=it.second;
                if(ans[abs(x)]==-1)
                {
                    if(x<0)
                        ans[abs(x)]=1;
                    else
                        ans[abs(x)]=0;
                    f=true;
                    break;
                }
            }
            assert(f);
            for(auto& it: adj2[u])
            {
                int v=it.first;
                if(!done[v] && (--deg[v])==1)
                    Q.push(it);
            }
            done[u]=true;
        }
        for(auto& it: comp) if(!done[it])
        {
            dfs2(it);
            break;
        }
    }
    printf("YES\n");
    for(int i=1; i<=M; i++)
        printf("%d", max(ans[i], 0));
    printf("\n");
    return 0;
}