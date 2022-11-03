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
const int N = 2e5 + 10;
int L[N];
int R[N];
int flag[N];
int a[N];
class SegmentTree
{
public:
	int setv[N * 4];
	int ql, qr, qx;
	void set(int l, int r, int x)
	{
		ql = l, qr = r, qx = x;
	}
	void pushdown(int o)
	{
		if (setv[o])
		{
			setv[o << 1] = setv[o << 1 | 1] = setv[o];
			setv[o] = 0;
		}
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			setv[o] = qx;
			return;
		}
		pushdown(o);
		int mid = (l + r) >> 1;
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
	}
	int query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return setv[o];
		}
		pushdown(o);
		int ans = 0;
		int mid = (l + r) >> 1;
		if (ql <= mid) ans = query(l, mid, o << 1);
		if (mid < qr) ans = query(mid + 1, r, o << 1 | 1);
		return ans;
	}
} st;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	cin >> n >> q;
	MEM(L, 0x3f);
	MEM(R, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == 0) continue;
		L[a[i]] = min(L[a[i]], i);
		R[a[i]] = max(R[a[i]], i);
	}
	for (int i = 1; i <= q; i++)
	{
		if (L[i] > R[i]) continue;
		st.set(L[i], R[i], i);
		st.update(1, n);
	}
	for (int i = 1; i <= n; i++)
	{
		st.set(i, i, 1);
		int x = st.query(1, n);
		if (a[i] != 0 && a[i] != x)
		{
			puts("NO");
			return 0;
		}
		flag[a[i]] = 1;
	}
	if (flag[0] == 0 && flag[q] == 0)
	{
		puts("NO");
		return 0;
	}
	int key = 0;
	if (flag[q] == 0) key = q;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 0)
		{
			a[i] = key;
			break;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 0) continue;
		int j = i + 1;
		while (j <= n && a[j] == 0) a[j++] = a[i];
		j = i - 1;
		while (j >= 1 && a[j] == 0) a[j--] = a[i];
	}
	puts("YES");
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	return 0;
}