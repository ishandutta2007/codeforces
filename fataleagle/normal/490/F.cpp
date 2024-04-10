#include <bits/stdc++.h>

using namespace std;

int N;
int A[6001];
int X[6001];
vector<int> adj[6001];
int ans;
int ptr=1;
int dp[6001];
vector<int> bit[6001];

inline void update(int x, int v)
{
    for(; x<=N; x+=x&-x)
        bit[x].push_back(max(bit[x].back(), v));
}

inline void unupdate(int x)
{
    for(; x<=N; x+=x&-x)
        bit[x].pop_back();
}

inline int query(int x)
{
    int ret=0;
    for(; x>0; x-=x&-x)
        ret=max(ret, bit[x].back());
    return ret;
}

void dfs(int u, int p)
{
    dp[ptr]=query(A[u]-1)+1;
    update(A[u], dp[ptr]);
    ans=max(ans, dp[ptr]);
    ptr++;
    for(auto& v: adj[u])
    {
        if(v==p)
            continue;
        dfs(v, u);
    }
    unupdate(A[u]);
    ptr--;
}

int main()
{
    scanf("%d", &N);
    int a, b;
    for(int i=1; i<=N; i++)
        scanf("%d", A+i), X[i]=A[i], bit[i].push_back(0);
    sort(X+1, X+1+N);
    for(int i=1; i<=N; i++)
        A[i]=lower_bound(X+1, X+1+N, A[i])-X;
    for(int i=1; i<N; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=N; i++)
        dfs(i, -1);
    printf("%d\n", ans);
    return 0;
}