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
const int N = 3e5 + 10;
int a[N];
int b[N];
LL solve(LL x, int n)
{
	LL ret = 0;
	for (int i = 1; i <= n; i++)
	{
		ret += a[i] * x / b[i];
	}
	return ret + n;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, c;
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
	int l = 1, r = INF;
	int lans = INF, rans = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (solve(mid, n) >= c) lans = mid, r = mid - 1;
		else l = mid + 1;
	}
	l = 1, r = INF;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (solve(mid, n) <= c) rans = mid, l = mid + 1;
		else r = mid - 1;
	}
	if (solve(lans, n) != c || solve(rans, n) != c) puts("0"), exit(0);
	printf("%d\n", max(0, rans - lans + 1));
	return 0;
}