#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};

int m,n,x,y;
pair <int,int> f[1515][1515];
string a[1515];
bool d[1515][1515];

void dfs(int x,int y,int fx,int fy)
{
	if (!d[x][y]) f[x][y]=mp(fx,fy), d[x][y]=1;
	else
		if (f[x][y]!=mp(fx,fy))
		{
			puts("Yes");
			exit(0);
		}
		else return;
	rep(i,4)
	{
		int xx=(x+dx[i]+m)%m,yy=(y+dy[i]+n)%n,fxx=fx+dx[i],fyy=fy+dy[i];
		if (a[xx][yy]!='#') dfs(xx,yy,fxx,fyy);
	}
}

int main()
{
	cin >> m >> n;
	rep(i,m) cin >> a[i];
	rep(i,m) rep(j,n)
		if (a[i][j]=='S') x=i, y=j;
	dfs(x,y,x,y);
	puts("No");
}