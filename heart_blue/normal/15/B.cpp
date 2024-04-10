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
LL getlen(int l1, int r1, int l2, int r2)
{
	int l = max(l1, l2);
	int r = min(r1, r2);
	return max(0, r - l + 1);
}
LL getarea(int x1, int y1, int x2, int y2)
{
	return getlen(x1, x2, x1, x2) * getlen(y1, y2, y1, y2);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m, a, b, c, d;
		scanf("%d%d%d%d%d%d", &n, &m, &a, &b, &c, &d);
		int U = min(a - 1, c - 1);
		int D = min(n - a, n - c);
		int L = min(b - 1, d - 1);
		int R = min(m - b, m - d);
		LL ans = getarea(a - U, b - L, a + D, b + R) +
			getarea(c - U, d - L, c + D, d + R) -
			getlen(a - U, a + D, c - U, c + D) * getlen(b - L, b + R, d - L, d + R);
		printf("%lld\n", 1LL * n * m - ans);
	}
	return 0;
}