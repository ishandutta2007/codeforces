#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N, M;
char grid[1001][1001];
pair<int, int> Q[1000001];
int head, tail;
int dist[1001][1001];
int dx[]={-1, 1, 0, 0};
int dy[]={0, 0, -1, 1};

int main()
{
    memset(dist, -1, sizeof dist);
    scanf("%d%d", &N, &M);
    int x=-1, y=-1;
    for(int i=0; i<N; i++)
    {
        scanf("%s", grid[i]);
        for(int j=0; j<M; j++)
            if(grid[i][j]=='E')
                x=i, y=j;
    }
    Q[head=0]=make_pair(x, y);
    tail=1;
    dist[x][y]=0;
    int limit=-1;
    while(head<tail)
    {
        x=Q[head].first;
        y=Q[head].second;
        head++;
        if(grid[x][y]=='S')
            limit=dist[x][y];
        for(int i=0; i<4; i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M && grid[nx][ny]!='T' && dist[nx][ny]==-1)
            {
                dist[nx][ny]=dist[x][y]+1;
                Q[tail++]=make_pair(nx, ny);
            }
        }
    }
    int ans=0;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(dist[i][j]!=-1 && grid[i][j]>='0' && grid[i][j]<='9' && dist[i][j]<=limit)
                ans+=grid[i][j]-'0';
    printf("%d\n", ans);
    return 0;
}