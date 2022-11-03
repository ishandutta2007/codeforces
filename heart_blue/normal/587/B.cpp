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
class BIT
{
public:
	LL a[N];
	int sz;
	void init(int n)
	{
		sz = n;
		fill(a, a + n + 1, 0);
	}
	void add(int x, LL val)
	{
		if (val < 0) val += INF;
		while (x <= sz)
		{
			a[x] += val;
			if (a[x] >= INF) a[x] -= INF;
			x += x & -x;
		}
	}
	LL sum(int x)
	{
		int ret = 0;
		while (x)
		{
			ret += a[x];
			if (ret >= INF) ret -= INF;
			x -= x & -x;
		}
		return ret;
	}
} b;
int a[N];
LL ans[N];
void refrain(int n)
{
	vector<int> v(a, a + n);
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (int i = 0; i < n; i++)
	{
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	LL len;
	scanf("%d%lld%d", &n, &len, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	refrain(n);
	LL res = 0;
	for (int o = 0; o < k; o++)
	{
		if (o == 0)
		{
			for (int i = 0; i < n; i++)
				ans[i] = 1;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				ans[i] = b.sum(a[i]);
			}
		}
		b.init(n);
		for (int i = 0; i < n; i++)
		{
			b.add(a[i], ans[i]);
		}
		int r = (len - 1) % n;
		if ((len - 1) / n < o)
		{
			break;
		}
		LL key = (len - 1) / n - o + 1;
		key %= INF;
		for (int i = 0; i < n; i++)
		{
			LL tot = 0;
			if (i <= r) tot = key;
			else tot = key - 1;
			res += tot * ans[i] % INF;
		}
	}
	res %= INF;
	if (res < 0) res += INF;
	printf("%lld\n", res);
	return 0;
}