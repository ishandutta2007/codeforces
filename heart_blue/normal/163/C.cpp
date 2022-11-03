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
LL a[N];
LL ans[N];
bool solve(int x, int y, LL tot)
{
	if (x > y) return false;
	if (a[y + 1] - a[x - 1] <= tot) return false;
	LL cur = a[y] - a[x];
	LL lsum = min(a[x] - a[x - 1], tot - cur);
	LL rsum = a[y + 1] - a[y];
	if (lsum + cur < tot) rsum -= tot - (cur + lsum);
	ans[y - x + 1] += min(rsum, lsum);
	ans[0] -= min(rsum, lsum);
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	LL l, v1, v2;
	scanf("%d%lld%lld%lld", &n, &l, &v1, &v2);
	l *= v1 + v2;
	LL tot = l / (v1 + v2) * v2;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		a[i] *= v1 + v2;
		a[i + n] = a[i] + 2 * l;
	}
	ans[0] = 2 * l;
	int ptr = 1;
	a[0] = a[n] - 2 * l;
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		while (ptr <= 2 * n && a[ptr] - a[i] < tot)
			ptr++;
		vp.emplace_back(i, ptr - 1);
	}
	ptr = n * 2;
	for (int i = 2 * n; i > n; i--)
	{
		while (ptr >= 1 && a[i] - a[ptr] < tot)
			ptr--;
		if (ptr + 1 >= 1 && ptr + 1 <= n)
			vp.emplace_back(ptr + 1, i);
	}
	sort(vp.begin(), vp.end());
	vp.resize(unique(vp.begin(), vp.end()) - vp.begin());
	map<pair<int, int>, int> mc;
	queue<pair<int, int>> q;
	for (auto p : vp)
	{
		mc[p] = 1;
		q.push(p);
	}
	while (!q.empty())
	{
		auto p = q.front();
		q.pop();
		auto [l, r] = p;
		if (!solve(l, r, tot)) continue;
		if (!mc.count(make_pair(l + 1, r)) && l + 1 <= n)
		{
			mc[{l + 1, r}] = 1;
			q.emplace(l + 1, r);
		}
		if (!mc.count(make_pair(l, r - 1)))
		{
			mc[{l, r - 1}] = 1;
			q.emplace(l, r - 1);
		}
	}
	for (int i = 0; i <= n; i++)
	{
		printf("%.15f\n", ans[i] / (l * 2.0));
	}
	return 0;
}