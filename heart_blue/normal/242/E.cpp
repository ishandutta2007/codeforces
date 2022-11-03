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
const int N = 4e5 + 10;
const int M = 22;
class SegmentTree
{
public:
	int ql, qr, qx;
	int xorv[N];
	int sumv[N];
	void init()
	{
		MEM(xorv, 0);
		MEM(sumv, 0);
	}
	void set(int ql, int qr, int qx)
	{
		this->ql = ql;
		this->qr = qr;
		this->qx = qx;
	}
	void pushdown(int o, int len)
	{
		if (xorv[o])
		{
			xorv[o << 1] ^= 1;
			xorv[o << 1 | 1] ^= 1;
			sumv[o << 1] = (len - len / 2) - sumv[o << 1];
			sumv[o << 1 | 1] = len / 2 - sumv[o << 1 | 1];
			xorv[o] = 0;
		}
	}
	void maintain(int o)
	{
		sumv[o] = sumv[o << 1] + sumv[o << 1 | 1];
	}
	int query(int l, int r, int o = 1)
	{
		if (ql <= l && qr >= r)
		{
			return sumv[o];
		}
		int mid = (l + r) >> 1;
		pushdown(o, r - l + 1);
		int ans = 0;
		if (ql <= mid) ans += query(l, mid, o << 1);
		if (qr > mid) ans += query(mid + 1, r, o << 1 | 1);
		return ans;
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && qr >= r)
		{
			xorv[o] ^= 1;
			sumv[o] = r - l + 1 - sumv[o];
			return;
		}
		int mid = (l + r) >> 1;
		pushdown(o, r - l + 1);
		if (ql <= mid) update(l, mid, o << 1);
		if (qr > mid) update(mid + 1, r, o << 1 | 1);
		maintain(o);
	}
} st[M];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 0; i < M; i++) st[i].init();
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		for (int j = 0; j < M; j++)
		{
			if (x >> j & 1) st[j].set(i, i, 1), st[j].update(1, n);
		}
	}
	int q;
	cin >> q;
	while (q--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int l, r;
			cin >> l >> r;
			LL ans = 0;
			for (int i = 0; i < M; i++)
			{
				st[i].set(l, r, 0);
				ans += (1LL << i)*st[i].query(1, n);
			}
			cout << ans << '\n';
		}
		else
		{
			int l, r, x;
			cin >> l >> r >> x;
			for (int i = 0; i < M; i++)
			{
				if (x >> i & 1) st[i].set(l, r, 1), st[i].update(1, n);
			}
		}
	}
	return 0;
}