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
const int N = 5e3 + 10;
const int M = 5e2 + 10;
int a[N];
int love[N];
int key[N];
int dp[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	map<int, int> mc1, mc2;
	for (int i = 1; i <= n * k; i++)
	{
		scanf("%d", &a[i]);
		mc1[a[i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &love[i]);
		mc2[love[i]]++;
	}
	for (int i = 1; i <= k; i++)
	{
		scanf("%d", &key[i]);
	}
	LL ans = 0;
	for (auto &p : mc2)
	{
		int x = p.first;
		int tot = p.second;
		int sz = mc1[x];
		for (int i = 1; i <= tot; i++)
		{
			for (int j = min(sz, i * k); j > 0; j--)
			{
				for (int t = min(k, j); t >= 0; t--)
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j - t] + key[t]);
				}
			}
		}
		ans += dp[tot][min(sz, tot*k)];
	}
	printf("%lld\n", ans);
	return 0;
}