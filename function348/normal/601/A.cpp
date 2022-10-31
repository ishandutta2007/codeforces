#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
const int N=500;
struct rec{int x,y,kd,d;};
int n,m,ans;
int a[N][N];
int v[N][N][2];
queue<rec>Q;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y]=a[y][x]=1;
	}
	Q.push((rec){1,1,0,0});
	v[1][1][0]=1;ans=-1;
	while (!Q.empty())
	{
		rec now=Q.front();Q.pop(); 
		if (now.x==n&&now.y==n&&!now.kd) { ans=now.d;break;}
		if (!now.kd)
		{
			for (int j=1;j<=n;j++)
			if (a[now.x][j]||(now.x==n&&j==n))
			if (!v[j][now.y][1])
			{
				v[j][now.y][1]=1;
				Q.push((rec){j,now.y,1,now.d+1});
	//			printf("%d %d %d %d\n",j,now.y,1,now.d+1);
			}
		}
		else
		{
			for (int j=1;j<=n;j++)
			if (!a[now.y][j]&&(now.y!=j||now.y==n))
			if (!v[now.x][j][0]&&(now.x!=j||now.x==n))
			{
				v[now.x][j][0]=1;
				Q.push((rec){now.x,j,0,now.d});
	//			printf("%d %d %d %d\n",now.x,j,0,now.d);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}