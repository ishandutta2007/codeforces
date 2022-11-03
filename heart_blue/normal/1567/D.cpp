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
class SegmentTree
{
public:
	int minv[N * 4];
	int addv[N * 4];
	int ql, qr, qx;
	void set(int l, int r, int x = 0)
	{
		ql = l, qr = r, qx = x;
	}
	inline void pushdown(int o)
	{
		if (addv[o])
		{
			addv[o << 1] += addv[o];
			addv[o << 1 | 1] += addv[o];
			minv[o << 1] += addv[o];
			minv[o << 1 | 1] += addv[o];
			addv[o] = 0;
		}
	}
	void add(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			addv[o] += qx;
			minv[o] += qx;
			return;
		}
		pushdown(o);
		int mid = (l + r) / 2;
		if (ql <= mid) add(l, mid, o << 1);
		if (mid < qr) add(mid + 1, r, o << 1 | 1);
		minv[o] = min(minv[o << 1], minv[o << 1 | 1]);
	}
	int query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return minv[o];
		}
		pushdown(o);
		int mid = (l + r) / 2;
		int ret = INF;
		if (ql <= mid) ret = min(ret, query(l, mid, o << 1));
		if (mid < qr) ret = min(ret, query(mid + 1, r, o << 1 | 1));
		return ret;
	}
} st;
int sum[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		int o = 1e9;
		vector<int> v;
		while (o)
		{
			while (n >= o)
			{
				v.push_back(o);
				n -= o;
			}
			o /= 10;
		}
		while (v.size() < k)
		{
			for (int i = v.size() - 1; i >= 0; i--)
			{
				if (v[i] >= 10)
				{
					int x = v[i] / 10;
					v[i] = 0;
					int cnt = 10;
					while (cnt--)
						v.push_back(x);
					break;
				}
			}
			sort(v.rbegin(), v.rend());
			v.pop_back();
		}
		while (v.size() > k)
		{
			int x = v.back();
			v.pop_back();
			v.back() += x;
		}
		for (int i = 0; i < v.size(); i++)
			printf("%d%c", v[i], " \n"[i + 1 == v.size()]);
	}
	return 0;
}