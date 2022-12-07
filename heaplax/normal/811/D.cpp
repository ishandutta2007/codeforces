#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define mp(a,b) make_pair(a,b)
char ch;void re(int& x)
{
	while(ch=getchar(),ch<33);x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
}
using namespace std;
typedef pair<int,int> pi;
char w[4]={'U','D','L','R'};
pi e,now=mp(1,1),to,d[4];
int n,m,go[101][101];
bool sx,sy,vis[101][101],ok[101][101];
pi operator + (pi a,pi b)
{
	a.first+=b.first;
	a.second+=b.second;
	return a;
}
void bfs(pi s)
{
	queue<pi> que;
	que.push(s);
	while(!que.empty())
	{
		pi now=que.front();que.pop();
		for(int i=0;i<4;++i)
		{
			pi to=now+d[i];
			int x=to.first,y=to.second;
			if(!vis[x][y] && ok[x][y])
			{
				vis[x][y]=1;
				go[x][y]=i^1;
				que.push(to);
			}
		}
	}
}
int main()
{
	re(n),re(m);
	d[0].first=-1;
	d[1].first=1;
	d[2].second=-1;
	d[3].second=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			while(ch=getchar(),ch<33);
			if(ch!='*')ok[i][j]=1;
			if(ch=='F')e=mp(i,j),vis[i][j]=1;
		}
	bfs(e);
	while(now != e)
	{
		int x=now.first,y=now.second;
		int g=go[x][y]<=1?go[x][y]^sx:go[x][y]^sy;
		putchar(w[g]);
		putchar('\n');
		fflush(stdout);
		re(to.first);
		re(to.second);
		if(to != now+d[g])
			go[x][y]<=1?sx=1:sy=1;
		now=to;
	}
}