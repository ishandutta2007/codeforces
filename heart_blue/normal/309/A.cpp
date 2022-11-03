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
const int N = 1e6 + 10;
int a[N];
LL solve(int n, int l, int t)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = l - a[i];
		if (a[i] == l) a[i] = 0;
	}
	sort(a, a + n);
	int ptr2 = 0;
	int ptr1 = 0;
	LL ret = 0;
	for (int i = 0; i < n; i++)
	{
		while (ptr2 < n && a[ptr2] - a[i] <= 2 * t)
			ptr2++;
		while (ptr1 < i && l - a[i] + a[ptr1] <= 2 * t)
			ptr1++;
		ret += ptr2 - i - 1 + ptr1;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, l, t;
	scanf("%d%d%d", &n, &l, &t);
	LL cnt = t / l;
	LL ans = 1LL * n * (n - 1) * 4 * cnt;
	t %= l;
	if (t >= l - t)
		ans += 1LL * n * (n - 1) * 2;
	t = min(t, l - t);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%.15f\n", (ans + solve(n, l, t) + solve(n, l, t)) / 8.0);
	return 0;
}