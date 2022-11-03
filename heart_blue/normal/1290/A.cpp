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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e3 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		int k1 = min(m - 1, k);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int k2 = m - 1 - k1;
		int ans = 0;
		for (int i = 0; i <= k1; i++)
		{
			int minv = INF;
			for (int j = 0; j <= k2; j++)
			{
				minv = min(minv, max(a[i + j + 1], a[n - (k1 - i) - (k2 - j)]));
			}
			ans = max(minv, ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}