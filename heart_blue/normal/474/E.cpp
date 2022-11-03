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
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int pre[N];
class SegmentTree
{
public:
	pair<int,int> maxv[N * 4];
	int ql, qr;
	pair<int, int> qx;
	void set(int l, int r, pair<int, int> x = { -1,-1 })
	{
		ql = l, qr = r, qx = x;
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			maxv[o] = qx;
			return;
		}
		int mid = (l + r) >> 1;
		if (ql <= mid) update(l, mid, o << 1);
		if (qr > mid) update(mid + 1, r, o << 1 | 1);
		maxv[o] = max(maxv[o << 1], maxv[o << 1 | 1]);
	}
	pair<int,int> query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return maxv[o];
		}
		if (l == r) return { 0,0 };
		int mid = (l + r) >> 1;
		pair<int, int> r1 = { 0,0 }, r2 = { 0,0 };
		if (mid >= ql) r1 = query(l, mid, o << 1);
		if (qr > mid) r2 = query(mid + 1, r, o << 1 | 1);
		return max(r1, r2);
	}
} st;
LL a[N];
LL b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	pair<int, int> ans = { 0,0 };
	for (int i = 1; i <= n; i++)
	{
		int l = upper_bound(b + 1, b + n + 1, a[i] - d) - b - 1;
		int r = lower_bound(b + 1, b + n + 1, a[i] + d) - b;
		st.set(1, l);
		auto p1 = st.query(1, n);
		st.set(r, n);
		auto p2 = st.query(1, n);
		auto p = max(p1, p2);
		int x = p.first + 1;
		pre[i] = p.second;
		ans = max(ans, { x,i });
		int o = lower_bound(b + 1, b + n + 1, a[i]) - b;
		st.set(o, o, { x,i });
		st.update(1, n);
	}
	cout << ans.first << endl;
	int x = ans.second;
	vector<int> res;
	while (x)
	{
		res.push_back(x);
		x = pre[x];
	}
	reverse(res.begin(), res.end());
	for (auto &x : res) cout << x << ' ';
	return 0;
}