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
int a;
int n;
int L[N];
int po[N];
double p[N];
double rp[N];
int cnt[N];
double ans = 0;
void init()
{
	for (int i = 1; i < N; i++)
	{
		cnt[i] = cnt[i >> 1] + (i & 1);
	}
}
void solve()
{
	int mask = (1 << n) - 1;
	p[0] = 1;
	for (int i = 0; i < n; i++) p[1 << i] = po[i] / 10.0;
	for (int i = 1; i <= mask; i++) p[i] = p[i - (i & -i)] * p[i & -i];
	rp[0] = 1;
	for (int i = 0; i < n; i++) rp[1 << i] = 1.0 - po[i] / 10.0;
	for (int i = 1; i <= mask; i++) rp[i] = rp[i - (i & -i)] * rp[i & -i];
	double sum = 0;
	for (int i = 0; i <= mask; i++)
	{
		double tot = p[i] * rp[mask ^ i];
		if (cnt[i] * 2 > n) sum += tot;
		else
		{
			int s = 0;
			for (int j = 0; j < n; j++)
			{
				if (i >> j & 1) continue;
				s += L[j];
			}
			sum += tot * a / (a + s);
		}
	}
	ans = max(ans, sum);
}
void dfs(int cur, int k)
{
	if (cur == n)
	{
		if (k != 0) return;
		solve();
		return;
	}
	int maxv = min(k, 10 - po[cur]);
	for (int i = 0; i <= maxv; i++)
	{
		po[cur] = po[cur] + i;
		dfs(cur + 1, k - i);
		po[cur] = po[cur] - i;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int k;
	cin >> n >> k >> a;
	int tot = 0;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		y /= 10;
		L[i] = x;
		po[i] = y;
		tot += 10 - y;
	}
	k = min(tot, k);
	dfs(0, k);
	printf("%.15f\n", ans);
	return 0;
}