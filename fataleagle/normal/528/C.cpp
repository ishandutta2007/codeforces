#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int>> adj[100001];
int deg[100001];
bool used[500001];

int main()
{
    scanf("%d%d", &N, &M);
    int a, b;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
        deg[a]++;
        deg[b]++;
    }
    int hold=-1;
    for(int i=1; i<=N; i++) if(deg[i]&1)
    {
        if(hold==-1)
            hold=i;
        else
        {
            adj[hold].push_back({i, M});
            adj[i].push_back({hold, M});
            M++;
            hold=-1;
        }
    }
    if(M&1)
    {
        adj[1].push_back({1, M});
        M++;
    }
    vector<pair<int, int>> fwd, bck, ans;
    int u=1;
    while(1)
    {
        while(used[adj[u].back().second])
            adj[u].pop_back();
        int v=adj[u].back().first;
        used[adj[u].back().second]=true;
        fwd.push_back({u, v});
        u=v;
        if(u==1)
            break;
    }
    while(!fwd.empty())
    {
        u=fwd.back().first;
        ans.push_back(fwd.back());
        fwd.pop_back();
        while(!adj[u].empty() && used[adj[u].back().second])
            adj[u].pop_back();
        if(adj[u].empty())
            continue;
        int ou=u;
        while(1)
        {
            while(used[adj[u].back().second])
                adj[u].pop_back();
            int v=adj[u].back().first;
            used[adj[u].back().second]=true;
            fwd.push_back({u, v});
            u=v;
            if(u==ou)
                break;
        }
    }
    printf("%d\n", M);
    bool flip=false;
    for(auto& it: ans)
    {
        if(flip)
            printf("%d %d\n", it.second, it.first);
        else
            printf("%d %d\n", it.first, it.second);
        flip^=1;
    }
    return 0;
}