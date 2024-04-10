#include<iostream>
#include<cstdio>
#include<algorithm>
int n,m,k,cnt;
char mp[501][501];
bool ans[501][501];
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
void dfs(int x,int y)
{
    if(x<=0||x>n||y<=0||y>m||mp[x][y]=='#'||ans[x][y])
        return;
    ++cnt;
    ans[x][y]=1;
    if(cnt==n*m-k)
    {
        for(register int i=1;i<=n;++i)
        {
            for(register int j=1;j<=m;++j)
                putchar(mp[i][j]=='#'? '#':ans[i][j]? '.':'X');
            puts("");
        }
        exit(0);
    }
    for(register int i=0;i<4;++i)
    {
        int xx=x+dx[i],yy=y+dy[i];
        dfs(xx,yy);
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=m;++j)
        {
            mp[i][j]=getchar();
            if(mp[i][j]!='.'&&mp[i][j]!='#')
                mp[i][j]=getchar();
            cnt+=mp[i][j]=='#';
        }
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=m;++j)
            if(mp[i][j]=='.')
                dfs(i,j);
    return 0;
}