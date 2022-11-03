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
const int N = 3e5 + 10;
class Bit
{
public:
	int a[N];
	Bit()
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
			ret = max(ret, a[x]);
			x -= lowbit(x);
		}
		return ret;
	}
	void add(int x, int y)
	{
		while (x < N)
		{
			a[x] = max(a[x], y);
			x += lowbit(x);
		}
	}
} b;
vector<int> v;
int a[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	v.resize(n);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		v[i - 1] = a[i];
	}
	sort(v.begin(), v.end());

	for (int i = n; i > 0; i--)
	{
		int x = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
		int o = b.sum(x - 1);
		if (o == 0) ans[i] = -1;
		else ans[i] = o - i - 1;
		b.add(x, i);
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", ans[i]);
	}
	return 0;
}