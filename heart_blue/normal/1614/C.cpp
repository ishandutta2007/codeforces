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
int a[N];
LL p2[N];
void init()
{
	p2[0] = 1;
	for (int i = 1; i < N; i++)
	{
		p2[i] = p2[i - 1] * 2 % INF;
	}
}
LL solve(int n, vector<tuple<int, int, int>>& vp, int o)
{
	fill(a + 1, a + n + 1, 1);
	int cur = 1;
	for (auto& [l, r, t] : vp)
	{
		if (t >> o & 1) continue;
		cur = max(cur, l);
		while (cur <= r)
			a[cur++] = 0;
	}
	int cnt = count(a + 1, a + n + 1, 1);
	if (cnt == 0) return 0;
	return p2[n - 1] * p2[o] % INF;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		vector<tuple<int, int, int>> vp(m);
		for (auto& [l, r, t] : vp)
		{
			scanf("%d%d%d", &l, &r, &t);
		}
		sort(vp.begin(), vp.end());
		LL ans = 0;
		for (int o = 0; o < 30; o++)
		{
			ans += solve(n, vp, o);
		}
		printf("%lld\n", ans % INF);
	}
	return 0;
}