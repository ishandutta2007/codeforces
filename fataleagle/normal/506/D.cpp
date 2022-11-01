#include <bits/stdc++.h>

#ifdef getchar
#undef getchar
#endif
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

const int SZ=350;
int N, M, Q;
unordered_map<int, vector<int>> adj[100001];
vector<int> colors[100001];
int seen[100001], curtime;
int answer[2*(100001/SZ)+3][100001];
int id[100001], nid;
int root;

struct disjoint_set
{
    unordered_map<int, int> parent;
    inline int& par(int x)
    {
        auto it=parent.find(x);
        if(it==parent.end())
            return parent[x]=x;
        return it->second;
    }
    inline int par2(int x)
    {
        auto it=parent.find(x);
        if(it==parent.end())
            return -1;
        return it->second;
    }
    inline int find(int u)
    {
        int& p=par(u);
        if(u!=p)
            p=find(p);
        return p;
    }
    inline int find2(int u)
    {
        int p=par2(u);
        if(p==-1)
            return u;
        if(u!=p)
            return find2(p);
        return p;
    }
    inline void merge(int u, int v)
    {
        int x=find(u);
        int y=find(v);
        par(x)=y;
    }
    inline int query(int u, int v)
    {
        return find2(u)==find2(v);
    }
} dsu[100001];

inline void dfs(int u, int c)
{
    seen[u]=curtime;
    answer[root][u]++;
    for(auto& v: adj[u][c])
        if(seen[v]!=curtime)
            dfs(v, c);
}

int main()
{
    scan(N);
    scan(M);
    int a, b, c;
    for(int i=0; i<M; i++)
    {
        scan(a);
        scan(b);
        scan(c);
        adj[a][c].push_back(b);
        adj[b][c].push_back(a);
        dsu[c].merge(a, b);
        colors[a].push_back(c);
        colors[b].push_back(c);
    }
    for(int i=1; i<=N; i++)
    {
        sort(colors[i].begin(), colors[i].end());
        colors[i].resize(unique(colors[i].begin(), colors[i].end())-colors[i].begin());
    }
    for(int i=1; i<=N; i++)
        if(colors[i].size()>SZ)
        {
            id[i]=nid;
            root=nid++;
            for(auto& it: colors[i])
            {
                curtime++;
                dfs(i, it);
            }
        }
    scan(Q);
    while(Q--)
    {
        scan(a);
        scan(b);
        if(colors[a].size()<colors[b].size())
            swap(a, b);
        if(colors[a].size()<=SZ)
        {
            int ans=0;
            for(auto& it: colors[a])
                ans+=dsu[it].query(a, b);
            printf("%d\n", ans);
        }
        else
            printf("%d\n", answer[id[a]][b]);
    }
    return 0;
}