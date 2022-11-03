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
const int N = 2e5 + 10;
class BIT
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
int L[N], R[N], pos[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int h, m, q;
	scanf("%d%d%d", &h, &m, &q);
	int used = 0;
	for (int i = 0; i < h; i++)
	{
		if (pos[i]) continue;
		int l = used + 1;
		int r = used + 1;
		int cur = i;
		while (pos[cur] == 0)
		{
			pos[cur] = ++used;
			r = used;
			cur = (cur + m) % h;
		}
		for (int i = l; i <= r; i++)
			L[i] = l, R[i] = r;
	}
	map<int, int> mc;
	LL ans = 0;
	while (q--)
	{
		char op;
		int id, x;
		scanf(" %c %d", &op, &id);
		if (op == '-')
		{
			int o = mc[id];
			mc.erase(id);
			b.add(o, -1);
		}
		else
		{
			scanf("%d", &x);
			x = pos[x];
			int l = L[x], r = R[x];
			if (b.sum(r) - b.sum(x - 1) == r - x + 1)
			{
				ans += r - x + 1;
				x = l;
			}
			int l1 = x, r1 = r;
			int key = r;
			while (l1 <= r1)
			{
				int mid = (l1 + r1) / 2;
				if (b.sum(mid) - b.sum(x - 1) == mid - x + 1) l1 = mid + 1;
				else key = mid, r1 = mid - 1;
			}
			ans += key - x;
			mc[id] = key;
			b.add(key, 1);
		}
	}
	printf("%lld\n", ans);
	return 0;
}