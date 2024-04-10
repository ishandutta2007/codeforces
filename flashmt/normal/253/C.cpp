#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int d[111][100100];

int main()
{
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n,a[111],sx,sy,fx,fy;
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i], a[i]++;
	cin >> sx >> sy >> fx >> fy;
	
	memset(d,-1,sizeof(d));
	d[sx][sy] = 0;
	queue < pair<int,int> > q;
	q.push(make_pair(sx,sy));
	while (!q.empty())
	{
		pair <int,int> u = q.front(); q.pop();
		int x = u.first, y = u.second;
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i], yy = min(a[xx], y + dy[i]);
			if (xx && yy && xx <= n && yy <= a[xx] && d[xx][yy] < 0)
				d[xx][yy] = d[x][y] + 1, q.push(make_pair(xx,yy));
		}
	}
	
	cout << d[fx][fy] << endl;
}