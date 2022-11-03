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
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n * k; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + n * k + 1);
		int l = 0, r = n * k + 1;
		int o1, o2;
		o2 = n - (n + 1) / 2 + 1;
		o1 = n - o2;
		LL ans = 0;
		while (1)
		{
			l += o1;
			r -= o2;
			if (l >= r) break;
			ans += a[r];
		}
		printf("%lld\n", ans);
	}
	return 0;
}