#include <bits/stdc++.h>

using namespace std;

const int MAGIC=40;
int N, M;
vector<int> adj[500001];
int par[500001];
double S[500001][MAGIC];

void update(int u, int l)
{
    if(u!=1 && l+1<MAGIC)
    {
        update(par[u], l+1);
        S[par[u]][l+1]/=1+S[u][l];
    }
    if(l==0)
    {
        S[u][l]*=0.5;
        while(par[u] && l+1<MAGIC)
        {
            S[par[u]][l+1]*=1+S[u][l];
            u=par[u];
            l++;
        }
    }
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<MAGIC; i++)
        S[1][i]=1.0;
    M=1;
    int a, b;
    for(int i=0; i<N; i++)
    {
        scanf("%d%d", &a, &b);
        if(a==1)
        {
            adj[b].push_back(++M);
            par[M]=b;
            for(int j=0; j<MAGIC; j++)
                S[M][j]=1.0;
            update(b, 0);
        }
        else
        {
            double ans=0.0;
            for(int j=1; j<MAGIC; j++)
                ans+=j*(S[b][j]-S[b][j-1]);
            printf("%.6f\n", ans);
        }
    }
    return 0;
}