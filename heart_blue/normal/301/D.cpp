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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int pos[N];
vector<int> vp[N];
vector<pair<int, int>> qr[N];
int ans[N];
class BIT
{
public:
	int a[N];
	void add(int x)
	{
		while (x < N)
		{
			a[x] ++;
			x += x & -x;
		}
	}
	int sum(int x)
	{
		int ret = 0;
		while (x)
		{
			ret += a[x];
			x -= x & -x;
		}
		return ret;
	}
} b;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	cin >> n >> q;
	int maxv = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		maxv = max(maxv, x);
		pos[x] = i;
	}
	for (int i = 1; i <= q; i++)
	{
		int l, r;
		cin >> l >> r;
		qr[r].emplace_back(l, i);
	}
	for (int i = 1; i <= maxv; i++)
	{
		if (pos[i] == 0) continue;
		for (int j = i; j <= maxv; j += i)
		{
			if (pos[j] == 0) continue;
			int x = pos[i];
			int y = pos[j];
			if (x > y) swap(x, y);
			vp[y].push_back(x);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (auto &x : vp[i])
		{
			b.add(x);
		}
		for (auto &p : qr[i])
		{
			int r = i;
			int l, pos;
			tie(l, pos) = p;
			ans[pos] = b.sum(r) - b.sum(l - 1);
		}
	}
	for (int i = 1; i <= q; i++)
		printf("%d\n", ans[i]);
	return 0;
}