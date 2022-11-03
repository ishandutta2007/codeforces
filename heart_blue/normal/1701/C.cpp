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
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		fill(cnt, cnt + n + 1, 0);
		for (int i = 1; i <= m; i++)
		{
			int x;
			scanf("%d", &x);
			cnt[x]++;
		}
		int l = 0, r = INF;
		int ans = INF;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			LL tot = 0;
			for (int i = 1; i <= n; i++)
			{
				tot += min(mid, cnt[i]);
				tot += (mid - min(mid, cnt[i])) / 2;
			}
			if (tot >= m) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%d\n", ans);
	}

	return 0;
}