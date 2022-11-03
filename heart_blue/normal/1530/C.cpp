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
const int N = 1e3 + 10;
LL a[N];
LL b[N];
LL check(LL a[])
{
	LL tot = 0;
	for (int i = 0; i <= 100; i++)
		tot += a[i];
	LL rest = tot - tot / 4;
	LL ret = 0;
	for (int i = 100; i >= 0; i--)
	{
		LL o = min(rest, a[i]);
		rest -= o;
		ret += o * i;
	}
	return ret;
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
		MEM(a, 0);
		MEM(b, 0);
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			a[x]++;
		}
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			b[x]++;
		}
		LL l = 0, r = INF;
		LL ans = 0;
		while (l <= r)
		{
			LL mid = (l + r) / 2;
			a[100] += mid;
			b[0] += mid;
			if (check(a) >= check(b)) ans = mid, r = mid - 1;
			else l = mid + 1;
			a[100] -= mid;
			b[0] -= mid;
		}
		printf("%lld\n", ans);
	}
	return 0;
}