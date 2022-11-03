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
const int N = 3e5 + 10;
LL a[N];
LL solve(LL a, LL b, LL x, LL y)
{
	if (a == 0 || b == 0) a = b = 0;
	return max(0LL, x - a) + max(0LL, y - b);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	LL sum = 0;
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), sum += a[i];
	sort(a + 1, a + n + 1);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		LL x, y;
		scanf("%lld%lld", &x, &y);
		int pos = lower_bound(a + 1, a + n + 1, x) - a;
		printf("%lld\n", min(solve(a[pos], sum - a[pos], x, y),
			solve(a[pos - 1], sum - a[pos - 1], x, y)));
	}
	return 0;
}