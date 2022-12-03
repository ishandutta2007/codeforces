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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
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
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		int ans = max(abs(a[1] - a[n]) + abs(a[n] - a[n - 1]),
			abs(a[1] - a[n]) + abs(a[2] - a[1]));
		for (int i = 2; i + 2 <= n; i++)
		{
			ans = max(ans, abs(a[1] - a[i + 1]) + abs(a[i + 1] - a[i]));
			ans = max(ans, abs(a[n] - a[i]) + abs(a[i + 1] - a[i]));
		}
		printf("%d\n", ans);
	}
	return 0;
}