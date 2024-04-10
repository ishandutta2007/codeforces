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
const int N = 5e2 + 10;
int cnt[N][N];
char str[N];
int dp[N][N];
int pre[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	int k;
	scanf("%d", &k);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			int c = 0;
			int l = i, r = j;
			while (l < r)
			{
				c += str[l++] != str[r--];
			}
			cnt[i][j] = c;
		}
	}
	MEM(pre, -1);
	MEM(dp, 0x3f);
	dp[0][0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (dp[i][j] > n) continue;
			for (int k = i + 1; k <= n; k++)
			{
				if (dp[k][j + 1] > dp[i][j] + cnt[i + 1][k])
				{
					dp[k][j + 1] = dp[i][j] + cnt[i + 1][k];
					pre[k][j + 1] = i;
				}
			}
		}
	}
	int t = 1;
	for (int i = 1; i <= k; i++)
	{
		if (dp[n][i] < dp[n][t])
			t = i;
	}
	printf("%d\n", dp[n][t]);
	vector<string> vs;
	int x = n;
	while (t)
	{
		int l = pre[x][t] + 1;
		int r = x;
		x = pre[x][t];
		t--;
		for (int i = 0; l + i < r - i; i++)
		{
			str[l + i] = str[r - i];
		}
		vs.emplace_back(str + l, str + r + 1);
	}
	reverse(vs.begin(), vs.end());
	int ok = 0;
	for (auto& s : vs)
	{
		if (ok) putchar('+');
		ok = 1;
		printf(s.c_str());
	}
	return 0;
}