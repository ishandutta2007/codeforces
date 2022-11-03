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
const int N = 4e3 + 10;
LL sum(LL n)
{
	return n * (n + 1) / 2;
}
LL check(LL n)
{
	LL l = 1, r = INF * 2;
	LL ret = 1;
	while (l <= r)
	{
		LL mid = (l + r) / 2;
		if (sum(mid) <= n) ret = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, h;
	cin >> n >> h;
	LL x = check(n);
	if (x <= h)
	{
		printf("%lld\n", x + (n - sum(x) > 0));
		return 0;
	}
	LL l = h, r = INF * 2;
	LL key = h;
	while (l <= r)
	{
		LL mid = (l + r) / 2;
		if (sum(mid - 1) - sum(h - 1) + sum(mid) <= n) key = mid, l = mid + 1;
		else r = mid - 1;
	}
	LL rest = -(sum(key - 1) - sum(h - 1) + sum(key) - n);
	printf("%lld\n", key - h + key + (rest - 1 + key) / key);
	return 0;
}