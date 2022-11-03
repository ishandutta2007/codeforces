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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, l, r;
		scanf("%d%d%d", &n, &l, &r);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		LL ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int ptr1 = lower_bound(a + 1, a + n + 1, l - a[i]) - a;
			int ptr2 = upper_bound(a + 1, a + n + 1, r - a[i]) - a;
			ptr1 = max(ptr1, i + 1);
			ptr2 = max(ptr2, i + 1);
			ans += ptr2 - ptr1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}