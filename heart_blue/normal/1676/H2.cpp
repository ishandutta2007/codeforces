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
int cnt[N];
int a[N];
int b[N];
struct BIT
{
public:
	int a[N];
	void init(int n)
	{
		fill(a, a + n + 1, 0);
	}
	void add(int x, int val)
	{
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
		return ret;
	}
} bb;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		fill(cnt, cnt + n + 1, 0);
		bb.init(n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			cnt[a[i]]++;
		}
		for (int i = 1; i <= n; i++)
			cnt[i] += cnt[i - 1];
		LL ans = 0;
		for (int i = 1; i <= n; i++)
		{
			b[i] = cnt[a[i]]--;
			bb.add(b[i], 1);
			ans += i - bb.sum(b[i]);
		}
		printf("%lld\n", ans);
	}

	return 0;
}