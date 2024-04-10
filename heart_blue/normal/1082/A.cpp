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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		LL n, x, y, d;
		LL ans = INF * INF;
		cin >> n >> x >> y >> d;
		if (abs(x - y) % d == 0) ans = min(ans, abs(x - y) / d);
		if (abs(y - 1) % d == 0) ans = min(ans, (x - 1 + d - 1) / d + (y - 1) / d);
		if (abs(n - y) % d == 0) ans = min(ans, (n - x + d - 1) / d + (n - y) / d);
		if (ans == INF * INF) ans = -1;
		cout << ans << endl;
	}
	return 0;
}