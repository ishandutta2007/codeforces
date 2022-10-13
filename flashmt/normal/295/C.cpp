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
const int BASE = int(1e9) + 7;

int n, k, X, Y, f[55][55][2];
long long c[55][55], way[55][55][2];
queue < pair<pair<int,int>,int> > q;

int main()
{
	//freopen("c.in", "r", stdin);
	int u;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &u);
		if (u == 50) X++;
		else Y++;
	}
	
	for (int i = 0; i < 55; i++)
		for (int j = 0; j <= i; j++)
			c[i][j] = j ? (c[i - 1][j] + c[i - 1][j - 1]) % BASE : 1;
	
	memset(f, -1, sizeof(f));
	f[X][Y][0] = 0; way[X][Y][0] = 1;
	q.push(make_pair(make_pair(X, Y), 0));
	
	while (!q.empty())
	{
		int x = q.front().first.first, y = q.front().first.second, z = q.front().second;
		q.pop();
		
		for (int i = 0; i <= x; i++)
			for (int j = 0; j <= y; j++)
				if (i + j && i * 50 + j * 100 <= k)
				{
					long long curWay = way[x][y][z] * c[x][i] % BASE * c[y][j] % BASE;
					int xx = X - x + i, yy = Y - y + j;
					if (f[xx][yy][z ^ 1] < 0)
					{
						f[xx][yy][z ^ 1] = f[x][y][z] + 1;
						way[xx][yy][z ^ 1] = curWay;
						q.push(make_pair(make_pair(xx, yy), z ^ 1));
					}
					else
						if (f[xx][yy][z ^ 1] == f[x][y][z] + 1)
							way[xx][yy][z ^ 1] = (way[xx][yy][z ^ 1] + curWay) % BASE;
				}
	}
	
	cout << f[X][Y][1] << endl << way[X][Y][1] << endl;
}