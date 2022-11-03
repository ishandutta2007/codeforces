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
const int N = 1e5 + 10;
int ans[N];
class BIT
{
public:
	int *a;
	int n;
	BIT(int sz = N)
	{
		init(sz);
	}
	void init(int sz = N)
	{
		n = sz;
		a = new int[sz];
		memset(a, 0, sizeof(int)*sz);
	}
	int lowbit(int x)
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
	void add(int x, int val)
	{
		while (x < n)
		{
			a[x] += val;
			x += lowbit(x);
		}
	}
};
class Solver
{
public:
	vector<tuple<int, int, int>> v;
	void push(int op, int t, int pos)
	{
		v.push_back(make_tuple(op, t, pos));
	}
	void solve()
	{
		if (v.empty()) return;
		vector<int> v1;
		for (auto &x : v)
		{
			v1.push_back(get<1>(x));
		}
		sort(v1.begin(), v1.end());
		auto idx = [&](int x) -> int
		{
			return lower_bound(v1.begin(), v1.end(), x) - v1.begin() + 1;
		};
		BIT *b = new BIT(v1.size() + 2);
		for (auto &p : v)
		{
			int op, t, pos;
			tie(op, t, pos) = p;
			t = idx(t);
			if (op == 1) b->add(t, 1);
			else if (op == 2) b->add(t, -1);
			else ans[pos] = b->sum(t);
		}
		delete b;
	}
} S[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<int, int> mc;
	int n;
	cin >> n;
	MEM(ans, -1);
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		int op, t, x;
		cin >> op >> t >> x;
		if (!mc.count(x)) mc[x] = k++;
		x = mc[x];
		S[x].push(op, t, i);
	}
	for (int i = 0; i < k; i++) S[i].solve();
	for (int i = 0; i < n; i++)
	{
		if (ans[i] == -1) continue;
		printf("%d\n", ans[i]);
	}
	return 0;
}