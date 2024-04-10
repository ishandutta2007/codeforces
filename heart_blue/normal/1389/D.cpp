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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
LL solve(LL a, LL b, LL t)
{
	if (t <= a) return 0;
	else return t - a;
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
		LL k;
		scanf("%d%lld", &n, &k);
		LL l1, r1, l2, r2;
		scanf("%lld%lld%lld%lld", &l1, &r1, &l2, &r2);
		if (min(r1, r2) >= max(l1, l2))
		{
			LL o = min(r1, r2) - max(l1, l2);
			k -= n * o;
			r2 = max(r1, r2) - min(l1, l2) - o;
			l1 = r1 = l2 = 0;
		}
		LL a = max(l1, l2) - min(r1, r2);
		LL b = max(r1, r2) - min(l1, l2);
		LL len = a + b;
		if (k <= 0)
		{
			puts("0");
			continue;
		}
		LL l = 0, r = INF * INF;
		LL ans = 0;
		while (l <= r)
		{
			LL mid = (l + r) / 2;
			LL rest = mid;
			LL sum = 0;
			for (int i = 1; i <= n; i++)
			{
				LL t = min(rest, len);
				if (i > 1)
				{
					if (t / 2 >= solve(a, b, t))
					{
						sum += rest / 2;
						rest = 0;
						break;
					}
				}
				rest -= t;
				sum += solve(a, b, t);
			}
			sum += rest / 2;
			if (sum >= k) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%lld\n", ans);
	}

	return 0;
}