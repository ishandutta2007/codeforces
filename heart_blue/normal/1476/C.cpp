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
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int b[N];
int c[N];
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
		for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		LL pre = -INF * INF;
		LL ans = 0;
		for (int i = 2; i <= n; i++)
		{
			if (a[i] == b[i])
			{
				ans = max(ans, 1LL + c[i]);
				pre = 2;
			}
			else
			{
				if (a[i] > b[i]) swap(a[i], b[i]);
				pre = 2LL + max(b[i] - a[i] + 0LL, pre + a[i] - 1LL + c[i - 1] - b[i]);
				ans = max(ans, c[i] - 1 + pre);
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}