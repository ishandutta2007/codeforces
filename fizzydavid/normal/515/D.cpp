//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
char g[2011][2011];
short q[10001111],d[2011][2011];
int front,rear,n,m;
inline int getval()
{
	int __res=0;
	char __c;
	while((__c=getchar())!=' '&&__c!='\n')__res=__res*10+__c-'0';
	return __res;
}
int main()
{
	n=getval();m=getval();
	for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)g[i][j]=getchar();getchar();}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
		if(g[i][j]=='.')
		{
			d[i][j]=((g[i+1][j]=='.')+(g[i-1][j]=='.')+(g[i][j+1]=='.')+(g[i][j-1]=='.'));
			if(d[i][j]==1)q[rear++]=i,q[rear++]=j;
		}
	}
	while(front<rear)
	{
		short x=q[front++],y=q[front++],nx,ny,nnx,nny;bool f=0;
		if(g[x][y]!='.')continue;
		for(int i=0;i<4;i++)
		{
			nx=x+dx[i],ny=y+dy[i],--d[nx][ny];
			if(g[nx][ny]=='.')
			{
				if(i==0)g[x][y]='^',g[nx][ny]='v';
				else if(i==1)g[x][y]='v',g[nx][ny]='^';
				else if(i==2)g[x][y]='<',g[nx][ny]='>';
				else g[x][y]='>',g[nx][ny]='<';
				f=1;
				for(int j=0;j<4;j++)
				{
					nnx=nx+dx[j],nny=ny+dy[j],d[nnx][nny]--;
					if(g[nnx][nny]=='.'&&d[nnx][nny]==1){
						q[rear++]=nnx,q[rear++]=nny;
					}
				}
				break;
			}
		}
		if(f==0){puts("Not unique");return 0;}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(g[i][j]=='.'){puts("Not unique");return 0;}
	for(int i=1;i<=n;i++)printf("%s\n",g[i]+1);
	return 0;
}