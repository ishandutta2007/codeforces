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

int sz;
vector<int> vp[N * 4];
class SegmentTree
{
public:
	vector<int> v[N * 4];
	int ql, qr, qx;
	void set(int l, int r, int x = 1)
	{
		ql = l, qr = r, qx = x;
	}
	void build(int l, int r, int o = 1)
	{
		for (int i = l; i <= r; i++)
		{
			for (auto& x : vp[i])
				v[o].push_back(x);
		}
		sort(v[o].begin(), v[o].end());
		if (l == r) return;
		int mid = (l + r) / 2;
		build(l, mid, o << 1);
		build(mid + 1, r, o << 1 | 1);
	}
	int query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			auto iter = lower_bound(v[o].begin(), v[o].end(), qx);
			if (iter == v[o].end()) return sz + 1;
			else return *iter;
		}
		int mid = (l + r) / 2;
		int ret = INF;
		if (ql <= mid) ret = min(ret, query(l, mid, o << 1));
		if (mid < qr) ret = min(ret, query(mid + 1, r, o << 1 | 1));
		return ret;
	}
} st;
int ans[N];
vector<int> v;
void init(int sz)
{
	for (int i = 1; i <= sz; i++)
	{
		v.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (int i = 1; i <= sz; i++)
	{
		int o = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
		vp[o].push_back(i);
	}
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
		a[i + n] = a[i];
		a[i + 2 * n] = a[i];
	}
	sz = 3 * n;
	init(sz);
	a[sz + 1] = INF;
	int tot = v.size();
	st.build(1, tot);
	vector<int> s;
	s.push_back(sz + 1);
	ans[sz + 1] = sz + 1;
	for (int i = sz; i > 0; i--)
	{
		while (!s.empty() && a[i] >= a[s.back()])
		{
			s.pop_back();
		}
		int l = 1, r = lower_bound(v.begin(), v.end(), (a[i] + 1) / 2) - v.begin();
		pair<int, int> minv = make_pair(a[i], i);
		if (l <= r)
		{
			st.set(l, r, i);
			int res = st.query(1, tot);
			if (res >= s.back()) res = sz + 1;
			minv = make_pair(a[res], res);

		}
		if (minv.first * 2 < a[i])
		{
			ans[i] = minv.second;
		}
		else
		{
			ans[i] = ans[s.back()];
		}
		s.push_back(i);
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d%c", ans[i] == sz + 1 ? -1 : ans[i] - i, " \n"[i == n]);
	}
	return 0;
}