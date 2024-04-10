#include <bits/stdc++.h>

using namespace std;

int N, M;
char grid[1002][1002];
int psum[1002][1002];
bool seen[1002][1002];
bool grid2[1002][1002];
int LH[1002][1002], LW[1002][1002];

int get(int x1, int y1, int x2, int y2)
{
    x1--, y1--;
    return psum[x2][y2]-psum[x1][y2]-psum[x2][y1]+psum[x1][y1];
}

int dfs(int x, int y)
{
    if(seen[x][y] || grid[x][y]!='X')
        return 0;
    seen[x][y]=true;
    int ret=1;
    if(x>1)
        ret+=dfs(x-1, y);
    if(x<N)
        ret+=dfs(x+1, y);
    if(y>1)
        ret+=dfs(x, y-1);
    if(y<M)
        ret+=dfs(x, y+1);
    return ret;
}

bool ok(int H, int W, int x, int y, int check)
{
    int cnt=0;
    while(x<=N && y<=W)
    {
        cnt++;
        if(x<N && grid2[x+1][y])
            x++;
        else if(y<M && grid2[x][y+1])
            y++;
        else
            break;
    }
    return cnt==check;
}

int main()
{
    scanf("%d%d", &N, &M);
    int x=-1, y=-1;
    for(int i=1; i<=N; i++)
    {
        scanf("%s", grid[i]+1);
        for(int j=1; j<=M; j++)
        {
            if(grid[i][j]=='X' && x==-1)
                x=i, y=j;
            psum[i][j]+=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+(grid[i][j]=='X');
            if(grid[i-1][j]=='X' && grid[i][j-1]=='X' && grid[i-1][j-1]!='X')
            {
                printf("-1\n");
                return 0;
            }
        }
    }
    if(dfs(x, y)!=psum[N][M])
    {
        printf("-1\n");
        return 0;
    }
    for(int i=1; i<=N; i++)
    {
        int seen=0;
        for(int j=1; j<=M; j++)
            if(grid[i][j]=='X')
            {
                if(seen==2)
                {
                    printf("-1\n");
                    return 0;
                }
                seen=1;
            }
            else if(seen)
                seen=2;
    }
    for(int j=1; j<=M; j++)
    {
        int seen=0;
        for(int i=1; i<=N; i++)
            if(grid[i][j]=='X')
            {
                if(seen==2)
                {
                    printf("-1\n");
                    return 0;
                }
                seen=1;
            }
            else if(seen)
                seen=2;
    }
    int ans=0x3f3f3f3f;
    int xx, yy;
    for(xx=x; grid[xx][y]=='X' && xx<=N; xx++);
    if(grid[xx][y]!='X')
        xx--;
    for(yy=y; grid[x][yy]=='X' && yy<=M; yy++);
    if(grid[x][yy]!='X')
        yy--;
    int W=yy-y+1, H=xx-x+1, minW=0x3f3f3f3f, minH=0x3f3f3f3f;
    for(int j=1; j<=M-W+1; j++)
    {
        for(int i=1; i<=N; i++)
        {
            int cnt=get(i, j, i, j+W-1);
            if(cnt==W)
                LH[i][j]=LH[i-1][j]+1;
            else
                LH[i][j]=0;
        }
    }
    for(int i=1; i<=N-H+1; i++)
    {
        for(int j=1; j<=M; j++)
        {
            int cnt=get(i, j, i+H-1, j);
            if(cnt==H)
                LW[i][j]=LW[i][j-1]+1;
            else
                LW[i][j]=0;
        }
    }
    for(int i=1; i<=N-H+1; i++)
        for(int j=1; j<=M; j++)
            if(get(i, j, i+H-1, j)==H)
                grid2[i][j]=true;
    minW=1;
    for(int i=1; i<=N-H+1; i++)
        for(int j=1; j<=M; j++)
            if(grid2[i][j] && grid2[i-1][j] && grid2[i][j-1])
                minW=max(minW, LW[i][j]);
    memset(grid2, 0, sizeof grid2);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M-W+1; j++)
            if(get(i, j, i, j+W-1)==W)
                grid2[i][j]=true;
    minH=1;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M-W+1; j++)
            if(grid2[i][j] && grid2[i-1][j] && grid2[i][j-1])
                minH=max(minH, LH[i][j]);
    memset(grid2, 0, sizeof grid2);
    int check=0;
    for(int i=1; i<=N-H+1; i++)
        for(int j=1; j<=M-minW+1; j++)
            if(get(i, j, i+H-1, j+minW-1)==H*minW)
                grid2[i][j]=true, check++;
    bool Hok=true;
    for(int j=1; j<=M; j++)
    {
        int mini=0x3f3f3f3f, len=0;
        for(int i=1; i<=N; i++)
            if(grid[i][j]=='X')
                len++;
            else
            {
                if(len>0)
                    mini=min(mini, len);
                len=0;
            }
        if(len>0)
            mini=min(mini, len);
        if(mini<H)
        {
            Hok=false;
            break;
        }
    }
    if(Hok && ok(N-H+1, M-minW+1, x, y, check))
        ans=min(ans, H*minW);
    memset(grid2, 0, sizeof grid2);
    check=0;
    for(int i=1; i<=N-minH+1; i++)
        for(int j=1; j<=M-W+1; j++)
            if(get(i, j, i+minH-1, j+W-1)==minH*W)
                grid2[i][j]=true, check++;
    bool Wok=true;
    for(int i=1; i<=N; i++)
    {
        int mini=0x3f3f3f3f, len=0;
        for(int j=1; j<=M; j++)
            if(grid[i][j]=='X')
                len++;
            else
            {
                if(len>0)
                    mini=min(mini, len);
                len=0;
            }
        if(len>0)
            mini=min(mini, len);
        if(mini<W)
        {
            Wok=false;
            break;
        }
    }
    if(Wok && ok(N-minH+1, M-W+1, x, y, check))
        ans=min(ans, minH*W);
    printf("%d\n", ans==0x3f3f3f3f?-1:ans);
    return 0;
}