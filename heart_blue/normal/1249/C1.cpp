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
const int N = 2e5 + 10;
LL multy(LL x, LL y)
{
	if (x > 4 * INF * INF / y) return 4 * INF * INF;
	else return x * y;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		LL n;
		cin >> n;
		LL l = 1, r = 1e18;
		LL res = 0;
		while (l <= r)
		{
			LL mid = (l + r) / 2;
			LL key = 0;
			for (int i = 62; i >= 0; i--)
			{
				key = multy(key, 3) + (mid >> i & 1);
			}
			if (key >= n) res = key, r = mid - 1;
			else l = mid + 1;
		}
		printf("%lld\n", res);
	}
	return 0;
}