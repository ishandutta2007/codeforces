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
set<int> s[250];
char str[N];
int flag[N];
class BIT
{
public:
	int a[N];
	inline int lowbit(int x)
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
	void add(int x, int val)
	{
		while (x < N)
		{
			a[x] += val;
			x += lowbit(x);
		}
	}
} b;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	MEM(flag, 0);
	scanf("%d%d", &n, &q);
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++)
	{
		s[str[i]].insert(i);
	}
	for (int i = 1; i <= n; i++) b.add(i, 1);
	while (q--)
	{
		int l, r;
		char o;
		scanf("%d %d %c", &l, &r, &o);
		if (s[o].empty()) continue;
		int L = *s[o].begin();
		int R = *s[o].rbegin();
		int key = n + 1;
		while (L <= R)
		{
			int mid = (L + R) >> 1;
			int x = *s[o].lower_bound(mid);
			if (b.sum(x) >= l) key = x, R = mid - 1;
			else L = mid + 1;
		}
		vector<int> v;
		while (!s[o].empty())
		{
			auto iter = s[o].lower_bound(key);
			if (iter == s[o].end()) break;
			if (b.sum(*iter) > r) break;
			v.push_back(*iter);
			key = *iter + 1;
		}
		for (auto &x : v)
		{
			flag[x] = 1;
			s[o].erase(x);
			b.add(x, -1);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (flag[i]) continue;
		putchar(str[i]);
	}

	return 0;
}