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
LL multy(LL x, LL y)
{
	if (x > INF* INF / y) return INF * INF;
	else return x * y;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		LL n, a, b;
		scanf("%lld%lld%lld", &n, &a, &b);
		if (a >= b) cout << n << '\n';
		else
		{
			LL l = n, r = INF * INF;
			LL ans = INF * INF;
			LL cost = (n + 1) / 2;
			while (l <= r)
			{
				LL mid = (l + r) / 2;
				LL p = mid / (a + b);
				LL sum1 = multy(p, a);
				LL sum2 = multy(p, b);
				LL rest = mid % (a + b);
				sum1 += min(rest, a);
				sum2 += max(0LL, rest - a);
				if (sum1 >= cost) ans = mid, r = mid - 1;
				else l = mid + 1;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}