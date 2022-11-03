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
class SegmentTree
{
public:
	int ql, qr, qx;
	int sumv[N * 4];
	void set(int l, int r, int x)
	{
		ql = l, qr = r, qx = x;
	}
	void add(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			sumv[o]++;
			return;
		}
		int mid = (l + r) / 2;
		if (ql <= mid) add(l, mid, o << 1);
		if (mid < qr) add(mid + 1, r, o << 1 | 1);
		sumv[o] = sumv[o << 1] + sumv[o << 1 | 1];
	}
	int query(int l, int r, int o = 1)
	{
		if (l == r)
		{
			return l;
		}
		int mid = (l + r) / 2;
		if (sumv[o << 1] >= qx) return query(l, mid, o << 1);
		else
		{
			qx -= sumv[o << 1];
			return query(mid + 1, r, o << 1 | 1);
		}
	}
} st;
vector<pair<int, int>> qr[N];
int a[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		vp.emplace_back(a[i], -i);
	}
	sort(vp.rbegin(), vp.rend());
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		int k, pos;
		scanf("%d%d", &k, &pos);
		qr[k].emplace_back(pos, i);
	}
	int len = 0;
	for (auto& p : vp)
	{
		len++;
		int id = -p.second;
		st.set(id, id, 1);
		st.add(1, n);
		for (auto& pp : qr[len])
		{
			int pos, id;
			tie(pos, id) = pp;
			st.set(1, n, pos);
			ans[id] = a[st.query(1, n)];
		}
	}
	for (int i = 1; i <= q; i++)
		printf("%d\n", ans[i]);
	return 0;
}