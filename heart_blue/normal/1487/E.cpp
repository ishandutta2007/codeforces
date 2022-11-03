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
int b[N];
int c[N];
int d[N];
int ans[N];
pair<int, int> key[N];
map<int, int> mc[N];
void solve(int a[], int n, int m, int o = 0)
{
	if (o)
	{
		for (int i = 1; i <= m; i++)
			mc[i].clear();
		int sz;
		scanf("%d", &sz);
		while (sz--)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			mc[y][x] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		key[i] = make_pair(ans[i], i);
	}
	sort(key + 1, key + n + 1);
	for (int i = 1; i <= m; i++)
	{
		ans[i] = INF;
		for (int j = 1; j <= n; j++)
		{
			if (!mc[i].count(key[j].second))
			{
				ans[i] = min(ans[i], a[i] + key[j].first);
				break;
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n1, n2, n3, n4;
	scanf("%d%d%d%d", &n1, &n2, &n3, &n4);
	for (int i = 1; i <= n1; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n2; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= n3; i++) scanf("%d", &c[i]);
	for (int i = 1; i <= n4; i++) scanf("%d", &d[i]);
	solve(a, n1, n1, 0);
	solve(b, n1, n2, 1);
	solve(c, n2, n3, 1);
	solve(d, n3, n4, 1);
	int res = INF;
	for (int i = 1; i <= n4; i++)
		res = min(res, ans[i]);
	if (res == INF) res = -1;
	printf("%d\n", res);
	return 0;
}