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
LL sum(LL a)
{
	return a * (a + 1) / 2;
}
LL check(int a, int b, int t)
{
	if (a > b) swap(a, b);
	if (a == 0) return 0;
	LL ret = 0;
	t = min(t, a + b - 1);
	if (t <= a) return sum(t);
	t -= a;
	ret += sum(a);
	if (t <= b - a) return ret + 1LL * t * a;
	t -= b - a;
	ret += 1LL * (b - a) * a;
	return ret + sum(a - 1) - sum(a - t - 1);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x, y, c;
	cin >> n >> x >> y >> c;
	if (c == 1) puts("0"), exit(0);
	vector<pair<int, int>> vp;
	vp.emplace_back(x - 1, y - 1);
	vp.emplace_back(x - 1, n - y);
	vp.emplace_back(n - x, y - 1);
	vp.emplace_back(n - x, n - y);
	vector<int> v;
	v.push_back(x - 1);
	v.push_back(n - x);
	v.push_back(y - 1);
	v.push_back(n - y);
	int l = 1, r = c;
	int ans = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		LL tot = 1;
		for (auto& x : v)
		{
			tot += min(mid, x);
		}
		for (auto& p : vp)
		{
			int x, y;
			tie(x, y) = p;
			tot += check(x, y, max(0, mid - 1));
		}
		if (tot >= c) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}