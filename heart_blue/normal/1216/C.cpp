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
LL check(LL l1, LL r1, LL l2, LL r2)
{
	return max(0LL, min(r2, r1) - max(l1, l2));
}
LL getans(LL x1, LL y1, LL x2, LL y2, LL x3, LL y3, LL x4, LL y4)
{
	return check(x1, x2, x3, x4) * check(y1, y2, y3, y4);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL x1, y1, x2, y2;
	LL x3, y3, x4, y4;
	LL x5, y5, x6, y6;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	cin >> x5 >> y5 >> x6 >> y6;
	x3 = max(x3, x1), x4 = min(x4, x2);
	x5 = max(x5, x1), x6 = min(x6, x2);
	y3 = max(y3, y1), y4 = min(y4, y2);
	y5 = max(y5, y1), y6 = min(y6, y2);
	if (getans(x1, y1, x2, y2, x1, y1, x2, y2) ==
		getans(x1, y1, x2, y2, x3, y3, x4, y4) +
		getans(x1, y1, x2, y2, x5, y5, x6, y6) -
		getans(x3, y3, x4, y4, x5, y5, x6, y6))
		puts("NO");
	else
		puts("YES");
	return 0;
}