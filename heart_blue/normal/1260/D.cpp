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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int m, n, k, t;
	scanf("%d%d%d%d", &m, &n, &k, &t);
	for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
	sort(a + 1, a + m + 1);
	vector<tuple<int, int, int>> vp;
	while (k--)
	{
		int l, r, d;
		scanf("%d%d%d", &l, &r, &d);
		vp.emplace_back(l, r, d);
	}
	sort(vp.begin(), vp.end());
	int ans = 0;
	int l = 1, r = m;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		int minv = n + 1;
		int maxv = 0;
		int flag = 0;
		vector<pair<int, int>> v;
		for (auto& p : vp)
		{
			int l, r, d;
			tie(l, r, d) = p;
			if (d > a[mid])
			{
				v.emplace_back(l, r);
				flag = 1;
			}
		}
		int tot = 0;
		int cur = 0;
		for (auto& p : v)
		{
			int x, y;
			tie(x, y) = p;
			cur = max(x - 1, cur);
			tot += max(0, y - cur);
			cur = max(cur, y);
		}
		if (flag == 0 || tot * 2 + n + 1 <= t) ans = m - mid + 1, r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}