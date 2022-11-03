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
const int N = 1e5 + 10;
vector<int> v[N];
class BIT
{
public:
	int a[N];
	inline int lowbit(int x)
	{
		return x&-x;
	}
	void add(int x, int o)
	{
		while (x < N)
		{
			a[x] += o;
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
} b;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) b.add(i, 1);
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		v[x].push_back(i);
	}
	int cur = 0;
	LL ans = 0;
	for (int i = 1; i < N; i++)
	{
		if (v[i].empty()) continue;
		int l = -1;
		int r = -1;
		for (auto &x : v[i])
		{
			if (x >= cur) r = max(r, x);
			else l = max(l, x);
		}
		if (r != -1)
		{
			ans += b.sum(r) - b.sum(cur);
			for (auto &x : v[i])
			{
				if (x >= cur) b.add(x, -1);
			}
			cur = r;
		}
		if (l != -1)
		{
			ans += b.sum(n) - b.sum(cur);
			cur = 0;
			ans += b.sum(l) - b.sum(cur);
			cur = l;
			for (auto &x : v[i])
			{
				if (x <= cur) b.add(x, -1);
			}
		}
	}
	cout << ans << endl;
	return 0;
}