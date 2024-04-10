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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
class BIT
{
public:
	int a[N];
	void add(int x, int val)
	{
		while (x < N)
		{
			a[x] += val;
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
vector<int> vp[N];
vector<pair<int, int>> qr[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		vp[r].emplace_back(l);
	}
	for (int i = 1; i <= m; i++)
	{
		int cnt = 1;
		int pre = 0;
		scanf("%d", &cnt);
		while (cnt--)
		{
			int x;
			scanf("%d", &x);
			if (pre + 1 != x)
			{
				qr[x - 1].emplace_back(pre + 1, i);
			}
			pre = x;
		}
		qr[N - 1].emplace_back(pre + 1, i);
	}
	fill(ans, ans + N, n);
	for (int i = 1; i < N; i++)
	{
		for (auto& x : vp[i])
			b.add(x, 1);
		for (auto& p : qr[i])
		{
			int x, pos;
			tie(x, pos) = p;
			ans[pos] -= b.sum(i) - b.sum(x - 1);
		}
	}
	for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
	return 0;
}