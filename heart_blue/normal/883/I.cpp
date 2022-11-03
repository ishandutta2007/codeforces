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
const int N = 3e5 + 10;
int a[N];
int n, k;
class BIT
{
public:
	int a[N];
	void init()
	{
		MEM(a, 0);
	}
	int lowbit(int x)
	{
		return x&-x;
	}
	void add(int x)
	{
		while (x < N)
		{
			a[x]++;
			x += lowbit(x);
		}
	}
	int sum(int x)
	{
		if (x < 0) return 0;
		int ret = 0;
		while (x)
		{
			ret += a[x];
			x -= lowbit(x);
		}
		return ret;
	}
} b;
bool check(int x)
{
	if (a[k] - a[1] > x) return false;
	b.init();
	b.add(k);
	for (int i = k + 1; i <= n; i++)
	{
		int l = i - k + 1;
		if (a[i] - a[l] > x) continue;
		int key = lower_bound(a + 1, a + i, a[i] - x) - a;
		if (key == 1)
		{
			b.add(i);
			continue;
		}
		if (b.sum(l - 1) - b.sum(key - 2) > 0)
		{
			b.add(i);
		}
	}
	return b.sum(n) - b.sum(n - 1) > 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 0, r = INF;
	int ans = r;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}