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
const int N = 1e4 + 10;
bitset<N> res;
class SegmentTree
{
public:
	bitset<N> ans[N * 4];
	vector<int> v[N * 4];
	int ql, qr, qx;
	void set(int l, int r, int x)
	{
		ql = l, qr = r, qx = x;
	}
	void update(int l, int r, int o)
	{
		if (ql <= l && r <= qr)
		{
			v[o].push_back(qx);
			return;
		}
		int mid = (l + r) >> 1;
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
	}
	void query(int l, int r, bitset<N> &b, int o)
	{
		ans[o] |= b;
		for (auto &x : v[o])
		{
			ans[o] |= ans[o] << x;
		}
		res |= ans[o];
		if (l == r) return;
		int mid = (l + r) >> 1;
		if (ql <= mid) query(l, mid, ans[o], o << 1);
		if (mid < qr) query(mid + 1, r, ans[o], o << 1 | 1);
	}
} st;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= q; i++)
	{
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		st.set(l, r, x);
		st.update(1, n, 1);
	}
	bitset<N> b;
	b[0] = 1;
	st.set(1, n, 1);
	st.query(1, n, b, 1);
	vector<int> ou;
	for (int i = 1; i <= n; i++)
	{
		if (res[i]) ou.push_back(i);
	}
	printf("%d\n", ou.size());
	for (auto &x : ou) printf("%d ", x);
	return 0;
}