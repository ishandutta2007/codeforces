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
const int N = 4e5 + 10;
class BIT
{
	int a[N];
public:
	void init()
	{
		MEM(a, 0);
	}
	inline int lowbit(int x)
	{
		return x & -x;
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
	void add(int x, int val)
	{
		while (x < N)
		{
			a[x] += val;
			x += lowbit(x);
		}
	}
} b;
int a[N];
int c[N];
LL getans(int n, int m)
{
	int minv = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] <= m) c[i] = 1;
		else c[i] = -1;
		c[i] += c[i - 1];
		minv = min(minv, c[i]);
	}
	b.init();
	for (int i = 1; i <= n; i++)
	{
		c[i] -= minv - 1;
	}
	LL ans = 0;
	b.add(-minv+1, 1);
	for (int i = 1; i <= n; i++)
	{
		b.add(c[i], 1);
		ans += b.sum(c[i]);
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cout << getans(n, m) - getans(n, m - 1) << endl;
	return 0;
}