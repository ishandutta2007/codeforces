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
const int N = 1e6 + 10;
vector<LL> check(LL x)
{
	vector<LL> ret;
	for (int i = 2; 1LL * i * i <= x; i++)
	{
		if (x % i == 0) ret.push_back(i);
		while (x % i == 0)
			x /= i;
	}
	if (x > 1) ret.push_back(x);
	return ret;
}
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL x, y;
	cin >> x >> y;
	auto key = check(x);
	LL ans = 0;
	while (y)
	{
		LL g = gcd(x, y);
		x /= g, y /= g;
		if (y % x == 0)
		{
			ans += y / x;
			break;
		}
		LL minv = INF * INF;
		for (auto& d : key)
		{
			if (x % d) continue;
			LL r = y % d;
			minv = min(minv, r);
		}
		ans += minv;
		y -= minv;
	}
	printf("%lld\n", ans);
	return 0;
}