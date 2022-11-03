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
const int N = 2e5 + 10;
int last[N];
int pos[N];
int a[N];
int nex[N][20];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		pos[x] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		int x;
		scanf("%d", &x);
		a[i] = pos[x];
	}
	fill(last + 1, last + n + 1, m + 1);
	for (int i = m; i >= 1; i--)
	{
		int x = a[i] + 1;
		if (x > n) x = 1;
		nex[i][0] = last[x];
		last[a[i]] = i;
	}
	nex[m + 1][0] = m + 1;
	for (int o = 0; o + 1 < 20; o++)
	{
		for (int i = 1; i <= m + 1; i++)
		{
			nex[i][o + 1] = nex[nex[i][o]][o];
		}
	}
	vector<tuple<int, int, int>> qr;
	for (int i = 1; i <= q; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		qr.emplace_back(l, r, i);
	}
	sort(qr.begin(), qr.end());
	int cur = m + 1;
	for (int i = m; i >= 1; i--)
	{
		int d = n - 1;
		int x = i;
		for (int o = 0; d >> o; o++)
		{
			if (d >> o & 1)
				x = nex[x][o];
		}
		cur = min(cur, x);
		while (!qr.empty())
		{
			int l, r, pos;
			tie(l, r, pos) = qr.back();
			if (l != i) break;
			qr.pop_back();
			if (r != m + 1 && r >= cur) ans[pos] = 1;
			else ans[pos] = 0;
		}
	}
	for (int i = 1; i <= q; i++)
		putchar(ans[i] + '0');
	return 0;
}