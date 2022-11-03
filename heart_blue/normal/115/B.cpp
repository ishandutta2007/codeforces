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
const int N = 1e3 + 10;
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<pair<int, int>> vp;
	int n, m;
	cin >> n >> m;
	int ans = INF;
	int l, r;
	MEM(dp, 0x3f);
	dp[1] = -1;
	for (int i = 1; i <= n; i++)
	{
		r = 1, l = m;
		int flag = 0;
		for (int j = 1; j <= m; j++)
		{
			char c;
			cin >> c;
			if (c == 'W') r = max(r, j), l = min(l, j), flag = 1;
		}
		if (i & 1)
		{
			for (int j = 1; j <= l; j++) dp[j]++;
			for (int j = l + 1; j <= m; j++) dp[j] = INF;
			for (int j = 2; j <= m; j++) dp[j] = min(dp[j], dp[j - 1] + 1);
			for (int j = 1; j < r; j++) dp[j] = INF;
		}
		else
		{
			for (int j = 1; j < r; j++) dp[j] = INF;
			for (int j = r; j <= m; j++) dp[j]++;
			for (int j = m - 1; j > 0; j--) dp[j] = min(dp[j], dp[j + 1] + 1);
			for (int j = l + 1; j <= m; j++) dp[j] = INF;
		}
		if (flag) ans = min(dp[l], dp[r]);
	}
	if (ans == INF) ans = 0;
	cout << ans << endl;
	return 0;
}