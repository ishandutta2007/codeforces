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
int cnt[N];
int last[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, m, a;
	scanf("%d%d%d%d", &n, &k, &m, &a);
	for (int i = 1; i <= a; i++)
	{
		int x;
		scanf("%d", &x);
		cnt[x]++;
		last[x] = i;
	}
	if (n == k)
	{
		for (int i = 1; i <= n; i++)
		{
			if (cnt[i] > 0) printf("1 ");
			else printf("%c ", "23"[a == m]);
		}
		puts("");
		return 0;
	}
	vector<tuple<int, int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		vp.emplace_back(cnt[i], -last[i], i);
	}
	sort(vp.rbegin(), vp.rend());
	for (int i = 0; i < k; i++)
	{
		int rest = k - i;
		int id = get<2>(vp[i]);
		if (get<0>(vp[i]) == 0)
		{
			if (m != a) ans[id] = 2;
			else ans[id] = 3;
			continue;
		}
		int cost = 0;
		for (int j = 1; j <= rest; j++)
		{
			cost += get<0>(vp[i]) - get<0>(vp[i + j]) + 1;
		}
		if (cost > m - a) ans[id] = 1;
		else ans[id] = 2;
	}
	for (int i = k; i < n; i++)
	{
		int need = get<0>(vp[k - 1]) + 1;
		auto [cur, key, id] = vp[i];
		if (need - cur > m - a) ans[id] = 3;
		else ans[id] = 2;
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);

	return 0;
}