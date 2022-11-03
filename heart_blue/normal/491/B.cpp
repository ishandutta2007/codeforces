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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%*d%*d");
	vector<pair<int, int>> v1, v2;
	int n, h;
	scanf("%d", &n);
	while (n--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v1.emplace_back(x, y);
	}
	scanf("%d", &h);
	for (int i = 1; i <= h; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v2.emplace_back(x + y, x - y);
	}
	LL l = 0, r = 1000 * INF;
	LL ans = 0;
	int key = -1;
	while (l <= r)
	{
		LL mid = (l + r) / 2;
		LL lx = -INF * INF, rx = INF * INF, ly = -INF * INF, ry = INF * INF;
		for (auto& p : v1)
		{
			LL x, y;
			x = p.first, y = p.second;
			tie(x, y) = make_pair(x + y, x - y);
			lx = max(lx, x - mid);
			rx = min(rx, x + mid);
			ly = max(ly, y - mid);
			ry = min(ry, y + mid);
		}
		vector<int> v;
		for (int i = 0; i < v2.size(); i++)
		{
			int x, y;
			tie(x, y) = v2[i];
			if (x >= lx && x <= rx && y >= ly && y <= ry)
			{
				v.push_back(i + 1);
				break;
			}
		}
		if (v.empty()) l = mid + 1;
		else r = mid - 1, ans = mid, key = v.back();
	}
	printf("%lld\n", ans);
	printf("%d\n", key);
	return 0;
}