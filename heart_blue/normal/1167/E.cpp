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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
int a[N];
int l[N];
int r[N];
class BIT
{
	int a[N];
public:
	void add(int x, int val)
	{
		if (x == 0)
		{
			a[x] += val;
			return;
		}
		while (x < N)
		{
			a[x] += val;
			x += x & -x;
		}
	}
	int sum(int x)
	{
		int ret = 0;
		while (x)
		{
			ret += a[x];
			x -= x & -x;
		}
		return ret + a[x];
	}
} b;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i] = x;
		if (l[x] == 0) l[x] = i;
		r[x] = i;
	}
	LL ans = 0;
	int cur = 0;
	b.add(0, 1);
	for (int i = 1; i <= m; i++)
	{
		if (l[i] < cur && l[i] != 0) break;
		ans = i;
		cur = max(cur, r[i]);
		b.add(cur, 1);
	}
	if (ans == m)
	{
		printf("%lld\n", 1LL * m * (m + 1) / 2);
		return 0;
	}
	cur = n + 1;
	for (int i = m; i >= 1; i--)
	{
		if (r[i] > cur) break;
		if (l[i])
			cur = min(cur, l[i]);
		ans += b.sum(cur - 1);
	}
	printf("%lld\n", ans + 1);
	return 0;
}