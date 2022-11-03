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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int a[N];
class SegmentTree
{
public:
	pair<int, int> key[N * 4];
	int ql, qr, qx;
	inline pair<int, int> combine(pair<int, int> p1, pair<int, int> p2)
	{
		if (p1 < p2) swap(p1, p2);
		if (p1.second == p2.second) return { p1.first + p2.first,p2.second };
		else return { p1.first - p2.first,p1.second };
	}
	void set(int l, int r, int x = 1)
	{
		ql = l, qr = r, qx = x;
	}
	void build(int l, int r, int o = 1)
	{
		if (l == r)
		{
			key[o] = { 1,a[l] };
			return;
		}
		int mid = (l + r) / 2;
		build(l, mid, o << 1);
		build(mid + 1, r, o << 1 | 1);
		key[o] = combine(key[o << 1], key[o << 1 | 1]);
	}
	pair<int, int> query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return key[o];
		}
		int mid = (l + r) / 2;
		pair<int, int> ret1(0, 0), ret2(0, 0);
		if (ql <= mid) ret1 = query(l, mid, o << 1);
		if (mid < qr) ret2 = query(mid + 1, r, o << 1 | 1);
		return combine(ret1, ret2);
	}
} st;
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), v[a[i]].push_back(i);
	st.build(1, n);
	while (q--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		st.set(l, r);
		int x = st.query(1, n).second;
		int len = r - l + 1;
		int cnt = upper_bound(v[x].begin(), v[x].end(), r) -
			lower_bound(v[x].begin(), v[x].end(), l);
		printf("%d\n", max(1, cnt * 2 - len));
	}
	return 0;
}