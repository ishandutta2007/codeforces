#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#define oo 1000111222
using namespace std;
const int dx[]={-1,0,1,0,-1,-1,1,1};
const int dy[]={0,1,0,-1,-1,1,1,-1};

int n,m,ans,step,d[1010][1010],e[1010][1010];
string a[1010];

int ok(int x,int y,char c)
{
	return x>=0 && x<m && y>=0 && y<n && a[x][y]==c;
}

void checkCycle(int sx,int sy,int num1)
{
	int x=sx,y=sy,cnt=1;
	while (1)
	{
		int cntAdj=0,X=-1,Y=-1,nextToStart=0;
		e[x][y]=step;
		for (int i=0;i<4;i++)
		{
			int xx=x+dx[i],yy=y+dy[i];
			if (ok(xx,yy,'1') && d[xx][yy]==step)
			{
				cntAdj++;
				if (xx==sx && yy==sy) nextToStart=1;
				if (e[xx][yy]<step) X=xx, Y=yy;
			}
		}
		if (cntAdj!=2) return;
		if (ok(X,Y,'1')) x=X, y=Y, cnt++;
		else
			if (nextToStart) break;
			else return;
	} 
	if (cnt==num1) ans=max(ans,cnt);
}

void bfs(int x,int y)
{
	queue < pair<int,int> > q;
	int X=-1,Y=-1,num1=0,isBorder=0;
	q.push(make_pair(x,y));
	d[x][y]=++step;
	while (!q.empty())
	{
		pair <int,int> u=q.front(); q.pop();
		x=u.first; y=u.second;
		if (!x || !y || x+1==m || y+1==n) isBorder=1;
		for (int i=0;i<8;i++)
		{
			int xx=x+dx[i],yy=y+dy[i];
			if (ok(xx,yy,'0') && !d[xx][yy])
				d[xx][yy]=1, q.push(make_pair(xx,yy));
			if (ok(xx,yy,'1') && d[xx][yy]<step) 
			{
				d[xx][yy]=step;
				X=xx; Y=yy; 
				num1++;
			}
		}
	}
	if (num1 && !isBorder) checkCycle(X,Y,num1);
}

int main()
{
	cin >> m >> n;
	for (int i=0;i<m;i++) cin >> a[i];
	for (int i=0;i+1<m && ans<4;i++)
		for (int j=0;j+1<n && ans<4;j++)
			if (a[i][j]=='1' && a[i][j+1]=='1' && a[i+1][j]=='1' && a[i+1][j+1]=='1')
				ans=4;
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			if (!d[i][j] && ok(i,j,'0'))
				bfs(i,j);
	cout << ans << endl;
}