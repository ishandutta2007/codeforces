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
int dp[N][4];
map<string, int> ans;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	MEM(dp, 0);
	int n = str.length();
	dp[n][2] = dp[n][3] = 1;
	for (int i = n - 2; i > 4; i--)
	{
		for (int k = 2; k <= 3; k++)
		{
			if (i + k > n) continue;
			string s = str.substr(i, k);
			dp[i][k] |= dp[i + k][k ^ 1];
			if (i + 2 * k > n || s != str.substr(i + k, k)) dp[i][k] |= dp[i + k][k];
			if (dp[i][k]) ans[s] = 1;
		}
	}
	printf("%d\n", ans.size());
	for (auto &p : ans)
	{
		puts(p.first.c_str());
	}
	return 0;
}