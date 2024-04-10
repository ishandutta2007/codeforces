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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		LL k, n, a, b;
		cin >> k >> n >> a >> b;
		if (b * n >= k)
		{
			puts("-1");
			continue;
		}
		LL l = 0, r = min(n, (k - 1) / a);
		int ans = 0;
		while (l <= r)
		{
			LL mid = (l + r) / 2;
			if (b * (n - mid) >= k - a * mid) r = mid - 1;
			else ans = mid, l = mid + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}