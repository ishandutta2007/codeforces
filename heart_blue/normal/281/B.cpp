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
const int N = 5e3 + 10;
int cmp(LL L1, LL R1, LL L2, LL R2)
{
	LL res = L1*R2 - R1*L2;
	if (res > 0) return 1;
	else if (res == 0) return 0;
	else return -1;
}
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL x, y, n;
	cin >> x >> y >> n;
	int ret = x / y;
	x %= y;
	LL L1 = 0, R1 = 1, L2 = 1, R2 = 1;
	LL a = 0, b = 1;
	for (b = 1; b <= n; b++)
	{
		while (a + 1 <= b && cmp(a + 1, b, x, y) < 0) a++;
		if (cmp(L1, R1, a, b) < 0) L1 = a, R1 = b;
		if (cmp(L2, R2, a + 1, b) > 0) L2 = a + 1, R2 = b;
	}
	// 2*x / y - L1 / R1;
	// L2/R2
	if (cmp(2 * x*R1 - L1*y, y*R1, L2, R2) > 0) L1 = L2, R1 = R2;
	LL g = gcd(L1, R1);
	L1 /= g;
	R1 /= g;
	L1 += R1*ret;
	printf("%lld/%lld\n", L1, R1);
	return 0;
}