#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

queue<pii> q;

pii fa[2010][4010];

int num[2010][4010],a;
bool vis[2010][4010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void trans(int x,int y,int z)
{
	int xx=(x+z*a)/10,yy=y+(x+z*a)%10*a-z;
	if (abs(yy)>2000) return;
	if (!vis[xx][yy+2000]) vis[xx][yy+2000]=true,fa[xx][yy+2000]=pii(x,y),num[xx][yy+2000]=z,q.push(pii(xx,yy));
}

inline void trans1(int x,int y,int z)
{
	int xx=(x+z*a)/10,yy=y+(x+z*a)%10*a-z;
	if (abs(yy)>2000) return;
	if (!vis[xx][yy+2000]) vis[xx][yy+2000]=true,fa[xx][yy+2000]=pii(-1,-1),num[xx][yy+2000]=z,q.push(pii(xx,yy));
}

bool flag=false;

inline void print(pii hh)
{
	if (hh.first<0) return;
	if (num[hh.first][hh.second+2000]) flag=true;
	if (flag) putchar(num[hh.first][hh.second+2000]+'0');
	print(fa[hh.first][hh.second+2000]);
}

int main()
{
	a=rd();
	for (int i=1;i<10;i++) trans1(0,0,i);
	while (!q.empty())
	{
		pii hh=q.front();q.pop();
		if (!hh.first&&!hh.second) { print(hh);putchar('\n');return 0; }
		for (int i=0;i<10;i++) trans(hh.first,hh.second,i);
	}
	puts("-1");
	return 0;
}