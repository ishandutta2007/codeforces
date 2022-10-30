#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> adj[100001];
int color[2][100001];
vector<int> w, b;
bool bad;

void dfs(int u, int t)
{
    if(color[t][u]==0)
        w.push_back(u);
    else
        b.push_back(u);
    for(auto& it: adj[u])
    {
        int v=it.first;
        int c=it.second^t;
        if(color[t][v]==-1)
        {
            color[t][v]=color[t][u]^c;
            dfs(v, t);
        }
        else if(color[t][v]!=(color[t][u]^c))
            bad=true;
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; i++)
    {
        int a, b;
        char c;
        scanf("%d%d %c", &a, &b, &c);
        if(c=='B')
        {
            adj[a].push_back({b, 0});
            adj[b].push_back({a, 0});
        }
        else
        {
            adj[a].push_back({b, 1});
            adj[b].push_back({a, 1});
        }
    }
    vector<int> W, B;
    memset(color, -1, sizeof color);
    vector<int> ret;
    bool wBad=false, bBad=false;
    for(int i=1; i<=N; i++) if(color[0][i]==-1)
    {
        bad=false;
        w.clear();
        b.clear();
        color[0][i]=0;
        dfs(i, 0);
        if(w.size()>b.size())
            w.swap(b);
        if(!bad)
        {
            for(auto& it: w)
                W.push_back(it);
        }
        else
            wBad=true;
        bad=false;
        w.clear();
        b.clear();
        color[1][i]=0;
        dfs(i, 1);
        if(w.size()>b.size())
            w.swap(b);
        if(!bad)
        {
            for(auto& it: w)
                B.push_back(it);
        }
        else
            bBad=true;
    }
    if(wBad && bBad)
        return printf("-1\n"), 0;
    if(wBad || (!bBad && W.size()>B.size()))
        swap(W, B);
    printf("%d\n", W.size());
    for(auto& it: W)
        printf("%d ", it);
    printf("\n");
    return 0;
}