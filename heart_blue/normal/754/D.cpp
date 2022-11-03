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
const int N = 1e6 + 10;
vector<pair<int, int>> vp, v0;
vector<int> v[N], vv;
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
	void add(int x, int y)
	{
		while (x < N)
		{
			a[x] += y;
			x += lowbit(x);
		}
	}
	int getans(int k)
	{
		int res = 0;
		int tot = sum(N - 1);
		int l = 0, r = N - 1;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (tot - sum(mid) >= k) res = mid + 1, l = mid + 1;
			else r = mid - 1;
		}
		return res;
	}
} b;
inline int idx(int x)
{
	return lower_bound(vv.begin(), vv.end(), x) - vv.begin();
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v0.push_back({ x,y });
		vp.push_back({ x,y });
		vv.push_back(x);
		vv.push_back(y);
	}
	vv.push_back(-INF);
	sort(vv.begin(), vv.end());
	sort(vp.begin(), vp.end(), [](pair<int, int> &p1, pair<int, int> &p2) -> bool
	{
		if (p1.first != p2.first) return p1.first < p2.first;
		return p1.second > p2.second;
	});
	int ptr = 0;
	pair<int, int> ans = { -1,-1 };
	for (auto &p : vp)
	{
		v[idx(p.second)].push_back(idx(p.second));
	}
	int ptr2 = 0;
	for (auto &p : vp)
	{
		while (ptr2 < vp.size() && vp[ptr2].first <= p.first)
		{
			b.add(idx(vp[ptr2++].second), 1);
		}
		int qq = idx(p.first);
		while (ptr < qq)
		{
			while (!v[ptr].empty())
			{
				b.add(v[ptr].back(), -1);
				v[ptr].pop_back();
			}
			ptr++;
		}
		int o = vv[b.getans(k)];
		o = min(o, p.second);
		ans = max(ans, { o - p.first,o });
	}
	cout << ans.first + 1 << endl;
	int r = ans.second, l = r - ans.first;
	if (ans.first == -1) l = INF, r = -INF;
	for (int i = 0; i < n && k > 0; i++)
	{
		if (v0[i].first <= l && v0[i].second >= r)
		{
			cout << i + 1 << ' ';
			k--;
		}
	}
	return 0;
}