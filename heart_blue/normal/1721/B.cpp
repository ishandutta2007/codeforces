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
const int N = 1e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		int x, y;
		int d;
		scanf("%d%d%d%d%d", &n, &m, &x, &y, &d);
		int cnt1 = 0;
		int cnt2 = 0;
		int cnt3 = 0;
		int cnt4 = 0;
		if (x - d <= 1) cnt1++, cnt2++;
		if (x + d >= n) cnt1++, cnt3++;
		if (y - d <= 1) cnt4++, cnt2++;
		if (y + d >= m) cnt4++, cnt3++;
		if (cnt1 == 2 || cnt2 == 2 || cnt3 == 2 || cnt4 == 2) puts("-1");
		else printf("%d\n", n + m - 2);
	}
	return 0;
}