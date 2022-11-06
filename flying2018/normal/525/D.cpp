#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define N 4010
using namespace std;
struct node{
	int x,y;
	node(int X=0,int Y=0):x(X),y(Y){}
};
bool mp[N][N];
int n,m;
char s[N];
queue<node>q;
inline void judge(int x,int y)
{
	if(1<=x && x<=n && 1<=y && y<=m && !mp[x][y] && (
		(mp[x-1][y] && mp[x][y-1] && mp[x-1][y-1]) ||
		(mp[x+1][y] && mp[x][y-1] && mp[x+1][y-1]) ||
		(mp[x-1][y] && mp[x][y+1] && mp[x-1][y+1]) ||
		(mp[x+1][y] && mp[x][y+1] && mp[x+1][y+1]))
	)q.push(node(x,y)),mp[x][y]=true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++) mp[i][j]=s[j]=='.';
	}
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<=m;j++) judge(i,j);
	while(!q.empty())
	{
		node u=q.front();
		q.pop();
		judge(u.x-1,u.y-1),judge(u.x-1,u.y),judge(u.x-1,u.y+1);
		judge(u.x,u.y-1),judge(u.x,u.y+1);
		judge(u.x+1,u.y-1),judge(u.x+1,u.y),judge(u.x+1,u.y+1);
	}
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=m;j++) putchar(mp[i][j]?'.':'*');
	return 0;
}