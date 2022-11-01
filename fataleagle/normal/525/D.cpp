#include <bits/stdc++.h>

using namespace std;

int N, M;
char grid[2100][2100];
bool seen[2100][2100];

bool check(int x, int y)
{
    if(x<0 || x>=N || y<0 || y>=M)
        return false;
    if(grid[x][y]!='*')
        return false;
    for(int i=-1; i<=0; i++) for(int j=-1; j<=0; j++)
    {
        int cnt=0;
        for(int k=0; k<2; k++) for(int l=0; l<2; l++)
            if(0<=x+i+k && x+i+k<N && 0<=y+j+l && y+j+l<M)
                cnt+=grid[x+i+k][y+j+l]=='.';
        if(cnt==3)
            return true;
    }
    return false;
}

void dfs(int x, int y)
{
    if(check(x, y) && !seen[x][y])
    {
        seen[x][y]=true;
        grid[x][y]='.';
        for(int i=-1; i<=1; i++)
            for(int j=-1; j<=1; j++)
                dfs(x+i, y+j);
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%s", grid[i]);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            dfs(i, j);
    for(int i=0; i<N; i++)
        puts(grid[i]);
    return 0;
}