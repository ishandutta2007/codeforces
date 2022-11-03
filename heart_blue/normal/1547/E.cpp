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
		int k;
		scanf("%d", &k);
		for (int i = 1; i <= k; i++)
		{
			scanf("%d", &a[i]);
		}
		fill(ans + 1, ans + n + 1, int(2 * INF));
		for (int i = 1; i <= k; i++)
		{
			int x;
			scanf("%d", &x);
			ans[a[i]] = x;
		}
		for (int i = 2; i <= n; i++)
		{
			ans[i] = min(ans[i - 1] + 1, ans[i]);
		}
		for (int i = n - 1; i >= 1; i--)
		{
			ans[i] = min(ans[i], ans[i + 1] + 1);
		}
		for (int i = 1; i <= n; i++)
		{
			printf("%d%c", ans[i], " \n"[i == n]);
		}
	}
	return 0;
}