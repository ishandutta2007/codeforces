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
const int N = 1e6 + 10;
int ans[N];
LL getx(int x1, int y1, int x2, int y2)
{
	if (y1 == y2) return -1;
	int dx = x2 - x1;
	int dy = y2 - y1;
	if (1LL * y1 * dx % dy) return -1;
	return x1 - 1LL * dx * y1 / dy;
}
bool check(int x1, int y1, int x2, int y2)
{
	return 1LL * x1 * y2 - 1LL * x2 * y1 == 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<pair<int, int>> vp;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		vp.emplace_back(y, x);
	}
	sort(vp.begin(), vp.end());
	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2, x3, y3;
		tie(y1, x1) = vp[i];
		for (int j = i + 1; j < m; j++)
		{
			tie(y2, x2) = vp[j];
			LL pos = getx(x1, y1, x2, y2);
			if (pos < 1 || pos > n) continue;
			int cnt = 2;
			for (int k = j + 1; k < m; k++)
			{
				tie(y3, x3) = vp[k];
				if (check(x2 - x1, y2 - y1, x3 - x1, y3 - y1))
					cnt++;
			}
			ans[pos] = max(ans[pos], cnt);
		}
	}
	LL res = 0;
	for (int i = 1; i <= n; i++)
		res += max(1, ans[i]);
	printf("%lld\n", res);
	return 0;
}