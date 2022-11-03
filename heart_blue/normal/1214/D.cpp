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
const int N = 2e6 + 10;
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<string> vs;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		vs.emplace_back(str);
	}
	vector<vector<int>> dp1(n, vector<int>(m, 0));
	auto dp2 = dp1;
	dp1[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (vs[i][j] == '#') continue;
			if (i > 0) dp1[i][j] |= dp1[i - 1][j];
			if (j > 0) dp1[i][j] |= dp1[i][j - 1];
		}
	}
	dp2[n - 1][m - 1] = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			if (vs[i][j] == '#') continue;
			if (i + 1 != n) dp2[i][j] |= dp2[i + 1][j];
			if (j + 1 != m) dp2[i][j] |= dp2[i][j + 1];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dp1[i][j] && dp2[i][j])
				cnt[i + j + 2]++;
		}
	}
	int ans = INF;
	for (int i = 3; i < n + m; i++)
		ans = min(ans, cnt[i]);
	printf("%d\n", ans);
	return 0;
}