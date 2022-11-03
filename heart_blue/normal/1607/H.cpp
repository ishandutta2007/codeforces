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
map<int, vector<tuple<int, int, int, int>>> mc;
int ans[N];
int key[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		mc.clear();
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int a, b, m;
			scanf("%d%d%d", &a, &b, &m);
			key[i] = m;
			int l, r, t;
			{
				int o = min(m, a);
				l = a - o;
				t = o;
			}
			{
				int o = min(m, b);
				r = a - (m - o);
			}
			mc[a + b - m].emplace_back(r, l, t, i);
		}
		int tot = 0;
		for (auto& p : mc)
		{
			auto& vp = p.second;
			sort(vp.begin(), vp.end());
			int pre = -INF;
			for (auto& p : vp)
			{
				int l, r, t, pos;
				tie(r, l, t, pos) = p;
				if (pre >= l)
				{
					ans[pos] = t - (pre - l);
				}
				else
				{
					tot++;
					pre = r;
					ans[pos] = t - (pre - l);
				}
			}
		}
		printf("%d\n", tot);
		for (int i = 1; i <= n; i++)
		{
			printf("%d %d\n", ans[i], key[i] - ans[i]);
		}
	}
	return 0;
}