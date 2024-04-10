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
int flag[N];
vector<pair<int, int>> vp[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	int ks = 0;
	while (ncase--)
	{
		ks = 1;
		int n, k;
		scanf("%d%d", &n, &k);
		flag[0] = ks;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			a[i] = x;
			for (int j = 1; j <= x && j <= k; j++)
			{
				int l = j;
				int r = x / (x / l);
				flag[x / j] = 1;
				j = r;
			}
		}
		int maxv = a[n];
		int minv = a[1];
		int ans = INF;
		vector<int> key;
		for (int i = 0; i <= maxv; i++)
		{
			if (flag[i] != ks) continue;
			vp[i].clear();
			key.push_back(i);
		}
		for (int i = 1; i <= n; i++)
		{
			vp[a[i]].emplace_back(a[i], 1);
		}
		while (!key.empty())
		{
			int id = key.back();
			key.pop_back();
			ans = min(ans, id - minv);
			if (id == 0) break;
			int ok = 1;
			for (auto [x, o] : vp[id])
			{
				o = x / (x / o) + 1;
				if (o > k)
				{
					ok = 0;
					break;
				}
				int val = x / o;
				vp[val].emplace_back(x, o);
				minv = min(minv, val);
			}
			vp[id].clear();
			auto v = vector<pair<int, int>>();
			vp[id].swap(v);
			if (ok == 0) break;
		}

		printf("%d\n", ans);
	}
	return 0;
}