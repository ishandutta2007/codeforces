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
const int N = 2e5 + 10;
vector<pair<LL, int>> v[N];
pair<LL, int> maxv[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<int, int> mc;
	int cur = 0;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int c, x;
		scanf("%d%d", &c, &x);
		if (!mc.count(c))
			mc[c] = cur++;
		v[mc[c]].emplace_back(x, i);
	}
	sort(v, v + cur, [](const vector<pair<LL, int>>& v1, const vector<pair<LL, int>>& v2)->bool
		{
			return v1.size() < v2.size();
		});
	tuple<LL, int, int, int, int> ans = make_tuple(0LL, 0, 0, 0, 0);
	for (int i = 0; i < cur; i++)
	{
		sort(v[i].rbegin(), v[i].rend());
		for (int j = 1; j < v[i].size(); j++)
		{
			v[i][j].first += v[i][j - 1].first;
		}
		for (int j = 0; j < v[i].size(); j++)
		{
			for (int o = -1; o <= 1; o++)
			{
				if (j + o < 0) continue;
				if (maxv[j + o].first == 0) continue;
				ans = max(ans, make_tuple(v[i][j].first + maxv[j + o].first, i, j, maxv[j + o].second, j + o));
			}
		}
		for (int j = 0; j < v[i].size(); j++)
		{
			maxv[j] = max(maxv[j], make_pair(v[i][j].first, i));
		}
	}
	LL res;
	int key1, sz1, key2, sz2;
	tie(res, key1, sz1, key2, sz2) = ans;
	if (sz1 < sz2) swap(sz1, sz2), swap(key1, key2);
	printf("%lld\n", res);
	printf("%d\n", sz1 + sz2 + 2);
	while (sz1 >= 0 || sz2 >= 0)
	{
		printf("%d ", v[key1][sz1].second);
		sz1--;
		swap(key1, key2);
		swap(sz1, sz2);
	}
	return 0;
}