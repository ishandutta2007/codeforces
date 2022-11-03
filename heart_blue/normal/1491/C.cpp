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
const int N = 5e3 + 10;
int a[N], b[N];
LL sum[N];
bool solve(int n, LL tot)
{
	memset(sum, 0, sizeof(LL) * (n + 1));
	memcpy(b, a, sizeof(int) * (n + 1));
	LL cur = tot;
	for (int i = 1; i <= n; i++)
	{
		sum[i] += sum[i - 1];
		cur += sum[i];
		if (b[i] - 1 > cur)
		{
			return false;
		}
		cur -= (b[i] - 1);
		sum[i + 2] ++;
		sum[min(i + b[i], n) + 1] --;

	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		LL l = 0, r = INF * n;
		LL ans = 0;
		while (l <= r)
		{
			LL mid = (l + r) / 2;
			if (solve(n, mid)) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}