#include<iostream>
#include<cstdlib>
using namespace std;
int n,m,k,c[510][510],cnt;
char a[510][510];
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int dfs(int x,int y)
{
    cnt++;c[x][y]=cnt;
    for(int i=0;i<4;i++)if(x>0&&y>0&&x<=n&&y<=m&&c[x+dx[i]][y+dy[i]]==0&&a[x+dx[i]][y+dy[i]]=='.')dfs(x+dx[i],y+dy[i]);
    if(k)k--,a[x][y]='X';
}
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(c[i][j]==0&&a[i][j]=='.')dfs(i,j);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}