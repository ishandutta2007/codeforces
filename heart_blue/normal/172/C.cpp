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
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<tuple<int, int, int>> vp;
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int t, x;
		scanf("%d%d", &t, &x);
		vp.emplace_back(t, x, i);
	}
	reverse(vp.begin(), vp.end());
	int cur = 0;
	while (!vp.empty())
	{
		map<int, vector<int>> mc;
		int tot = 0;
		int maxv = 0;
		while (!vp.empty() && tot < m)
		{
			tot++;
			int t, x, pos;
			tie(t, x, pos) = vp.back();
			vp.pop_back();
			cur = max(cur, t);
			maxv = max(maxv, x);
			mc[x].emplace_back(pos);
		}
		int o = 0;
		for (auto& p : mc)
		{
			int x = p.first;
			auto& v = p.second;
			for (auto& id : v)
			{
				ans[id] = cur + x + o;
			}
			o += v.size() / 2 + 1;
		}
		cur += 2 * maxv + o;
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", ans[i]);
	}
	return 0;
}