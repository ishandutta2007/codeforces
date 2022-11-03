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
int pos[N];
set<pair<int, int>> s[N];
int a[N];
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
		fill(pos + 1, pos + k + 1, 0);
		set<pair<int, int>> sp;
		for (int i = 1; i <= k; i++)
		{
			int x;
			scanf("%d", &x);
			a[i] = x;
			sp.emplace(x, i);
		}
		int o = 0;
		for (int i = 1; i < n; i++)
		{
			int t, r;
			scanf("%d%d", &t, &r);
			if (r == 1)
			{
				while (!sp.empty())
				{
					auto [x, id] = *sp.begin();
					if (x < i - o)
					{
						pos[id] = i;
						s[i].emplace(a[id], id);
						sp.erase(make_pair(a[id], id));
					}
					else break;
				}
			}
			if (t != 0)
			{
				o++;
				s[pos[t]].erase(make_pair(a[t], t));
				sp.erase(make_pair(a[t], t));
				pos[t] = 0;
				a[t]--;
				sp.emplace(a[t], t);
			}
		}
		string ans(k, 'N');

		for (int i = 1; i < n; i++)
		{
			if (!s[i].empty())
			{
				for (auto& [val, x] : s[i])
				{
					ans[x - 1] = 'Y';
				}
				int x = s[i].begin()->second;
				o += a[x];
				a[x] = 0;
				break;
			}
		}
		for (int i = 1; i <= k; i++)
		{
			if (a[i] < n - o)
				ans[i - 1] = 'Y';
		}
		puts(ans.c_str());
	}
	return 0;
}