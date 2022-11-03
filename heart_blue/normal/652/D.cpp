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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
const LL INF = 1e9 + 7;
const int N = 4e5 + 10;
vector<tuple<int, int, int>> vp;
vector<int> v;
class BIT
{
public:
	int a[N];
	int lowbit(int x)
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
} b;
int getid(int x)
{
	return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v.push_back(x);
		v.push_back(y);
		vp.push_back({ x,y,i });
	}
	sort(v.begin(), v.end());
	for (auto &p : vp)
	{
		int x, y, i;
		tie(x, y, i) = p;
		x = getid(x);
		y = getid(y);
		p = { x,y,i };
	}
	sort(vp.begin(), vp.end(), [](tuple<int, int, int> &t1, tuple<int, int, int> &t2)->bool
	{
		int a, b, c;
		int x, y, z;
		tie(a, b, c) = t1;
		tie(x, y, z) = t2;
		if (b != y) return b < y;
		if (a != x) return a < x;
		return c < z;
	});
	for (auto &p : vp)
	{
		int x, y, pos;
		tie(x, y, pos) = p;
		ans[pos] = b.sum(y) - b.sum(x - 1);
		b.add(x, 1);
	}
	for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
	return 0;
}