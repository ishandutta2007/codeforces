#include <bits/stdc++.h>

using namespace std;

int N, M;
char grid[1001][1001];
int dist[4][1001][1001];
bool seen[1001][1001];
int dx[]={-1, 1, 0, 0};
int dy[]={0, 0, -1, 1};
int dd[4][4];

void bfs(int idx)
{
    memset(seen, 0, sizeof seen);
    queue<pair<int, int>> Q;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(grid[i][j]=='0'+idx)
                Q.push({i, j}), seen[i][j]=true;
    for(int d=0; !Q.empty(); d++)
    {
        int temp=Q.size();
        while(temp--)
        {
            int x=Q.front().first, y=Q.front().second;
            Q.pop();
            dist[idx][x][y]=d;
            if(grid[x][y]=='1')
                dd[idx][1]=min(dd[idx][1], d);
            if(grid[x][y]=='2')
                dd[idx][2]=min(dd[idx][2], d);
            if(grid[x][y]=='3')
                dd[idx][3]=min(dd[idx][3], d);
            for(int i=0; i<4; i++)
            {
                int nx=x+dx[i], ny=y+dy[i];
                if(nx>=0 && nx<N && ny>=0 && ny<M && !seen[nx][ny] && grid[nx][ny]!='#')
                    Q.push({nx, ny}), seen[nx][ny]=true;
            }
        }
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%s", grid[i]);
    memset(dd, 0x3f, sizeof dd);
    memset(dist, 0x3f, sizeof dist);
    bfs(1);
    bfs(2);
    bfs(3);
    long long ans=0x3f3f3f3f;
    int P[3]={1, 2, 3};
    do
    {
        ans=min(ans, 0LL+dd[P[0]][P[1]]+dd[P[1]][P[2]]-2);
    }
    while(next_permutation(P, P+3));
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) if(grid[i][j]!='#')
            ans=min(ans, 0LL+dist[1][i][j]+dist[2][i][j]+dist[3][i][j]-2);
    if(ans>=0x3f3f3f3f-5)
        ans=-1;
    printf("%lld\n", ans);
    return 0;
}