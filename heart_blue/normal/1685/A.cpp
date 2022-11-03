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
const int N = 2e5 + 10;
int a[N];
int ans[N];
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
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		if (n & 1)
		{
			puts("NO");
			continue;
		}
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n / 2; i++)
		{
			ans[i * 2 - 1] = a[i];
			ans[i * 2] = a[i + n / 2];
		}
		ans[n + 1] = ans[1];
		int flag = 1;
		for (int i = 2; i <= n; i += 2)
		{
			if (ans[i] > ans[i - 1] && ans[i] > ans[i + 1]) continue;
			flag = 0;
		}
		if (flag == 0) puts("NO");
		else
		{
			puts("YES");
			for (int i = 1; i <= n; i++)
				printf("%d%c", ans[i], " \n"[i == n]);
		}
	}
	return 0;
}