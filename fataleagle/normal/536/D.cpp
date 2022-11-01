#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct compressor
{
    int NX;
    long long X[2001];
    void add(long long x)
    {
        X[NX++]=x;
    }
    void init()
    {
        sort(X, X+NX);
        NX=unique(X, X+NX)-X;
    }
    int get(long long x)
    {
        return lower_bound(X, X+NX, x)-X;
    }
} cc[2];

int N, M, S, T;
int P[2001];
long long adj[2001][2001];
long long dist[2][2001];
bool seen[2][2001];
long long dp[2001][2001][2];
vector<pair<int, long long>> all[2][2001];

// player, new number, other number
long long get(int t, int x, int y)
{
    size_t pos=upper_bound(all[t][x].begin(), all[t][x].end(), make_pair(y, -0x3f3f3f3f3f3f3f3fLL))-all[t][x].begin();
    if(pos==all[t][x].size())
        return 0x3f3f3f3f3f3f3f3fLL;
    return all[t][x].back().second-(pos?all[t][x][pos-1].second:0);
}

int main()
{
    memset(adj, 0x3f, sizeof adj);
    memset(dist, 0x3f, sizeof dist);
    scanf("%d%d%d%d", &N, &M, &S, &T);
    S--, T--;
    for(int i=0; i<N; i++)
        scanf("%d", P+i), adj[i][i]=0;
    int a, b, c;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        adj[a][b]=min(adj[a][b], (long long)c);
        adj[b][a]=min(adj[b][a], (long long)c);
    }
    for(int t=0; t<2; t++)
    {
        if(t==0)
            dist[t][S]=0;
        else
            dist[t][T]=0;
        for(int i=1; i<N; i++)
        {
            int idx=-1;
            for(int j=0; j<N; j++) if(!seen[t][j] && (idx==-1 || dist[t][j]<dist[t][idx]))
                idx=j;
            seen[t][idx]=true;
            for(int j=0; j<N; j++)
                dist[t][j]=min(dist[t][j], dist[t][idx]+adj[idx][j]);
        }
        for(int i=0; i<N; i++)
            cc[t].add(dist[t][i]);
        cc[t].init();
    }
    for(int t=0; t<2; t++)
        for(int i=0; i<N; i++)
            all[t^1][cc[t^1].get(dist[t^1][i])].push_back({cc[t].get(dist[t][i]), P[i]});
    for(int t=0; t<2; t++)
        for(int i=0; i<cc[t].NX; i++)
            for(size_t j=1; j<all[t][i].size(); j++)
                all[t][i][j].second+=all[t][i][j-1].second;
    for(int i=cc[0].NX; i>=0; i--)
        for(int j=cc[1].NX; j>=0; j--)
            for(int k=0; k<2; k++)
            {
                if(i==cc[0].NX && j==cc[1].NX)
                {
                    dp[i][j][k]=0;
                    continue;
                }
                if(k==0)
                {
                    dp[i][j][k]=-0x3f3f3f3f3f3f3f3fLL;
                    // same turn
                    if(i<cc[k].NX)
                    {
                        long long tmp=get(k, i, j);
                        if(tmp==0x3f3f3f3f3f3f3f3fLL)
                            dp[i][j][k]=max(dp[i][j][k], dp[i+1][j][k]);
                        else
                            dp[i][j][k]=max(dp[i][j][k], dp[i+1][j][k]+tmp);
                    }
                    // switch turn
                    if(j<cc[k^1].NX)
                    {
                        long long tmp=get(k^1, j, i);
                        if(tmp==0x3f3f3f3f3f3f3f3fLL)
                            dp[i][j][k]=max(dp[i][j][k], dp[i][j+1][k]);
                        else
                            dp[i][j][k]=max(dp[i][j][k], dp[i][j+1][k^1]-tmp);
                    }
                }
                else
                {
                    dp[i][j][k]=0x3f3f3f3f3f3f3f3fLL;
                    // same turn
                    if(j<cc[k].NX)
                    {
                        long long tmp=get(k, j, i);
                        if(tmp==0x3f3f3f3f3f3f3f3fLL)
                            dp[i][j][k]=min(dp[i][j][k], dp[i][j+1][k]);
                        else
                            dp[i][j][k]=min(dp[i][j][k], dp[i][j+1][k]-tmp);
                    }
                    // switch turn
                    if(i<cc[k^1].NX)
                    {
                        long long tmp=get(k^1, i, j);
                        if(tmp==0x3f3f3f3f3f3f3f3fLL)
                            dp[i][j][k]=min(dp[i][j][k], dp[i+1][j][k]);
                        else
                            dp[i][j][k]=min(dp[i][j][k], dp[i+1][j][k^1]+tmp);
                    }
                }
            }
    if(dp[0][0][0]>0)
        printf("Break a heart\n");
    else if(dp[0][0][0]<0)
        printf("Cry\n");
    else
        printf("Flowers\n");
    return 0;
}