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
set<int> s[N];
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
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) s[i].clear();
		for (int i = 1; i <= n; i++) v[i].clear();
		memset(deg, 0, sizeof(int) * (n + 1));
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			s[x].insert(y);
			s[y].insert(x);
			deg[x]++;
			deg[y]++;
		}
		if (k == 1)
		{
			printf("%d\n", n - 1);
			continue;
		}
		priority_queue<pair<int, int>> pq;
		for (int i = 1; i <= n; i++)
		{
			if (deg[i] == 1)
			{
				int j = *s[i].begin();
				v[j].push_back(i);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (!v[i].empty())
			{
				pq.emplace(int(v[i].size()), i);
			}
		}
		int ans = 0;
		while (!pq.empty())
		{
			int sz, x;
			tie(sz, x) = pq.top();
			pq.pop();
			if (sz != v[x].size() || sz < k)
				continue;
			if (sz > k)
			{
				pq.emplace(sz - k, x);
			}
			sz = k;
			ans++;
			while (sz--)
			{
				int y = v[x].back();
				v[x].pop_back();
				s[x].erase(y);
				s[y].erase(x);
				deg[x]--;
				deg[y]--;
				if (deg[x] == 1)
				{
					int z = *s[x].begin();
					v[z].push_back(x);
					pq.emplace(int(v[z].size()), z);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}