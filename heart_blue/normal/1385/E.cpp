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
int cnt[N];
vector<int> v[N];
int deg[N];
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
		for (int i = 1; i <= n; i++) v[i].clear();
		memset(deg, 0, sizeof(int) * (n + 1));
		memset(cnt, 0, sizeof(int) * (n + 1));
		vector<tuple<int, int, int>> vp;
		while (m--)
		{
			int o, x, y;
			scanf("%d%d%d", &o, &x, &y);
			vp.emplace_back(o, x, y);
			if (o == 1)
			{
				v[x].push_back(y);
				deg[y]++;
			}
		}
		queue<int> q;
		for (int i = 1; i <= n; i++)
		{
			if (deg[i] == 0)
				q.push(i);
		}
		int tot = 0;
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			tot++;
			cnt[x] = tot;
			for (auto& y : v[x])
			{
				if (deg[y]-- == 1)
					q.push(y);
			}
		}
		if (tot != n)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for (auto [o, x, y] : vp)
		{
			if (o == 0 && cnt[x] > cnt[y]) swap(x, y);
			printf("%d %d\n", x, y);
		}
	}
	return 0;
}