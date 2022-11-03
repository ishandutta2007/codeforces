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
const int N = 1e6 + 10;
const LL INF = 1e9 + 7;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	for (int i = n - 1; i >= 1; i--) a[i] += a[i + 1];
	for (int i = 1; i <= q; i++) scanf("%d", &b[i]);
	int l = 1, r = n;
	int ans = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		int cnt2 = a[mid];
		int cnt1 = n - cnt2;
		for (int i = 1; i <= q; i++)
		{
			if (b[i] < 0)
			{
				if (-b[i] <= cnt1) cnt1--;
				else cnt2--;

			}
			else
			{
				if (b[i] < mid) cnt1++;
				else cnt2++;
			}
		}
		if (cnt2 > 0) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}