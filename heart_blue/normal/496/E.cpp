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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<tuple<int, int, int, int>> vp;
	set<pair<int, int>> sp;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		vp.emplace_back(b, -i, a, -i);
	}
	int m;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int c, d, k;
		scanf("%d%d%d", &c, &d, &k);
		vp.emplace_back(d, i, c, k);
	}
	sort(vp.begin(), vp.end());
	for (auto [r, id, l, k] : vp)
	{
		if (id < 0)
		{
			sp.emplace(l, -id);
		}
		else
		{
			while (k--)
			{
				auto iter = sp.lower_bound(make_pair(l, -1));
				if (iter == sp.end()) break;
				ans[iter->second] = id;
				sp.erase(*iter);
			}
		}
	}
	if (!sp.empty()) puts("NO");
	else
	{
		puts("YES");
		for (int i = 1; i <= n; i++)
			printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}