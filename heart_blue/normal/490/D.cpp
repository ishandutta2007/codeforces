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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
map<LL, pair<int, pair<int, int>>> m1, m2;
int dx[] = { 3,2,2,1,1,1,1,1 };
int dy[] = { 1,1,1,1,3,2,2,1 };
void check(int a, int b, map<LL, pair<int, pair<int, int>>> &m)
{
	map<pair<int, int>, int> mp;
	mp[{a, b}] = 0;
	queue<pair<int, int>> q;
	q.push({ a,b });
	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		int o = mp[{x, y}];
		if (!m.count(1LL * x*y)) m[1LL * x*y] = { o,{x,y} };
		m[1LL * x*y] = min(m[1LL * x*y], { o,{x,y} });
		for (int i = 0; i < 8; i += 2)
		{
			if (x%dx[i] == 0 && y %dy[i] == 0)
			{
				int tx = x / dx[i] * dx[i + 1];
				int ty = y / dy[i] * dy[i + 1];
				if (!mp.count({ tx,ty }))
				{
					q.push({ tx,ty });
					mp[{tx, ty}] = o + 1;
				}
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	check(a, b, m1);
	check(c, d, m2);
	int ans = INF;
	pair<int, int> pa, pb;
	for (auto &p1 : m1)
	{
		if (m2.count(p1.first))
		{
			auto &p2 = m2[p1.first];
			if (ans > p1.second.first + p2.first)
			{
				ans = p1.second.first + p2.first;
				pa = p1.second.second;
				pb = p2.second;
			}
		}
	}
	if (ans == INF) puts("-1");
	else
	{
		printf("%d\n", ans);
		printf("%d %d\n", pa.first, pa.second);
		printf("%d %d\n", pb.first, pb.second);
	}
	return 0;
}