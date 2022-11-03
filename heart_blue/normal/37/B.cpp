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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e2 + 10;
vector<pair<int, int>> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, maxv, delta;
	cin >> n >> maxv >> delta;
	vector<pair<int, int>> ans;
	int cur = maxv;
	int t = 0;
	int d = 0;
	for (int i = 1; i <= n; i++)
	{
		int p, d;
		cin >> p >> d;
		v[p].emplace_back(d, i);
	}
	for (int i = 1; i <= 100; i++)
	{
		sort(v[i].begin(), v[i].end());
	}
	while (1)
	{
		cur = min(cur - d + delta, maxv);
		if (cur <= 0) break;
		pair<int, int> res = { -1,-1 };
		for (int i = 100; i >= 1; i--)
		{
			if (cur * 100 <= maxv * i)
			{
				if (!v[i].empty())
				{
					res = max(res, make_pair(v[i].back().first, i));
				}
			}
			else break;
		}
		if (res.first != -1)
		{
			int o = res.second;
			ans.emplace_back(t, v[o].back().second);
			v[o].pop_back();
			d += res.first;
			t++;
		}
		else
		{
			if (cur - d + delta >= cur)
			{
				puts("NO");
				return 0;
			}
			t++;
		}
	}
	puts("YES");
	printf("%d %d\n", t, ans.size());
	for (auto& p : ans)
		printf("%d %d\n", p.first, p.second);
	return 0;
}