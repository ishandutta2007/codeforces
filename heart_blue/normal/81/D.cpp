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
const int N = 1e3 + 10;
vector<int> key[N];
int sz[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	vector<pair<int, int>> vp;
	for (int i = 1; i <= m; i++)
	{
		int x;
		scanf("%d", &x);
		sz[i] = min(n / 2, x);
		vp.emplace_back(sz[i], i);
	}
	sort(vp.rbegin(), vp.rend());
	int tot = n;
	while (tot--)
	{
		tot = tot * 1;
		int cur = 0;
		for (auto [x, i] : vp)
		{
			if (sz[i] == 0) continue;
			for (int j = 1; j <= n; j++)
			{
				cur++;
				if (cur > n) cur = 1;
				if (ans[cur]) continue;
				int l = cur - 1;
				if (l == 0) l = n;
				int r = cur + 1;
				if (r > n) r = 1;
				if (ans[l] == i || ans[r] == i) continue;
				ans[cur] = i;
				sz[i]--;
				if (sz[i] == 0) break;
			}
		}
	}
	if (count(ans + 1, ans + n + 1, 0) > 0) puts("-1");
	else
	{
		for (int i = 1; i <= n; i++)
			printf("%d ", ans[i]);
	}
	return 0;
}