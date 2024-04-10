#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, M;
vector<int> adj[4005];
int dist[4005][4005];
int Q[50000], head, tail;
int S0, T0, L0, S1, T1, L1;

void bfs(int root)
{
    Q[head=0]=root;
    tail=1;
    dist[root][root]=0;
    while(head<tail)
    {
        int u=Q[head++];
        for(auto& v: adj[u]) if(dist[root][u]+1<dist[root][v])
        {
            dist[root][v]=dist[root][u]+1;
            Q[tail++]=v;
        }
    }
}

int main()
{
    memset(dist, 0x3f, sizeof dist);
    scan(N);
    scan(M);
    int a, b;
    for(int i=0; i<M; i++)
    {
        scan(a);
        scan(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    scan(S0); scan(T0); scan(L0);
    scan(S1); scan(T1); scan(L1);
    for(int i=1; i<=N; i++)
        bfs(i);
    if(dist[S0][T0]>L0 || dist[S1][T1]>L1)
    {
        printf("-1\n");
        return 0;
    }
    int ans=M;
    for(int t0=0; t0<2; t0++)
    {
        for(int t1=0; t1<2; t1++)
        {
            ans=min(ans, dist[S0][T0]+dist[S1][T1]);
            for(int i=1; i<=N; i++)
                for(int j=1; j<=N; j++)
                    if(dist[S0][i]+dist[i][j]+dist[j][T0]<=L0 &&
                       dist[S1][i]+dist[i][j]+dist[j][T1]<=L1)
                        ans=min(ans, dist[S0][i]+dist[i][j]+dist[j][T0]+dist[S1][i]+dist[j][T1]);
            swap(S1, T1);
        }
        swap(S0, T0);
    }
    printf("%d\n", M-ans);
    return 0;
}