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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int ans[N];
int res[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		int cur = 0;
		deque<pair<int, int>> q;
		fill(res, res + n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			q.emplace_back(x, i);
		}
		vector<tuple<int, int, int>> vp;
		for (int i = 1; i <= m; i++)
		{
			int id, x;
			scanf("%d%d", &id, &x);
			vp.emplace_back(x, id, i);
		}
		sort(vp.rbegin(), vp.rend());
		while (!vp.empty())
		{
			auto [k, id, pos] = vp.back();
			vp.pop_back();
			while (cur < k && q.front().first != n)
			{
				auto p1 = q.front();
				q.pop_front();
				auto p2 = q.front();
				q.pop_front();
				if (p1 < p2) swap(p1, p2);
				res[p1.second]++;
				q.emplace_front(p1);
				q.emplace_back(p2);
				cur++;
			}
			if (q.front().first == n)
			{
				res[q.front().second] += k - cur;
				cur = k;
			}
			ans[pos] = res[id];
		}
		for (int i = 1; i <= m; i++)
			printf("%d\n", ans[i]);
	}
	return 0;
}