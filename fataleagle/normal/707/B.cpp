#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<pair<int, int>> adj[100001];
bool f[100001];

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    for(int i=0; i<M; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for(int i=0; i<K; i++)
    {
        int a;
        scanf("%d", &a);
        f[a]=true;
    }
    int ans=0x3f3f3f3f;
    for(int i=1; i<=N; i++) if(f[i]) for(auto& it: adj[i]) if(!f[it.first])
        ans=min(ans, it.second);
    if(ans>=0x3f3f3f3f)
        printf("-1\n");
    else
        printf("%d\n", ans);
    return 0;
}