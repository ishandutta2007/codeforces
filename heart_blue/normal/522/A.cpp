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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e2 + 10;
vector<int> v[N];
map<string, int> ms;
int dp[N];
int dfs(int x)
{
	if (dp[x]) return dp[x];
	for (auto &y : v[x])
	{
		dp[x] = max(dp[x], dfs(y));
	}
	dp[x]++;
	return dp[x];
}
void refrain(string &s)
{
	for (auto &x : s) x = tolower(x);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, 0);
	string s1, op, s2;
	int n;
	cin >> n;
	int sz = 0;
	while (n--)
	{
		cin >> s1 >> op >> s2;
		refrain(s1);
		refrain(s2);
		if (!ms.count(s1)) ms[s1] = sz++;
		if (!ms.count(s2)) ms[s2] = sz++;
		int x = ms[s1];
		int y = ms[s2];
		v[y].push_back(x);
	}
	int ans = 0;
	for (int i = 0; i < sz; i++)
	{
		ans = max(ans, dfs(i));
	}
	cout << ans << endl;


	return 0;
}