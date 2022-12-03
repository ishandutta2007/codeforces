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
const int N = 2e2 + 10;

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
		LL ans = -1;
		LL l = 0, r = INF;
		while (l <= r)
		{
			LL mid = (l + r) / 2;
			auto calc = [](LL n)->LL
			{
				n--;
				LL ans = 0;
				ans = (n / 3) * (n / 3) * 3;
				for (int i = 0; i <= n % 3; i++)
					ans += n / 3 * 2 + i;
				return ans * 2;
			};
			if (calc(mid) >= n) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}