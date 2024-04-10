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
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int R, C, sx, sy, ex, ey, dist[1010][1010];
char a[1010][1010];

void bfs(int x, int y)
{
	memset(dist, -1, sizeof(dist));
	queue < pair<int,int> > q;
	q.push(make_pair(x, y));
	dist[x][y] = 0;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i], yy = y + dy[i];
			if (xx >= 0 && xx < R && yy >= 0 && yy < C && a[xx][yy] != 'T' && dist[xx][yy] < 0)
			{
				dist[xx][yy] = dist[x][y] + 1;
				q.push(make_pair(xx, yy));
			}
		}
	}
}

int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++) scanf("%s", a[i]);
	
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			if (a[i][j] == 'S') sx = i, sy = j;
			if (a[i][j] == 'E') ex = i, ey = j;
		}
		
	bfs(ex, ey);
	int ans = 0;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (a[i][j] >= '0' && a[i][j] <= '9' && dist[i][j] >= 0 && dist[i][j] <= dist[sx][sy])
				ans += a[i][j] - '0';
				
	cout << ans << endl;
}