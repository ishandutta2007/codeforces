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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
class BIT
{
public:
	LL a[N];
	inline int lowbit(int x)
	{
		return x & -x;
	}
	void add(int x, int y)
	{
		while (x < N)
		{
			a[x] += y;
			x += lowbit(x);
		}
	}
	LL sum(int x)
	{
		LL ret = 0;
		while (x)
		{
			ret += a[x];
			x -= lowbit(x);
		}
		return ret;

	}
} b, b2;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	LL t;
	scanf("%d%lld", &n, &t);
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		vp.push_back({ a[i],i });
		b.add(i, a[i]);
		b2.add(i, 1);
	}
	sort(vp.begin(), vp.end());
	LL ans = 0;
	int cur = 1;
	while (b2.sum(n) != 0)
	{
		LL tot = b.sum(n);
		ans += t / tot * vp.size();
		t %= tot;
		LL pre = b.sum(cur - 1);
		if (tot - pre <= t)
		{
			t -= tot - pre;
			ans += b2.sum(n) - b2.sum(cur - 1);
			cur = 1;
		}
		pre = b.sum(cur - 1);
		int l = cur, r = n;
		int o = cur - 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (b.sum(mid) - pre <= t) o = mid, l = mid + 1;
			else r = mid - 1;
		}
		t -= b.sum(o) - b.sum(cur - 1);
		ans += b2.sum(o) - b2.sum(cur - 1);
		while (!vp.empty() && vp.back().first > t)
		{
			int pos = vp.back().second;
			b.add(pos, -a[pos]);
			b2.add(pos, -1);
			vp.pop_back();
		}
		cur = o + 1;
		if (cur > n) cur = 1;
	}
	printf("%lld\n", ans);
	return 0;
}