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

int n,a[2020][2020],square,circle,d[2020][2020];

void bfs(int x,int y)
{
	int maxX=x,minX=x,maxY=y,minY=y,cnt=1;
	queue < pair<int,int> > q;
	q.push(mp(x,y)); d[x][y]=1;
	while (!q.empty())
	{
		pair <int,int> u = q.front(); q.pop();
		x=u.fi; y=u.se;
		rep(i,4)
		{
			int xx=x+dx[i],yy=y+dy[i];
			if (xx && yy && xx<=n && yy<=n && a[xx][yy] && !d[xx][yy])
			{
				d[xx][yy]=1; cnt++;
				q.push(mp(xx,yy));
				minX=min(minX,xx); maxX=max(maxX,xx);
				minY=min(minY,yy); maxY=max(maxY,yy);
			}
		}
	}
	if (cnt==(maxX-minX+1)*(maxY-minY+1)) square++;
	else circle++;
}

int main()
{
	cin >> n;
	fr(i,1,n)
		fr(j,1,n)
			scanf("%d",&a[i][j]);
	
	fr(i,1,n)
		fr(j,1,n)
			if (a[i][j] && !d[i][j])
				bfs(i,j);
				
	cout << circle << ' ' << square << endl;
}