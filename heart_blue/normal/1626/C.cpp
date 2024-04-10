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
const int N = 1e2 + 10;
int a[N];
int b[N];
LL sum(int n)
{
	return 1LL * n * (n + 1) / 2;
}
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
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		for (int i = n; i > 1; i--)
		{
			b[i - 1] = max(b[i - 1], b[i] - a[i] + a[i - 1]);
		}
		LL ans = sum(b[1]);
		for (int i = 1; i < n; i++)
		{
			if (b[i + 1] - a[i + 1] + a[i] <= 0) ans += sum(b[i + 1]);
			else
			{
				b[i + 1] = b[i] + a[i + 1] - a[i];
				ans += sum(b[i + 1]) - sum(b[i]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}