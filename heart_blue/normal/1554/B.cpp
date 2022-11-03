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
		int k;
		scanf("%d", &k);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		LL ans = -INF;
		for (int i = n; i >= 1; i--)
		{
			for (int j = i - 1; j >= 1; j--)
			{
				if (1LL * i * j <= ans) break;
				ans = max(ans, 1LL * i * j - k * (a[i] | a[j]));
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}