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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
class SegmentTree
{
public:
	int minv[N * 4];
	int maxv[N * 4];
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
			maxv[o << 1] += addv[o];
			maxv[o << 1 | 1] += addv[o];
			addv[o] = 0;
		}
	}
	inline void maintain(int o)
	{
		minv[o] = min(minv[o << 1], minv[o << 1 | 1]);
		maxv[o] = max(maxv[o << 1], maxv[o << 1 | 1]);
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			addv[o] += qx;
			minv[o] += qx;
			maxv[o] += qx;
			return;
		}
		pushdown(o);
		int mid = (l + r) / 2;
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
		maintain(o);
	}
	pair<int, int> query()
	{
		return { minv[1],maxv[1] };
	}
} st;
string s;
char str[N];
int cnt[200];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int len;
	cin >> len >> s;
	int cur = 1;
	int ans = 0;
	for (auto& c : s)
	{
		if (c == 'L')
		{
			cur--;
			if (cur == 0)
				cur = 1;
			printf("%d ", ans);
			continue;
		}
		if (c == 'R')
		{
			cur++;
			printf("%d ", ans);
			continue;
		}
		if (str[cur] == '(')
		{
			cnt['(']--;
			st.set(cur, len, -1);
			st.update(1, len);
		}
		else if (str[cur] == ')')
		{
			cnt[')']--;
			st.set(cur, len, 1);
			st.update(1, len);
		}
		str[cur] = c;
		if (str[cur] == '(')
		{
			cnt['(']++;
			st.set(cur, len, 1);
			st.update(1, len);
		}
		else if (str[cur] == ')')
		{
			cnt[')']++;
			st.set(cur, len, -1);
			st.update(1, len);
		}
		ans = -1;
		if (cnt['('] == cnt[')'])
		{
			auto [minv, maxv] = st.query();
			if (minv == 0)
				ans = maxv;
		}
		printf("%d ", ans);
	}
	return 0;
}