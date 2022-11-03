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
const int N = 2e5 + 10;
class Node
{
public:
	int a, b, h;
	void init()
	{
		scanf("%d%d%d", &a, &b, &h);
	}
	bool operator < (Node &node)
	{
		if (b != node.b) return b > node.b;
		else return a > node.a;
	}
}p[N];
class BIT
{
public:
	LL a[N];
	BIT()
	{
		MEM(a, 0);
	}
	inline int lowbit(int x)
	{
		return x&-x;
	}
	LL sum(int x)
	{
		LL ret = 0;
		while (x)
		{
			ret = max(ret, a[x]);
			x -= lowbit(x);
		}
		return ret;
	}
	LL add(Node &node)
	{
		LL o = sum(node.b - 1) + node.h;
		int x = node.a;
		while (x < N)
		{
			a[x] = max(a[x], o);
			x += lowbit(x);
		}
		return o;
	}
} bb;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		p[i].init();
		v.push_back(p[i].a);
		v.push_back(p[i].b);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		p[i].a = lower_bound(v.begin(), v.end(), p[i].a) - v.begin() + 1;
		p[i].b = lower_bound(v.begin(), v.end(), p[i].b) - v.begin() + 1;
	}
	sort(p, p + n);
	LL ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans = max(ans, bb.add(p[i]));
	}
	printf("%lld\n", ans);
	return 0;
}