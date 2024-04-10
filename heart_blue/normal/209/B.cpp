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
const int N = 1e3 + 10;
LL solve2(LL a, LL b, LL c)
{
	if (a % 2 != b % 2) return INF * INF;
	if (a < b) swap(a, b);
	if (a == b && a == 0) return 0;
	return a;
}
LL solve3(LL a, LL b, LL c)
{
	if (a % 2 != b % 2 || a % 2 != c % 2) return INF * INF;
	if (a < b) swap(a, b);
	if (a < c) swap(a, c);
	if (b < c) swap(b, c);
	return b;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL a, b, c;
	cin >> a >> b >> c;
	LL ans1 = solve2(a, b, c);
	LL ans2 = solve2(a, c, b);
	LL ans3 = solve2(b, c, a);
	LL ans4 = solve3(a, b, c);
	printf("%lld\n", min({ ans1, ans2, ans3, ans4 }));
	return 0;
}