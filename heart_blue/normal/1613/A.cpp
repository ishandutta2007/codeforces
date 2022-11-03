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
const int N = 2e2 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		LL x1, p1, x2, p2;
		scanf("%lld%lld%lld%lld", &x1, &p1, &x2, &p2);
		LL o = min(p1, p2);
		p1 -= o;
		p2 -= o;
		p1 = min(10LL, p1);
		p2 = min(10LL, p2);
		while (p1--) x1 *= 10;
		while (p2--) x2 *= 10;
		if (x1 > x2) puts(">");
		if (x1 < x2) puts("<");
		if (x1 == x2) puts("=");
	}
	return 0;
}