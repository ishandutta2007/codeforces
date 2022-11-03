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
const int N = 3e5 + 10;
class SegmentTree
{
public:
	int minv[N * 4];
	int ql, qr, qx;
	void set(int l, int r, int x = 0)
	{
		ql = l, qr = r, qx = x;
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			minv[o] = qx;
			return;
		}
		int mid = (l + r) >> 1;
		if (ql <= mid) update(l, mid, o << 1);
		else update(mid + 1, r, o << 1 | 1);
		minv[o] = min(minv[o << 1], minv[o << 1 | 1]);
	}
	int query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return minv[o];
		}
		int mid = (l + r) >> 1;
		int ret = INF;
		if (ql <= mid) ret = min(ret, query(l, mid, o << 1));
		if (qr > mid) ret = min(ret, query(mid + 1, r, o << 1 | 1));
		return ret;
	}
} st;
int a[N];
int pos[N];
int L[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		pos[a[i]] = i;
		L[i] = n;
	}
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (pos[x] > pos[y]) swap(x, y);
		L[pos[x]] = min(L[pos[x]], pos[y] - 1);
	}
	LL ans = 0;
	for (int i = n; i > 0; i--)
	{
		if (i + 1 <= L[i])
		{
			st.set(i + 1, L[i]);
			L[i] = min(L[i], st.query(1, n));
		}
		st.set(i, i, L[i]);
		st.update(1, n);
		//cout << L[i] - i + 1 << endl;
		ans += L[i] - i + 1;
	}
	printf("%lld\n", ans);
	return 0;
}