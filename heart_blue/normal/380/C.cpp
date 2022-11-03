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
const int N = 1e6 + 10;
class SegmentTree
{
public:
	int ql, qr, qx;
	int L[N * 4];
	int R[N * 4];
	int ans[N * 4];
	void init()
	{
		MEM(L, 0);
		MEM(R, 0);
		MEM(ans, 0);
	}
	void setQuery(int ql, int qr, int qx = -1)
	{
		this->ql = ql;
		this->qr = qr;
		this->qx = qx;
	}
	void maintain(int o)
	{
		int l1 = L[o << 1], r1 = R[o << 1], ans1 = ans[o << 1];
		int l2 = L[o << 1 | 1], r2 = R[o << 1 | 1], ans2 = ans[o << 1 | 1];
		int oo = min(l1, r2);
		l1 -= oo, r2 -= oo;
		L[o] = l1 + l2;
		R[o] = r1 + r2;
		ans[o] = ans1 + ans2 + oo;
	};
	tuple<int, int, int> query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			if (qx != -1)
			{
				if (qx == '(') L[o] = 1;
				else R[o] = 1;
			}
			return { L[o],R[o],ans[o] };
		}
		int l1 = 0, r1 = 0, ans1 = 0;
		int l2 = 0, r2 = 0, ans2 = 0;
		int mid = (l + r) / 2;
		if (ql <= mid) tie(l1, r1, ans1) = query(l, mid, o << 1);
		if (qr > mid) tie(l2, r2, ans2) = query(mid + 1, r, o << 1 | 1);
		maintain(o);
		int oo = min(l1, r2);
		l1 -= oo, r2 -= oo;
		return { l1 + l2,r1 + r2,ans1 + ans2 + oo };
	}
} st;
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	st.init();
	for (int i = 1; i <= n; i++)
	{
		st.setQuery(i, i, str[i]);
		st.query(1, n);
	}
	int m;
	scanf("%d", &m);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		st.setQuery(x, y);
		printf("%d\n", get<2>(st.query(1, n)) << 1);
	}
	return 0;
}