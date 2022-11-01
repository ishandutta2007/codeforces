#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[1001];
bool added[1001];
int order[1001];
vector<int> adj[1001];

bool cmp(int a, int b)
{
    return A[a]<A[b];
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i), order[i]=i;
    sort(order+1, order+1+N, cmp);
    int a, b;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    long long cost=0;
    for(int i=1; i<=N; i++)
    {
        int u=order[i];
        added[u]=true;
        for(size_t j=0; j<adj[u].size(); j++)
            if(added[adj[u][j]])
                cost+=A[adj[u][j]];
    }
    printf("%lld\n", cost);
    return 0;
}