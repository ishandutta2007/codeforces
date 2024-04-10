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
int k,n,m;
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
int bx,by,s,ansx[1000000],ansy[1000000];
bool g[510][510];
char ansc[1000000];
int dfs(int x,int y)
{
    if(x>0&&y>0&&x<=n&&y<=m&&g[x][y]==0)
    {
        g[x][y]=1;
        s++;
        ansc[s]='B';ansx[s]=x;ansy[s]=y;
        int nx,ny;
        for(int i=0;i<4;i++)
        {
            nx=x+dx[i];ny=y+dy[i];
            dfs(nx,ny);
        }
        if(bx!=x||by!=y)
        {
            s++;ansc[s]='D';ansx[s]=x;ansy[s]=y;s++;ansc[s]='R';ansx[s]=x;ansy[s]=y;
        }
    }
}  
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    {
        char c;cin>>c;
        if(c=='#')g[i][j]=true;
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(!g[i][j])bx=i,by=j,dfs(i,j);
    cout<<s<<endl;
    for(int i=1;i<=s;i++)printf("%c %d %d\n",ansc[i],ansx[i],ansy[i]);
    return 0;
}