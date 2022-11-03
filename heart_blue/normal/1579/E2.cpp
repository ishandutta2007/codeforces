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
const int N = 2e5 + 10;
int n;
class BIT
{
public:
	int a[N];
	void init()
	{
		fill(a + 1, a + n + 1, 0);
	}
	void add(int x, int val)
	{
		while (x <= n)
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
		return ret;
	}
} b;
void refrain(vector<int>& v)
{
	vector<int> v0 = v;
	sort(v0.begin(), v0.end());
	for (auto& x : v)
	{
		x = lower_bound(v0.begin(), v0.end(), x) - v0.begin() + 1;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%d", &n);
		b.init();
		LL ans = 0;
		vector<int> v(n);
		for (auto& x : v)
			scanf("%d", &x);
		refrain(v);
		for (auto& x : v)
		{
			b.add(x, 1);
			ans += min(b.sum(x - 1), b.sum(n) - b.sum(x));
		}
		printf("%lld\n", ans);
	}
	return 0;
}