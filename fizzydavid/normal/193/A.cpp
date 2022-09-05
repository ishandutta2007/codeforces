#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>
using namespace std;
const int dx[4]={1,-1,0,0},dy[4]={0,0,-1,1};
int n,m,cnt,num,R=0;
bool u[55][55];
char g[55][55];
int dfs(int x,int y)
{
    cnt++;u[x][y]=1;
    for(int i=0;i<4;i++)
    {
        if(!u[x+dx[i]][y+dy[i]]&&g[x+dx[i]][y+dy[i]]=='#')dfs(dx[i]+x,dy[i]+y);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>g[i][j];
            if(g[i][j]=='#')num++;
        }
    }
    for(int i=1;i<=n&&!R;i++)
    {
        for(int j=1;j<=m&&!R;j++)
        {
            if(g[i][j]=='#')
            {
                g[i][j]='.';
                bool ff=1;
                for(int x=1;x<=n&&ff;x++)
                {
                    for(int y=1;y<=m&&ff;y++)
                    {
                        if(g[x][y]=='#')
                        {
                            for(int a=1;a<=n;a++)for(int b=1;b<=m;b++)u[a][b]=0;
                            ff=0;cnt=0;dfs(x,y);
                            if(cnt!=num-1)
                            {
                                R=1;
                            }
                        }
                    }
                }
                g[i][j]='#';
            }
        }
    }
    if(num>2)cout<<2-R;else cout<<"-1";                        
    return 0;
}