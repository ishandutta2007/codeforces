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
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, m, q;
	scanf("%lld%lld%lld", &n, &m, &q);
	LL g = gcd(n, m);
	LL a = n / g, b = m / g;
	LL key[] = { 0,a,b };
	while (q--)
	{
		LL sx, sy, ex, ey;
		scanf("%lld%lld%lld%lld", &sx, &sy, &ex, &ey);
		sy--, ey--;
		if (sy / key[sx] == ey / key[ex]) puts("YES");
		else puts("NO");
	}
	return 0;
}