#include <bits/stdc++.h>

using namespace std;

int N, M, K;
char grid[1001][1001];
bool seen[1001][1001];
vector<int> ans;
int comp[1001][1001];
int dx[]={-1, 1, 0, 0};
int dy[]={0, 0, -1, 1};

void bfs(int x, int y)
{
    int cc=ans.size();
    int rans=0;
    queue<pair<int, int>> Q;
    Q.push(make_pair(x, y));
    seen[x][y]=true;
    while(!Q.empty())
    {
        x=Q.front().first, y=Q.front().second;
        comp[x][y]=cc;
        Q.pop();
        for(int i=0; i<4; i++)
        {
            int nx=x+dx[i], ny=y+dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M && grid[nx][ny]=='*')
                rans++;
        }
        for(int i=0; i<4; i++)
        {
            int nx=x+dx[i], ny=y+dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M && grid[nx][ny]=='.' && !seen[nx][ny])
            {
                seen[nx][ny]=true;
                Q.push(make_pair(nx, ny));
            }
        }
    }
    ans.push_back(rans);
}

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    for(int i=0; i<N; i++)
        scanf("%s", grid[i]);
    for(int i=0; i<K; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        if(!seen[x][y])
            bfs(x, y);
        printf("%d\n", ans[comp[x][y]]);
    }
    return 0;
}