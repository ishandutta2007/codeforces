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
int a[N];
int pos[N];
int key[N];
int b[N];
const int mod = 998244353;
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
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			pos[a[i]] = i;
		}
		LL ans = 1;
		for (int i = 1; i <= n; i++) key[i] = 0;
		for (int i = 1; i <= m; i++)
		{
			int x;
			scanf("%d", &x);
			b[i] = x;
			key[x] = i;
		}
		for (int i = 1; i <= m; i++)
		{
			int o = pos[b[i]];
			int cnt = 0;
			for (int j = -1; j <= 1; j += 2)
			{
				int p = o + j;
				if (p < 1 || p > n) continue;
				if (key[a[p]] <= i) cnt++;
			}
			ans = ans * cnt % mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}