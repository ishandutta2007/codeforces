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
int cnt1[N];
int cnt2[N];
int a[N];
int b[N];
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
		fill(cnt1, cnt1 + n + 1, 0);
		fill(cnt2, cnt2 + n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &a[i], &b[i]);
			cnt1[a[i]]++;
			cnt2[b[i]]++;
		}
		LL ans = 1LL * n * (n - 1) * (n - 2) / 6;
		for (int i = 1; i <= n; i++)
		{
			ans -= 1LL * (cnt1[a[i]] - 1) * (cnt2[b[i]] - 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}