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
const int N = 2e5 + 10;
int a[N];
LL cost[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	LL tot = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), tot += a[i];
	LL rest = 0;
	for (int i = 1; i <= n; i++)
	{
		cost[i] = cost[i - 1];
		rest += cost[i];
		if (rest < a[i])
		{
			LL o = (a[i] - rest + i - 1) / i;
			rest += o * i;
			cost[i] += o;
		}
		rest -= a[i];
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int t;
		scanf("%d", &t);
		int l = 1, r = n;
		int ans = -1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (cost[mid] <= t && 1LL * mid * t >= tot) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}