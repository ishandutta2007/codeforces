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
int a[N];

LL sum(int l, int r, int n)
{
	return 1LL * l * (n - r + 1);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	LL ans = 1LL * n * (n + 1) / 2;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] != a[i - 1])
			ans += sum(i - 1, i, n);
	}
	while (q--)
	{
		int i, x;
		scanf("%d%d", &i, &x);
		if (i > 1)
		{
			if (a[i - 1] != a[i])
				ans -= sum(i - 1, i, n);
			if (a[i - 1] != x)
				ans += sum(i - 1, i, n);
		}
		if (i < n)
		{
			if (a[i] != a[i + 1])
				ans -= sum(i, i + 1, n);
			if (x != a[i + 1])
				ans += sum(i, i + 1, n);
		}
		a[i] = x;
		printf("%lld\n", ans);
	}
	return 0;
}