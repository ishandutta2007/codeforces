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
const int N = 1e5 + 10;
class BIT
{
	int a[N];
public:
	void init()
	{
		MEM(a, 0);
	}
	void add(int x, int val)
	{
		while (x < N)
		{
			a[x] = max(a[x], val);
			x += x & -x;
		}
	}
	int sum(int x)
	{
		int ret = 0;
		while (x)
		{
			ret = max(ret, a[x]);
			x -= x & -x;
		}
		return ret;
	}
} b;
int a[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	swap(n, m);
	while (m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		a[l]++;
		a[r + 1]--;
	}
	a[1]++;
	for (int i = 1; i <= n; i++)
	{
		a[i] += a[i - 1];
	}
	for (int i = 1; i <= n; i++)
	{
		int x = b.sum(a[i]);
		ans[i] += x;
		b.add(a[i], x + 1);
	}
	b.init();
	for (int i = n; i >= 1; i--)
	{
		if (a[i] == 0) continue;
		int x = b.sum(a[i]);
		ans[i] += x;
		b.add(a[i], x + 1);
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		res = max(res, ans[i] + 1);
	}
	printf("%d\n", res);
	return 0;
}