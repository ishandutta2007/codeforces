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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e6 + 10;
// k1x - k2y = a
// k1y + k2x = b
bool solve(LL a1, LL b1, LL c1, LL a2, LL b2, LL c2)
{
	LL d = a1 * b2 - a2 * b1;
	if (d == 0) return false;
	LL d1 = c1 * b2 - c2 * b1;
	LL d2 = a1 * c2 - a2 * c1;
	return (d1 % d == 0 && d2 % d == 0);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL ax, ay;
	LL bx, by;
	LL cx, cy;
	cin >> ax >> ay;
	cin >> bx >> by;
	cin >> cx >> cy;
	for (int i = 0; i < 4; i++)
	{
		tie(ax, ay) = make_pair(-ay, ax);
		if (ax == bx && ay == by) puts("YES"), exit(0);
		else if (solve(cx, -cy, bx - ax, cy, cx, by - ay)) puts("YES"), exit(0);
	}
	puts("NO");
	return 0;
}