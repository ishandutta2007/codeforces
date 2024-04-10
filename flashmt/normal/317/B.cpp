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

int a[200][200], flag[200][200], step;

int main()
{
	int n, Q, z = 0, x, y;
	
	cin >> n >> Q;
	
	a[100][100] = n;
	
	vector < pair<int,int> > q[2];
	if (n >= 4) q[0].push_back(make_pair(100, 100));
	
	while (!q[z].empty())
	{
		step++;
		q[1 - z].clear();
		
		for (int i = 0; i < int(q[z].size()); i++)
		{
			int x = q[z][i].first, y = q[z][i].second;
			a[x][y] -= 4;
			if (a[x][y] >= 4) q[1 - z].push_back(make_pair(x, y)), flag[x][y] = step;
		}
		
		for (int i = 0; i < int(q[z].size()); i++)
		{
			int x = q[z][i].first, y = q[z][i].second;
			for (int j = 0; j < 4; j++)
			{
				int xx = x + dx[j], yy = y + dy[j];
				a[xx][yy]++;
				if (a[xx][yy] >= 4 && flag[xx][yy] < step)
				{
					flag[xx][yy] = step;
					q[1 - z].push_back(make_pair(xx, yy));
				}
			}
		}
		
		z ^= 1;
	}		
		
	while (Q--)
	{
		scanf("%d%d", &x, &y);
		if (x < -70 || x > 70 || y < -70 || y > 70) puts("0");
		else printf("%d\n", a[100 + x][100 + y]);
	}
}