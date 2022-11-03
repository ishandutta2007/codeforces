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
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		if (1LL * n * (n - 1) / 2 < m || m < n - 1)
		{
			puts("NO");
			continue;
		}
		k -= 2;
		if (k < 0)
		{
			puts("NO");
			continue;
		}
		if (n == 1)
		{
			puts("YES");
			continue;
		}
		if (k == 0)
		{
			puts("NO");
			continue;
		}
		if (k >= 2)
		{
			puts("YES");
			continue;
		}
		if (1LL * n * (n - 1) / 2 == m) puts("YES");
		else puts("NO");
	}
	return 0;
}