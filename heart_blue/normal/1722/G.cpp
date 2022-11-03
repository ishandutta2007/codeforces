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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e1 + 10;
char str[N][N];
bool bfs(int n, int m, int x, int y)
{
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;
	q.emplace(x, y);
	str[x][y] = '.';
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		v.emplace_back(x, y);
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				int tx = x + i;
				int ty = y + j;
				if (tx < 1 || tx > n) continue;
				if (ty < 1 || ty > m) continue;
				if (str[tx][ty] != '*') continue;
				q.emplace(tx, ty);
				str[tx][ty] = '.';
			}
		}
	}
	if (v.size() != 3) return false;
	int u = INF, d = 0, l = INF, r = 0;
	for (auto [x, y] : v)
	{
		u = min(u, x);
		d = max(d, x);
		l = min(l, y);
		r = max(r, y);
	}
	return d - u == 1 && r - l == 1;

}
bool solve(int n, int m)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (str[i][j] != '*') continue;
			if (!bfs(n, m, i, j))
				return false;

		}
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		vector<int> v;
		int n;
		scanf("%d", &n);
		int cur = 0;
		if (n % 4 == 2) v = { 0b11111,0b00001,0b00010,0b00100,0b01000,0b10000 }, cur = 1 << 5;
		if (n % 4 == 1) v = { 0b1111,0b0001,0b0010,0b0100,0b1000 }, cur = 1 << 4;
		if (n % 4 == 3) v = { 0b11,0b01,0b10 }, cur = 1 << 2;
		while (v.size() < n)
		{
			v.push_back(cur);
			v.push_back(cur + 1);
			v.push_back(cur + 2);
			v.push_back(cur + 3);
			cur += 4;
		}
		for (int i = 0; i < n; i++)
			printf("%d%c", v[i], " \n"[i + 1 == n]);
	}
	return 0;
}