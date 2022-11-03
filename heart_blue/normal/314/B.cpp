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
const int N = 2e2 + 10;
char b[N];
char d[N];
int nxt[N][N];
pair<LL, int> dp[N][32];
int n, m;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, c;
	scanf("%d%d", &a, &c);
	scanf("%s", b + 1);
	scanf("%s", d + 1);
	n = strlen(b + 1);
	m = strlen(d + 1);
	for (int i = n; i >= 1; i--)
	{
		nxt[n][b[i]] = i;
	}
	nxt[n][b[n]] = n;
	for (int i = n - 1; i >= 1; i--)
	{
		memcpy(nxt[i], nxt[i + 1], sizeof(nxt[i]));
		nxt[i][b[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		int len = 0, cur = i;
		int ptr = 1;
		while (1)
		{
			if (nxt[cur][d[ptr]] == 0) puts("0"), exit(0);
			if (cur > nxt[cur][d[ptr]]) len++;
			cur = nxt[cur][d[ptr]];
			ptr++;
			if (ptr > m) break;
			cur++;
			if (cur > n) cur = 1, len++;
		}
		dp[i][0] = { 1LL * len,cur };
	}
	for (int o = 1; o < 32; o++)
	{
		for (int i = 1; i <= n; i++)
		{
			auto p = dp[i][o - 1];
			LL len, pos;
			tie(len, pos) = p;
			pos++;
			if (pos > n) pos = 1, len++;
			dp[i][o] = make_pair(len + dp[pos][o - 1].first, dp[pos][o - 1].second);
		}
	}
	int l = 1, r = 1e9;
	int ans = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		int pos = 0;
		LL len = 1;
		for (int o = 0; o < 32; o++)
		{
			if (mid >> o & 1)
			{
				pos++;
				if (pos > n) pos = 1, len++;
				len += dp[pos][o].first;
				pos = dp[pos][o].second;
			}
		}
		if (len > a) r = mid - 1;
		else ans = mid, l = mid + 1;
	}
	printf("%d\n", ans / c);
	return 0;
}