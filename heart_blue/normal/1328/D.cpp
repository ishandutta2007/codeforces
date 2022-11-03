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
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int cnt = a[1] != a[n];
		for (int i = 1; i < n; i++)
		{
			cnt += a[i] != a[i + 1];
		}
		if (cnt == 0)
		{
			puts("1");
			for (int i = 1; i <= n; i++) printf("1 ");
			puts("");
			continue;
		}
		if (cnt % 2 == 0 || (cnt % 2 == 1 && cnt == n))
		{
			ans[1] = 1;
			for (int i = 2; i <= n; i++)
			{
				if (a[i] == a[i - 1]) ans[i] = ans[i - 1];
				else ans[i] = 3 - ans[i - 1];
			}
			if (cnt == n && cnt % 2 == 1) ans[n] = 3, puts("3");
			else puts("2");
			for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
			puts("");
			continue;
		}
		int key = 1;
		for (int i = 1; i <= n; i++)
		{
			int x = i;
			int r = i + 1;
			int l = i - 1;
			if (r > n) r -= n;
			if (l == 0) l = n;
			if (a[x] != a[l] && a[x] == a[r])
			{
				key = x;
				break;
			}
		}
		ans[key] = 2;
		a[key] = -1;
		for (int i = 1; i < n; i++)
		{
			int l = key + i - 1;
			int r = key + i;
			if (l > n) l -= n;
			if (r > n) r -= n;
			if (a[l] == a[r]) ans[r] = ans[l];
			else ans[r] = 3 - ans[l];
		}
		puts("2");
		for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
		puts("");

	}
	return 0;
}