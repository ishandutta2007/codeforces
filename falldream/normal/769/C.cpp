#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
using namespace std;
inline int read()
{
   int  x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
   return x*f;
}
int n,m,x=0,y=0,k;
char s[1005][1005];
int d[1005][1005];
char ans[1000005];
struct node{
    int x,y;
}newx;
queue<node> q;
const int dis[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void bfs()
{
    q.push((node){x,y});d[x][y]=1;
    while(!q.empty())
    {
        newx=q.front();q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=newx.x+dis[i][0];
            int yy=newx.y+dis[i][1];
            if(xx<1||yy<1||xx>n||yy>m||d[xx][yy]||s[xx][yy]=='*') continue;
            d[xx][yy]=d[newx.x][newx.y]+1;
            q.push((node){xx,yy});
        }
    }
}

int main()
{
    n=read();m=read();k=read();
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    for(int i=1;i<=n&&!x;i++)
        for(int j=1;j<=m&&!x;j++)
            if(s[i][j]=='X')
            {x=i;y=j;s[i][j]='.';}
    bfs();
    for(int i=1;i<=k;i++)
    {
        if(x<n&&s[x+1][y]=='.'&&d[x+1][y]<=k-i+1){ans[i]='D';++x;continue;}
        if(y>1&&s[x][y-1]=='.'&&d[x][y-1]<=k-i+1){ans[i]='L';--y;continue;}
        if(y<m&&s[x][y+1]=='.'&&d[x][y+1]<=k-i+1){ans[i]='R';++y;continue;}
        if(x>1&&s[x-1][y]=='.'&&d[x-1][y]<=k-i+1){ans[i]='U';--x;continue;}
        return 0*puts("IMPOSSIBLE");
    }
    for(int i=1;i<=k;i++)printf("%c",ans[i]);
    return 0;
}