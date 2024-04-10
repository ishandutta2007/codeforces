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
const int N = 2e5 + 10;
int ans[N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<tuple<int, int, int>> vp1, vp2;
	for (int i = 1; i <= n; i++)
	{
		int x, r;
		cin >> x >> r;
		vp1.emplace_back(x, r, i);
	}
	MEM(ans, 0x3f);
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		vp2.emplace_back(x, y, i);
	}
	sort(vp1.begin(), vp1.end());
	sort(vp2.begin(), vp2.end());
	while (!vp1.empty() && !vp2.empty())
	{
		if (vp2.size() > 2)
		{
			int x1, y1, pos1;
			int x2, y2, pos2;
			tie(x1, y1, pos1) = vp2.back();
			tie(x2, y2, pos2) = vp2[vp2.size() - 2];
			if (x1 == x2 && y1 == y2)
			{
				vp2.pop_back();
				vp2.pop_back();
				vp2.emplace_back(x1, y1, min(pos1, pos2));
				continue;
			}
		}
		int x, r, pos1;
		int a, b, pos2;
		tie(x, r, pos1) = vp1.back();
		tie(a, b, pos2) = vp2.back();
		if (a < x - r)
		{
			vp1.pop_back();
			continue;
		}
		LL dx = x - a, dy = b - 0;
		if (dx * dx + dy * dy <= r * r)
		{
			ans[pos1] = min(ans[pos1], pos2);
			if (a == x - r)
			{
				vp1.pop_back();
				continue;
			}
		}
		vp2.pop_back();
	}
	printf("%d\n", n - count(ans + 1, ans + n + 1, 0x3f3f3f3f));
	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == 0x3f3f3f3f) ans[i] = -1;
		printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}