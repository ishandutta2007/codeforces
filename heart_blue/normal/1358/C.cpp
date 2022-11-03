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
const int N = 1e2 + 10;
LL sum(int n)
{
	return 1LL * n * (n + 1) / 2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int n = x2 - x1 + 1;
		int m = y2 - y1 + 1;
		if (n > m) swap(n, m);
		LL ans = sum(n) * 2 - 2 * n + 1LL * (n + m - 1 - 2 * (n - 1)) * n;
		ans -= n + m - 1;
		ans++;
		printf("%lld\n", ans);
	}
	return 0;
}