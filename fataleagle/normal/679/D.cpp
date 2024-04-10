#include <bits/stdc++.h>

using namespace std;

int N, M;
int adj[401][401];
double P[401];
double Q[401];

double attemptSecondRun(int x, vector<int>& cand)
{
    for(int i=1; i<=N; i++)
        P[i]=0.0;
    vector<int> w;
    for(auto& u: cand)
    {
        int deg=0;
        for(int v=1; v<=N; v++) if(adj[u][v]==1)
            deg++;
        for(int v=1; v<=N; v++) if(adj[u][v]==1)
            P[v]+=1.0/deg;
    }
    for(int i=1; i<=N; i++) if(P[i]>0.0)
        w.push_back(i);
    double ret=0.0;
    for(int i=1; i<=N; i++)
    {
        for(auto& j: w)
            Q[adj[i][j]]=max(Q[adj[i][j]], P[j]);
        double sum=0.0;
        for(auto& j: w)
        {
            sum+=Q[adj[i][j]];
            Q[adj[i][j]]=0.0;
        }
        ret=max(ret, sum);
    }
    return ret;
}

double startAtCityX(int x)
{
    double ret=0.0;
    for(int i=0; i<N; i++)
    {
        vector<int> cand;
        int cnt=0;
        for(int j=1; j<=N; j++) if(adj[x][j]==i)
            cnt++, cand.push_back(j);
        if(cnt==1)
            ret+=1.0;
        else if(cnt>1)
            ret+=max(1.0, attemptSecondRun(x, cand));
    }
    return ret;
}

int main()
{
    scanf("%d%d", &N, &M);
    memset(adj, 0x3f, sizeof adj);
    for(int i=1; i<=N; i++)
        adj[i][i]=0;
    for(int i=0; i<M; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a][b]=adj[b][a]=1;
    }
    for(int k=1; k<=N; k++)
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
    double ans=0.0;
    for(int i=1; i<=N; i++)
        ans=max(ans, startAtCityX(i));
    printf("%.9f\n", ans/N);
    return 0;
}