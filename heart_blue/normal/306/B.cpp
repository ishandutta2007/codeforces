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
const int N = 2e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	vector<tuple<int, int, int>> vp;
	for (int i = 1; i <= m; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		r += l - 1;
		vp.emplace_back(l, -r, i);
	}
	sort(vp.begin(), vp.end());
	pair<int, int> maxv = { -1,-1 };
	int cur = -INF;
	set<int> ans;
	for (int i = 1; i <= m; i++)
		ans.insert(i);
	for (int i = 0; i < vp.size(); i++)
	{
		auto [l, r, id] = vp[i];
		r = -r;
		if (l <= cur + 1)
		{
			if (r > cur)
				maxv = max(maxv, { r,id });
			continue;
		}
		if (maxv.second != -1)
		{
			ans.erase(maxv.second);
			cur = maxv.first;
			maxv = { -1,-1 };
			i--;
			continue;
		}
		ans.erase(id);
		cur = r;
	}
	if (maxv.second != -1)
	{
		ans.erase(maxv.second);
	}
	printf("%d\n", ans.size());
	for (auto& x : ans)
		printf("%d ", x);
	return 0;
}