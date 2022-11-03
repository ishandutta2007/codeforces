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
const int N = 2e6 + 10;
const int M = 2e3 + 10;
int a[N];
int ans[N];
pair<int, int> p1[M], p2[M];
vector<pair<int, int>> key;
vector<tuple<int, int, int>> vp;
class SegmentTree
{
public:
	int maxv[N * 4];
	int ql, qr, qx;
	void set(int l, int r, int x = 0)
	{
		ql = l, qr = r, qx = x;
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			maxv[o] = max(maxv[o], qx);
			return;
		}
		int mid = (l + r) / 2;
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
	}
	int query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return maxv[o];
		}
		int ret = maxv[o];
		int mid = (l + r) / 2;
		if (ql <= mid) ret = max(ret, query(l, mid, o << 1));
		if (mid < qr) ret = max(ret, query(mid + 1, r, o << 1 | 1));
		return ret;
	}
} st;
int main()
{
	//freopen("input.txt", "r", stdin);1
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d%d", &p1[i].first, &p1[i].second);
	int maxv = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &p2[i].first, &p2[i].second);
		int x, y;
		tie(x, y) = p2[i];
		maxv = max(maxv, x);
		a[x] = max(a[x], y);
	}

	for (int i = maxv; i >= 0; i--)
	{
		a[i] = max(a[i], a[i + 1]);
	}
	for (int i = 0; i <= maxv; i++)
	{
		int j = i;
		for (j = i; j <= maxv; j++)
		{
			if (a[j] != a[i])
				break;
		}
		j--;
		key.emplace_back(i, j);
		i = j;
	}
	int tot = 1e6 + 10;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		tie(x, y) = p1[i];
		for (auto& p : key)
		{
			int l, r;
			tie(l, r) = p;
			if (r >= x && a[r] >= y)
			{
				st.set(max(0, l - x), r - x, a[l] - y + 1);
				st.update(0, tot);
			}
		}
	}
	int ans = INF;
	for (int i = 0; i <= tot; i++)
	{
		st.set(i, i);
		ans = min(ans, i + st.query(0, tot));
	}
	printf("%d\n", ans);
	return 0;
}