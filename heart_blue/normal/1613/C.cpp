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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
LL a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		LL h;
		scanf("%d%lld", &n, &h);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		LL l = 1, r = h;
		LL ans = -1;
		while (l <= r)
		{
			LL mid = (l + r) / 2;
			LL tot = mid;
			for (int i = 1; i < n; i++)
			{
				tot += min(a[i + 1] - a[i], mid);
				if (tot >= h) break;
			}
			if (tot >= h) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}