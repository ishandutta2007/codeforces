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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
LL d[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		d[x] -= w;
		d[y] += w;
	}
	vector<pair<LL, int>> vp1, vp2;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] < 0) vp1.emplace_back(-d[i], i);
		if (d[i] > 0) vp2.emplace_back(d[i], i);
	}
	vector<tuple<int, int, LL>> ans;
	while (!vp1.empty() && !vp2.empty())
	{
		if (vp1.back().first == 0)
		{
			vp1.pop_back();
			continue;
		}
		if (vp2.back().first == 0)
		{
			vp2.pop_back();
			continue;
		}
		LL o = min(vp1.back().first, vp2.back().first);
		ans.emplace_back(vp1.back().second, vp2.back().second, o);
		vp1.back().first -= o;
		vp2.back().first -= o;
	}
	printf("%d\n", ans.size());
	for (auto [a, b, c] : ans)
	{
		printf("%d %d %lld\n", a, b, c);
	}
	return 0;
}