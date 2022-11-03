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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e5 + 10;
pair<pair<int, int>, pair<int, int>> p[N];
int dx[] = { 1,-1,1,-1 };
int dy[] = { 1,1,-1,-1 };
inline int dis(pair<int, int>& p1, pair<int, int>& p2)
{
	int dx = p1.first - p2.first;
	int dy = p1.second - p2.second;
	return dx * dx + dy * dy;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	int cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		for (int o = 0; o < 4; o++)
		{
			p[cnt++] = make_pair(make_pair(x * dx[o], y * dy[o]), make_pair(i + 1, o + 1));
		}
	}
	sort(p, p + cnt);
	tuple<int, pair<int, int>, pair<int, int>> ans;
	get<0>(ans) = INF;
	for (int i = 0; i < cnt; i++)
	{
		for (int j = i + 1; j < cnt; j++)
		{
			int dx = p[i].first.first - p[j].first.first;
			if (dx * dx >= get<0>(ans)) break;
			if (p[i].second.first == p[j].second.first) continue;
			ans = min(ans, make_tuple(dis(p[i].first, p[j].first), p[i].second, p[j].second));
		}
	}
	pair<int, int> p1, p2;
	tie(ignore, p1, p2) = ans;
	printf("%d %d %d %d\n", p1.first, p1.second, p2.first, 5 - p2.second);
	return 0;
}