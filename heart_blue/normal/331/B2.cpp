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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int a[N];
int pos[N];
class BIT
{
public:
	int a[N];
	void add(int x, int va)
	{
		while (x < N)
		{
			a[x] += va;
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
set<pair<int, int>> sp;
int n;
void combine(int x, int y)
{
	if (x > y) swap(x, y);
	if (x == 0) return;
	if (y == n + 1) return;
	if (pos[x] > pos[y]) return;
	int l1, r1, l2, r2;
	tie(r1, l1) = *sp.lower_bound(make_pair(x, -1));
	tie(r2, l2) = *sp.lower_bound(make_pair(y, -1));
	if (l1 == l2) return;
	b.add(l2, -1);
	sp.erase(make_pair(r1, l1));
	sp.erase(make_pair(r2, l2));
	sp.emplace(r2, l1);
}
void split(int x)
{
	int l, r;
	tie(r, l) = *sp.lower_bound(make_pair(x, -1));
	sp.erase(make_pair(r, l));
	sp.emplace(x, x);
	b.add(x, 1);
	b.add(l, -1);
	if (x > l)
	{
		b.add(l, 1);
		sp.emplace(x - 1, l);
	}
	if (x < r)
	{
		b.add(x + 1, 1);
		sp.emplace(r, x + 1);
	}
}
void add(int x)
{
	combine(x - 1, x);
	combine(x, x + 1);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
		sp.emplace(i, i);
	for (int i = 1; i <= n; i++)
		b.add(i, 1);
	for (int i = 1; i <= n; i++)
		add(i);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1)
		{
			printf("%d\n", b.sum(y) - b.sum(x) + 1);
		}
		else
		{
			int vx = a[x], vy = a[y];
			split(a[x]);
			split(a[y]);
			swap(a[x], a[y]);
			swap(pos[vx], pos[vy]);
			add(a[x]);
			add(a[y]);
		}
	}
	return 0;
}