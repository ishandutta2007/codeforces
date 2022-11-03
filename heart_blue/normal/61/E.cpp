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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const int INF = 1e9 + 7;
const int N = 1e6 + 10;
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
	void add(int x)
	{
		int ret = 0;
		while (x < N)
		{
			a[x]++;
			x += lowbit(x);
		}
	}
} b;
int res[N];
int a[N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	vector<int> v(a + 1, a + n + 1);
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
	}
	b.init();
	for (int i = 1; i <= n; i++)
	{
		b.add(a[i]);
		res[i] = i - b.sum(a[i]);
	}
	b.init();
	LL ans = 0;
	for (int i = n; i > 0; i--)
	{
		b.add(a[i]);
		ans += 1LL * res[i] * b.sum(a[i] - 1);
	}
	cout << ans << endl;
	return 0;
}