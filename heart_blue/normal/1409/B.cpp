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
const int N = 2e5 + 10;
LL solve(int a, int b, int x, int y, int n)
{
	int o = min(a - x, n);
	a -= o, n -= o;
	b -= min(n, b - y);
	return 1LL * a * b;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int a, b, x, y, n;
		scanf("%d%d%d%d%d", &a, &b, &x, &y, &n);
		printf("%lld\n", min(solve(a, b, x, y, n), solve(b, a, y, x, n)));
	}
	return 0;
}