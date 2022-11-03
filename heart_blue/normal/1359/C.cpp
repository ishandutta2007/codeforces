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
const int N = 1e3 + 10;
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int h, c, t;
		cin >> h >> c >> t;
		if (t <= (h + c) / 2)
		{
			puts("2");
			continue;
		}
		int l = 0, r = 1e9;
		int res = 0;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			LL u = 1LL * (h + c) * mid + h;
			LL d = 2 * mid + 1;
			if (u >= d * t) res = mid, l = mid + 1;
			else r = mid - 1;
		}
		LL u1 = 1LL * (h + c) * res + h;
		LL d1 = 2 * res + 1;
		LL u2 = 1LL * (h + c) * (res + 1) + h;
		LL d2 = 2 * res + 3;
		u1 -= d1 * t;
		u2 -= d2 * t;
		u1 = abs(u1);
		u2 = abs(u2);
		if (u1 * d2 > u2 * d1) res++;
		res = 2 * res + 1;
		printf("%d\n", res);
	}
	return 0;
}