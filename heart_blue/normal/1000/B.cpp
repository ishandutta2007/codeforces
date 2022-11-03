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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL sum1 = 0, sum2 = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (i & 1) sum1 += a[i];
		else sum2 += a[i];
	}
	LL cur = 0;
	a[0] = 0;
	a[n + 1] = m;
	LL s1 = 0, s2 = 0;
	if (n & 1) s1 += m;
	LL maxv = 0;
	for (int i = 1; i <= n + 1; i += 2)
	{
		maxv += a[i] - a[i - 1];
	}
	for (int i = 0; i <= n; i++)
	{
		if (i & 1) sum1 -= a[i], s1 += a[i];
		else sum2 -= a[i], s2 += a[i];
		if (a[i] + 1 == a[i + 1]) continue;

		if (i & 1)
		{
			maxv = max(maxv, s1 - s2 + sum2 - sum1 - (a[i] + 1));
		}
		else
		{
			maxv = max(maxv, s1 - s2 + sum2 - sum1 + a[i + 1] - 1);
		}
	}
	cout << maxv << '\n';
	return 0;
}