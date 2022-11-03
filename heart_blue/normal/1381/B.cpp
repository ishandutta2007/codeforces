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
const int N = 4e3 + 10;
int dp[N][N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	int key = 0;
	while (ncase--)
	{
		key++;
		dp[0][0] = key;
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= 2 * n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= 2 * n; i++)
		{
			int j = i + 1;
			while (j <= 2 * n && a[j] < a[i]) j++;
			int len = j - i;
			for (int k = 0; k <= i - 1; k++)
			{
				if (dp[i - 1][k] != key) continue;
				dp[j - 1][k] = dp[j - 1][k + len] = key;
			}
			i = j - 1;
		}
		if (dp[2 * n][n] == key) puts("YES");
		else puts("NO");
	}
	return 0;
}