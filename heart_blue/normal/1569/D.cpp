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
map<int, map<int, int>> mc1, mc2;
LL solve(map<int, map<int, int>>& mc)
{
	LL ret = 0;
	for (auto& p1 : mc)
	{
		auto& m = p1.second;
		LL pre = 0;
		for (auto& p2 : m)
		{
			ret += pre * p2.second;
			pre += p2.second;
		}
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		vector<int> v1(n), v2(m);
		for (auto& x : v1) scanf("%d", &x);
		for (auto& x : v2) scanf("%d", &x);
		mc1.clear();
		mc2.clear();
		while (k--)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			auto iter1 = lower_bound(v1.begin(), v1.end(), x);
			auto iter2 = lower_bound(v2.begin(), v2.end(), y);
			if (*iter1 == x && *iter2 == y) continue;
			if (*iter1 != x)
			{
				mc1[iter1 - v1.begin()][y]++;
			}
			if (*iter2 != y)
			{
				mc2[iter2 - v2.begin()][x]++;
			}
		}
		LL ans = solve(mc1) + solve(mc2);
		printf("%lld\n", ans);
	}
	return 0;
}