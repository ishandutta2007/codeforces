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
const int N = 3e5 + 10;
pair<int, int> v[N];
int n, a, b;
int flag[N];
int check(int l1, int r1, int l2, int r2)
{
	return max(0, min(r1, r2) - max(l1, l2) + 1);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &v[i].first);
		v[i].second = i;
	}
	sort(v + 1, v + n + 1);
	for (int i = n; i > 0; i--)
	{
		flag[i] = flag[i + 1];
		if (1LL * (n - i + 1)*v[i].first >= b) flag[i] = i;
	}
	pair<int, int> minv = { n,0 };
	for (int i = 1; i <= n; i++)
	{
		int lo = i;
		int ro = i + (a - 1) / v[i].first;
		if (ro > n) continue;
		if (flag[ro + 1])
		{
			puts("Yes");
			printf("%d %d\n", ro - lo + 1, n - flag[ro + 1] + 1);
			for (int j = lo; j <= ro; j++) printf("%d ", v[j].second);
			puts("");
			for (int j = flag[ro + 1]; j <= n; j++) printf("%d ", v[j].second);
			puts("");
			return 0;
		}
		int d = check(lo, ro, minv.second, minv.first);
		if (d <= n - ro && minv.second != 0)
		{
			puts("Yes");
			printf("%d %d\n", ro - lo + 1, n - minv.second + 1 - (ro - lo + 1));
			for (int j = lo; j <= ro; j++) printf("%d ", v[j].second);
			puts("");
			for (int j = minv.second; j <= n; j++)
			{
				if (j >= lo && j <= ro) continue;
				printf("%d ", v[j].second);
			}
			puts("");
			return 0;
		}
		minv = min(minv, { i + (b - 1) / v[i].first,i });
	}
	puts("No");
	return 0;
}