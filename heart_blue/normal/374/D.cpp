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
const int N = 1e6 + 10;
struct BIT
{
public:
	int a[N];
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
} b;
int a[N];
int ans[N];
string str;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	str.reserve(N);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &a[i]);
	}
	int sz = 1;
	while (n--)
	{
		int x;
		scanf("%d", &x);
		if (x >= 0)
		{
			b.add(sz, 1);
			ans[sz++] = x;
			continue;
		}
		for (int i = 1; i <= m; i++)
		{
			int cur = a[i] - i + 1;
			if (b.sum(N - 1) < cur) break;
			int l = 1, r = sz;
			int key = -1;
			while (l <= r)
			{
				int mid = (l + r) / 2;
				if (b.sum(mid) >= cur) key = mid, r = mid - 1;
				else l = mid + 1;
			}
			b.add(key, -1);

		}
	}
	if (b.sum(N - 1) == 0) puts("Poor stack!");
	else
	{
		for (int i = 1; i < sz; i++)
		{
			if (b.sum(i) - b.sum(i - 1) > 0)
				str += char('0' + ans[i]);
		}
		puts(str.c_str());
	}
	return 0;
}