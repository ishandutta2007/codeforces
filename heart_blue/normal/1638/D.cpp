#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
int vis[N][N];
int dx[] = { 0,0,1,1 };
int dy[] = { 0,1,0,1 };
int a[N][N];
int n, m;
bool check(int x, int y)
{
	if (x == n || y == m) return false;
	if (x < 1 || y < 1) return false;
	if (vis[x][y]) return false;
	set<int> s;
	for (int i = 0; i < 4; i++)
	{
		s.emplace(a[x + dx[i]][y + dy[i]]);
	}
	s.erase(0);
	return s.size() <= 1;
}
int getnum(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int val = a[x + dx[i]][y + dy[i]];
		if (val) return val;
	}
	return 0;
}
inline bool blank(char ch) { return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t'; }

inline void read(int& x) {
	bool sign = 0; char ch = getchar(); x = 0;
	for (; blank(ch); ch = getchar());
	for (; ch >= '0' && ch <= '9'; ch = getchar())x = x * 10 + ch - '0';
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	read(n);
	read(m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			read(a[i][j]);
		}
	}
	queue<pair<int, int>> q;

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (check(i, j))
				q.emplace(i, j), vis[i][j] = 1;
		}
	}
	vector<tuple<int, int, int>> ans;
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		int val = getnum(x, y);
		if (val)
		{
			ans.emplace_back(x, y, val);
		}
		else
		{
			continue;
		}
		
		for (int o = 0; o < 4; o++)
			a[x + dx[o]][y + dy[o]] = 0;
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				int tx = x + i;
				int ty = y + j;
				if (check(tx, ty))
				{
					int val = getnum(tx, ty);
					if (val)
					{
						q.emplace(tx, ty);
						vis[tx][ty] = 1;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (count(a[i] + 1, a[i] + m + 1, 0) != m)
		{
			puts("-1");
			return 0;
		}
	}
	reverse(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (auto& [x, y, c] : ans)
	{
		printf("%d %d %d\n", x, y, max(c, 1));
	}
	return 0;
}