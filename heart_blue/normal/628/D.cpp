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
const int N = 2e3 + 10;
LL dp[N][N];
int n, key;
int m;
LL dfs(string& str, int pos = 0, int mod = 0, bool lead = true, bool limit = true)
{
	if (pos == n)
	{
		return mod == 0;
	}
	if (!lead && !limit && dp[pos][mod] != -1)
		return dp[pos][mod];
	int up = limit ? str[pos] - '0' : 9;
	int lo = lead ? 1 : 0;
	if (pos & 1)
	{
		if (key >= lo && key <= up)
		{
			return dfs(str, pos + 1, (mod * 10 + key) % m, false, limit && key == str[pos] - '0');
		}
		else
		{
			return 0;
		}
	}
	LL ret = 0;
	for (int i = lo; i <= up; i++)
	{
		if (i == key && key == 0 && !lead) continue;
		if (key > 0 && i == key) continue;
		ret += dfs(str, pos + 1, (mod * 10 + i) % m, lead && i == 0, limit && i == str[pos] - '0');
	}
	ret %= INF;
	if (ret < 0) ret += INF;
	if (!lead && !limit) dp[pos][mod] = ret;
	return ret;
}
int check(string& str)
{
	int cur = 0;
	for (int i = 0; i < str.length(); i++)
	{
		cur = (cur * 10 + str[i] - '0') % m;
		if (i % 2 == 0 && str[i] - '0' == key) return 0;
		if (i % 2 == 1 && str[i] - '0' != key) return 0;
	}
	return cur == 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, -1);
	cin >> m >> key;
	string s1, s2;
	cin >> s1 >> s2;
	n = s1.length();
	LL ans = dfs(s2) - dfs(s1) + check(s1);
	ans %= INF;
	if (ans < 0) ans += INF;
	printf("%lld\n", ans);
	return 0;
}