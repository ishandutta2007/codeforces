#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define N 800
using namespace std;
int ax[N*N],ay[N*N],cnt;
int sx[N*N],sy[N*N],tot;
char str[N];
int num[N][N],swp[N][N];//0:U,1:D,2:L,3:R
void rotate(int x,int y)
{
    ax[++cnt]=x,ay[cnt]=y;
    if(num[x][y]==2) num[x][y]=num[x][y+1]=0,num[x+1][y]=num[x+1][y+1]=1;
	else num[x][y]=num[x+1][y]=2,num[x][y+1]=num[x+1][y+1]=3;
}
void dfs(int x,int y)
{
    if(num[x][y]==2) return;
    if(num[x][y+1]==2)
	{
		dfs(x+1,y+1);
		rotate(x,y+1),rotate(x,y);
	}
    else rotate(x,y);
}
int n,m;
void work(void)
{
    bool chg=false;
	if(m&1)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) swp[j][i]=num[i][j]^2;
        memcpy(num,swp,sizeof(num));
		swap(n,m);
        chg=true;
	}
    cnt=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(num[i][j]==0) dfs(i,j);
	if(chg)
    {
        for(int i=1;i<=cnt;i++) swap(ax[i],ay[i]);
        swap(n,m);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(num,-1,sizeof(num));
    for(int i=1;i<=n;i++)
    {
        scanf("%s",str+1);
        for(int j=1;j<=m;j++)
        if(str[j]=='U') num[i][j]=0;
        else if(str[j]=='D') num[i][j]=1;
        else if(str[j]=='L') num[i][j]=2;
        else if(str[j]=='R') num[i][j]=3;
    }
    work();
    memcpy(sx,ax,sizeof(sx));
    memcpy(sy,ay,sizeof(sy));
    memset(num,-1,sizeof(num));
    tot=cnt;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",str+1);
        for(int j=1;j<=m;j++)
        if(str[j]=='U') num[i][j]=0;
        else if(str[j]=='D') num[i][j]=1;
        else if(str[j]=='L') num[i][j]=2;
        else if(str[j]=='R') num[i][j]=3;
    }
    work();
    printf("%d\n",cnt+tot);
    for(int i=1;i<=tot;i++) printf("%d %d\n",sx[i],sy[i]);
    for(int i=cnt;i>=1;i--) printf("%d %d\n",ax[i],ay[i]);
    return 0;
}