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
int g[N][20];
int cnt[N];
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
void init(int n)
{
	cnt[0] = 0;
	for (int i = 1; i <= n; i++) cnt[i] = 1 + cnt[i >> 1];
	for (int o = 0; (1 << o) <= n; o++)
	{
		for (int i = 1; i + (2 << o) <= n + 1; i++)
		{
			g[i][o + 1] = gcd(g[i][o], g[i + (1 << o)][o]);
		}
	}
}
int solve(int l, int r)
{
	int o = cnt[r - l + 1] - 1;
	return gcd(g[l][o], g[r - (1 << o) + 1][o]);
}
map<int, LL> ans;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &g[i][0]);
	init(n);
	int gg = 0;
	for (int i = n; i >= 1; i--)
	{
		gg = gcd(gg, g[i][0]);
		int cur = n;
		while (cur >= i)
		{
			int l = i, r = cur;
			int o = solve(i, cur);
			int res = r;
			while (l <= r)
			{
				int mid = (l + r) >> 1;
				if (solve(i, mid) == o) res = mid, r = mid - 1;
				else l = mid + 1;
			}
			ans[o] += cur - res + 1;
			cur = res - 1;
		}
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int x;
		scanf("%d", &x);
		printf("%lld\n", ans[x]);
	}
	return 0;
}