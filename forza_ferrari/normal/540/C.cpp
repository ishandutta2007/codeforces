#include<iostream>//
#include<cstdio>
#include<algorithm>
using namespace std;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int n,m,sx,sy,tx,ty;
bool vis[501][501];
inline void dfs(int x,int y)
{
    if(x==tx&&y==ty)
    {
        for(int i=0;i<4;++i)
        {
            int xx=x+dx[i],yy=y+dy[i];
            if(xx<=0||xx>n||yy<=0||yy>m||vis[xx][yy])
                continue;
            puts("YES");
            exit(0);
        }
        return;
    }
    for(int i=0;i<4;++i)
    {
        int xx=x+dx[i],yy=y+dy[i];
        if(xx<=0||xx>n||yy<=0||yy>m)
            continue;
        if(vis[xx][yy])
        {
            if(xx==tx&&yy==ty)
            {
                puts("YES");
                exit(0);
            }
            continue;
        }
        vis[xx][yy]=1;
        dfs(xx,yy);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            char c;
            cin>>c;
            vis[i][j]=c=='X';
        }
    cin>>sx>>sy>>tx>>ty;
    dfs(sx,sy);
    puts("NO");
    return 0;
}