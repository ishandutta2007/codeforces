#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[100001];
int orig[100001];
int targ[100001];
bool flipped[100001];

int solve(int u, int p, int f1, int f2) // node, parent, immediate flip, flip child of child
{
    if(f1)
        orig[u]^=1;
    int ret=0;
    if(orig[u]!=targ[u])
    {
        ret++;
        f1^=1;
        flipped[u]=true;
    }
    for(size_t i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(v!=p)
            ret+=solve(v, u, f2, f1);
    }
    return ret;
}

int main()
{
    scanf("%d", &N);
    int a, b;
    for(int i=1; i<N; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=N; i++)
        scanf("%d", orig+i);
    for(int i=1; i<=N; i++)
        scanf("%d", targ+i);
    printf("%d\n", solve(1, -1, 0, 0));
    for(int i=1; i<=N; i++)
        if(flipped[i])
            printf("%d\n", i);
    return 0;
}