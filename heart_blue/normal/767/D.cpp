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
const int N = 1e6 + 10;
int a[N];
pair<int, int> b[N];
int n, m, k;
bool check(int x)
{
	int p1 = 0;
	int p2 = m - x;
	int cur = -1;
	while (1)
	{
		int tot = k;
		cur++;
		if (p1 < n && a[p1] < cur) return false;
		if (p2 < m && b[p2].first < cur) return false;
		while (tot > 0 && p1 < n && p2 < m)
		{
			if (a[p1] <= b[p2].first) p1++;
			else p2++;
			tot--;
		}
		while (tot > 0 && p1 < n) p1++, tot--;
		while (tot > 0 && p2 < m) p2++, tot--;
		if (p1 == n && p2 == m) return true;
		if (tot > 0) return false;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int j = 0; j < m; j++)
	{
		scanf("%d", &b[j].first);
		b[j].second = j + 1;
	}
	sort(a, a + n);
	sort(b, b + m);
	int l = 0, r = m;
	int ans = -1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	if (ans == -1) puts("-1");
	else
	{
		printf("%d\n", ans);
		for (int i = m - ans; i < m; i++) printf("%d ", b[i].second);
	}
	return 0;
}