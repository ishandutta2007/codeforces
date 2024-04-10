#include <bits/stdc++.h>

using namespace std;

const int dx[]={-1, 1, 0, 0};
const int dy[]={0, 0, -1, 1};
int N, M;
vector<int> adj[2000*2000];
char grid[2000][2001];
bool used[2000*2000];
int deg[2000*2000];
char ans[2000][2001];
queue<int> Q;

inline void invalidate(int u)
{
    for(auto& v: adj[u]) if(!used[v])
    {
        deg[v]--;
        if(deg[v]==1)
            Q.push(v);
    }
}

inline void make_domino(int x0, int y0, int x1, int y1)
{
    if(x0==x1)
        ans[x0][min(y0, y1)]='<', ans[x0][max(y0, y1)]='>';
    else
        ans[min(x0, x1)][y0]='^', ans[max(x0, x1)][y0]='v';
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
    {
        scanf("%s", grid[i]);
        for(int j=0; j<M; j++)
            ans[i][j]=grid[i][j];
    }
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(grid[i][j]=='.')
            {
                for(int k=0; k<4; k++)
                {
                    int x=i+dx[k], y=j+dy[k];
                    if(0<=x && x<N && 0<=y && y<M && grid[x][y]=='.')
                    {
                        deg[i*M+j]++;
                        adj[i*M+j].push_back(x*M+y);
                    }
                }
                if(deg[i*M+j]==1)
                    Q.push(i*M+j);
            }
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        if(used[u])
            continue;
        used[u]=true;
        for(auto& v: adj[u])
            if(!used[v])
            {
                used[v]=true;
                invalidate(u);
                invalidate(v);
                make_domino(u/M, u%M, v/M, v%M);
                break;
            }
    }
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(ans[i][j]=='.')
                return printf("Not unique\n"), 0;
    for(int i=0; i<N; i++)
        puts(ans[i]);
    return 0;
}