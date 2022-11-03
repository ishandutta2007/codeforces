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
class BIT
{
public:
	int a[N];
	void init()
	{
		MEM(a, 0);
	}
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
	int sum(int x)
	{
		int ret = 0;
		while (x)
		{
			ret += a[x];
			x -= lowbit(x);
		}
		return ret;
	}
}b;
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	b.init();
	for (int i = n; i >= 1; i--)
	{
		int x;
		cin >> x;
		x++;
		cnt[i - 1] += x - 1 - b.sum(x);
		b.add(x, 1);
	}
	b.init();
	for (int i = n; i >= 1; i--)
	{
		int x;
		cin >> x;
		x++;
		cnt[i - 1] += x - 1 - b.sum(x);
		b.add(x, 1);
	}
	for (int i = 1; i < n; i++)
	{
		cnt[i + 1] += cnt[i] / (i + 1);
		cnt[i] %= (i + 1);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		int l = 1, r = n;
		int key = 0;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (b.sum(mid) <= cnt[i]) key = mid, l = mid + 1;
			else r = mid - 1;
		}
		key++;
		b.add(key, -1);
		printf("%d ", key - 1);
	}
	return 0;
}