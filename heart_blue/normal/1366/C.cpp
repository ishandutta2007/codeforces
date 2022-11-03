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
const int N = 1e2 + 10;
int tot[N];
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
		MEM(tot, 0);
		MEM(cnt, 0);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				int x;
				scanf("%d", &x);
				tot[i + j]++;
				cnt[i + j] += x;
			}
		}
		int l = 2, r = n + m;
		int ans = 0;
		while (l < r)
		{
			int maxv = tot[l] + tot[r];
			int cur = cnt[l] + cnt[r];
			l++, r--;
			ans += min(cur, maxv - cur);
		}
		printf("%d\n", ans);
	}
	return 0;
}