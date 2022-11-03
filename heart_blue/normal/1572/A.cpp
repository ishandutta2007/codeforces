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
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) v[i].clear();
		set<int> s;
		for (int i = 1; i <= n; i++)
		{
			int sz;
			scanf("%d", &sz);
			deg[i] = sz;
			if (sz == 0)
				s.insert(i);
			while (sz--)
			{
				int x;
				scanf("%d", &x);
				v[x].push_back(i);
			}
		}
		int rest = n;
		int ans = 0;
		int cur = n + 1;
		while (!s.empty())
		{
			if (cur > *s.rbegin())
			{
				cur = 1;
				ans++;
			}
			int x = *s.lower_bound(cur);
			s.erase(x);
			cur = x;
			rest--;
			for (auto& y : v[x])
			{
				if (deg[y]-- == 1)
				{
					s.emplace(y);
				}
			}
		}
		if (rest > 0) ans = -1;
		printf("%d\n", ans);

	}
	return 0;
}