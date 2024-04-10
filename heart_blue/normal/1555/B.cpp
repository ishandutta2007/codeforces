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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int check(int n, int m, int x1, int y1, int h1, int w1, int h2, int w2)
{
	int ans = INF;
	if (w1 + w2 <= n) ans = min(ans, max(0, w2 - x1));
	if (h1 + h2 <= m) ans = min(ans, max(0, h2 - y1));
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int w1 = x2 - x1;
		int h1 = y2 - y1;
		int h2, w2;
		scanf("%d%d", &w2, &h2);
		int res1 = check(n, m, x1, y1, h1, w1, h2, w2);
		int res2 = check(n, m, x1, m - y2, h1, w1, h2, w2);
		int res3 = check(n, m, n - x2, y1, h1, w1, h2, w2);
		int res4 = check(n, m, n - x2, m - y2, h1, w1, h2, w2);
		int ans = min({ res1,res2,res3,res4 });
		if (ans == INF) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}