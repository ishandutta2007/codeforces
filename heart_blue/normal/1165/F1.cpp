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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e5 + 10;
int a[N];
int cost[N];
int last[N];
vector<int> v[N];
vector<pair<int, int>> vp;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &cost[i]);
		sum += cost[i];
	}
	vp.resize(m);
	for (auto &p : vp)
	{
		scanf("%d%d", &p.first, &p.second);
	}
	int l = 1, r = 4e5 + 10;
	int ans = r;
	while (l <= r)
	{
		MEM(a, 0);
		MEM(last, 0);
		int mid = (l + r) >> 1;
		int tot = mid;
		for (int i = 1; i <= mid; i++) v[i].clear();
		for (auto &p : vp)
		{
			if (p.first > mid) continue;
			last[p.second] = max(last[p.second], p.first);
		}
		for (int i = 1; i < N; i++)
		{
			if (last[i] == 0) continue;
			v[last[i]].push_back(i);
		}
		int cur = 0;
		for (int i = 1; i <= mid; i++)
		{
			cur++;
			while (!v[i].empty() && cur > 0)
			{
				int x = v[i].back();
				int o = min(cur, cost[x]);
				tot -= o;
				cur -= o;
				a[x] += o;
				if (a[x] == cost[x]) v[i].pop_back();
			}
		}
		for (int i = 1; i <= n; i++)
		{
			tot -= (cost[i] - a[i]) * 2;
		}
		if (tot >= 0) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}