#include <bits/stdc++.h>

using namespace std;

const int dx[4]={-1, 1, 0, 0};
const int dy[4]={0, 0, -1, 1};
int N, K;
char grid[502][502];
int id[502][502], nid;
bool seen[502][502];
int sz[250000];
bool used[250000];
int ans[502][502];
int rans;
vector<int> v;

void add_range(int x0, int y0, int x1, int y1, int n)
{
    if(x0>x1 || y0>y1)
        return;
    ans[x0][y0]+=n;
    ans[x0][y1+1]-=n;
    ans[x1+1][y0]-=n;
    ans[x1+1][y1+1]+=n;
}

void bfs(int x, int y)
{
    nid++;
    queue<pair<int, int>> Q;
    Q.push({x, y});
    seen[x][y]=true;
    int cnt=0;
    int minx=x;
    int maxx=x;
    int miny=y;
    int maxy=y;
    while(!Q.empty())
    {
        x=Q.front().first;
        y=Q.front().second;
        Q.pop();
        id[x][y]=nid;
        cnt++;
        minx=min(minx, x);
        maxx=max(maxx, x);
        miny=min(miny, y);
        maxy=max(maxy, y);
        for(int i=0; i<4; i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(1<=nx && nx<=N && 1<=ny && ny<=N && grid[nx][ny]=='.' && !seen[nx][ny])
            {
                Q.push({nx, ny});
                seen[nx][ny]=true;
            }
        }
    }
    sz[nid]=cnt;
    rans=max(rans, cnt);
    add_range(max(1, maxx-K+1), max(1, maxy-K+1), minx, miny, cnt);
}

int prep(int x, int y)
{
    if(1<=x && x<=N && 1<=y && y<=N && !used[id[x][y]])
    {
        used[id[x][y]]=true;
        return sz[id[x][y]];
    }
    return 0;
}

void undo(int x, int y)
{
    if(1<=x && x<=N && 1<=y && y<=N)
        used[id[x][y]]=false;
}

int main()
{
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++)
        scanf("%s", grid[i]+1);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) if(grid[i][j]=='.' && !seen[i][j])
            bfs(i, j);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) if(grid[i][j]=='X')
            add_range(max(1, i-K+1), max(1, j-K+1), i, j, 1);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            ans[i][j]+=ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1];
    for(int i=1; i<=N-K+1; i++)
        for(int j=1; j<=N-K+1; j++)
        {
            int sum=ans[i][j];
            for(int k=0; k<K; k++)
            {
                sum+=prep(i-1, j+k);
                sum+=prep(i+K, j+k);
                sum+=prep(i+k, j-1);
                sum+=prep(i+k, j+K);
            }
            rans=max(rans, sum);
            for(int k=0; k<K; k++)
            {
                undo(i-1, j+k);
                undo(i+K, j+k);
                undo(i+k, j-1);
                undo(i+k, j+K);
            }
        }
    printf("%d\n", rans);
    return 0;
}