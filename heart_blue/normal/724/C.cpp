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
const int N = 2e5 + 10;
vector<tuple<int, int, int>> v1[N * 2], v2[N * 2];
LL ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		v1[x + y + N].push_back({ x,y,i });
		v2[x - y + N].push_back({ x,y,i });
	}
	for (int i = 0; i < N * 2; i++) if (!v1[i].empty()) sort(v1[i].begin(), v1[i].end());
	for (int i = 0; i < N * 2; i++) if (!v2[i].empty()) sort(v2[i].begin(), v2[i].end());
	MEM(ans, -1);
	int dx = 1, dy = 1;
	int cx = 0, cy = 0;
	LL cur = 0;
	auto check = [&](vector<tuple<int, int, int>> &v, int o)
	{
		if (v.empty()) return;
		if (o == -1) reverse(v.begin(), v.end());
		for (auto &p : v)
		{
			int x, y, pos;
			tie(x, y, pos) = p;
			if (ans[pos] == -1)
			{
				ans[pos] = cur + abs(x - cx);
			}
		}
		if (o == -1) reverse(v.begin(), v.end());
	};
	while (1)
	{
		if (dx*dy == 1) check(v2[cx - cy + N], dx);
		else check(v1[cx + cy + N], dx);
		int tx, ty;
		if (dx > 0) tx = n - cx;
		else tx = cx;
		if (dy > 0) ty = m - cy;
		else ty = cy;
		int t = min(tx, ty);
		cx += t*dx;
		cy += t*dy;
		int flag = 0;
		if (cx + dx < 0 || cx + dx > n) dx = -dx, flag++;
		if (cy + dy < 0 || cy + dy > m) dy = -dy, flag++;
		if (flag == 2) break;
		cur += t;
	}
	for (int i = 0; i < k; i++) printf("%lld\n", ans[i]);
	return 0;
}