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
int sum[N * 2];
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
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= 2 * k; i++) sum[i] = 0;
		int l = 1, r = n;
		while (l <= r)
		{
			int x = a[l++];
			int y = a[r--];
			if (x > y) swap(x, y);
			int L = x + 1, R = k + y;
			sum[L]++;
			sum[R + 1]--;
			sum[x + y]--;
			sum[x + y + 1]++;
			sum[1] += 2;
			sum[L] -= 2;
			sum[R + 1] += 2;
			sum[2 * k + 1] -= 2;
		}
		int ans = INF;
		for (int i = 1; i <= 2 * k; i++)
		{
			sum[i] += sum[i - 1];
			ans = min(ans, sum[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}