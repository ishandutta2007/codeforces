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
int a[N];
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		int g = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), g = gcd(a[i], g);
		sort(a + 1, a + n + 1);
		if (a[1] < 0)
		{
			puts("NO");
			continue;
		}
		int l = min(g, a[1]);
		int r = a[n];
		if ((r - l) / g + 1 > 300)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		printf("%d\n", (r - l) / g + 1);
		while (l <= r)
		{
			printf("%d%c", l, " \n"[l == r]);
			l += g;
		}
	}
	return 0;
}