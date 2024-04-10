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
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const string DIRECTION = "URDL";

int valid(int x, int dx, int y, int dy)
{
	if (dx < 0) dx = -dx, x = -x;
	if (dy < 0) dy = -dy, y = -y;
	if (dx && dy) return abs(x) % dx == 0 && abs(y) % dy == 0 && x / dx == y / dy && x / dx >= 0;
	if (dx) return abs(x) % dx == 0 && x / dx >= 0 && y == 0;
	if (dy) return abs(y) % dy == 0 && y / dy >= 0 && x == 0;
	return x == 0 && y == 0;	
}

int main()
{
	int x, y, n, xx[111] = {0}, yy[111] = {0};
	string s;
	cin >> x >> y >> s;
	n = s.size();
	for (int i = 0; i < n; i++)
	{
		xx[i + 1] = xx[i];
		yy[i + 1] = yy[i];
		for (int j = 0; j < 4; j++)
			if (DIRECTION[j] == s[i])
			{
				xx[i + 1] += dx[j]; yy[i + 1] += dy[j];
				break;
			}
	}
			
	for (int i = 0; i <= n; i++)
	{
		int curx = x - xx[i], cury = y - yy[i];
		if (valid(curx, xx[n], cury, yy[n]))
		{
			puts("Yes"); return 0;
		}
	}
	
	puts("No");
}