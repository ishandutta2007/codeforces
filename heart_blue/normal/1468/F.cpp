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
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		map<pair<int, int>, int> mc;
		int n;
		scanf("%d", &n);
		while (n--)
		{
			int x, y, u, v;
			scanf("%d%d%d%d", &x, &y, &u, &v);
			x = u - x;
			y = v - y;
			int g = gcd(abs(x), abs(y));
			mc[make_pair(x / g, y / g)]++;
		}
		LL ans = 0;
		for (auto& p : mc)
		{
			auto [x, y] = p.first;
			x = -x, y = -y;
			if (mc.count(make_pair(x, y)))
				ans += 1LL * p.second * mc[{x, y}];
		}
		printf("%lld\n", ans / 2);
	}
	return 0;
}