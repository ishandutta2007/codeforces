#include <bits/stdc++.h>

using namespace std;

int N;
int A[200001];
vector<int> adj[200001];
int P[18][200001];
long long D[18][200001];
int sum[200001];

void dfs(int u)
{
    for(int i=1; i<18; i++)
    {
        P[i][u]=P[i-1][P[i-1][u]];
        D[i][u]=D[i-1][u]+D[i-1][P[i-1][u]];
    }
    int x=A[u];
    int p=u;
    for(int i=17; i>=0; i--) if(D[i][p]<=x)
        x-=D[i][p], p=P[i][p];
    if(p!=1)
        sum[P[0][p]]--;
    sum[u]++;
    for(auto& v: adj[u])
        dfs(v);
}

void dfs2(int u)
{
    for(auto& v: adj[u])
    {
        dfs2(v);
        sum[u]+=sum[v];
    }
}

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    for(int i=2; i<=N; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        P[0][i]=a;
        D[0][i]=b;
        adj[a].push_back(i);
    }
    P[0][1]=1;
    dfs(1);
    dfs2(1);
    for(int i=1; i<=N; i++)
        printf("%d ", sum[i]-1);
    printf("\n");
    return 0;
}