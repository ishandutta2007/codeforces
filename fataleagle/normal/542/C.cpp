#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[201];
int seen[201], now;
int cyclen, dist;

void dfs(int u)
{
    if(seen[u])
    {
        cyclen=now-seen[u]+1;
        dist=now-cyclen;
        return;
    }
    seen[u]=++now;
    for(auto& v: adj[u])
        dfs(v);
}

long long gcd(long long a, long long b)
{
    if(!b)
        return a;
    return gcd(b, a%b);
}

int main()
{
    scanf("%d", &N);
    int a;
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &a);
        adj[i].push_back(a);
    }
    int mini=0;
    long long ans=1;
    for(int i=1; i<=N; i++)
    {
        memset(seen, 0, sizeof seen);
        now=0;
        dfs(i);
        mini=max(mini, dist);
        ans=ans/gcd(ans, cyclen)*cyclen;
    }
    long long gans=ans;
    while(gans<mini)
        gans+=ans;
    printf("%lld\n", gans);
    return 0;
}