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
const int N = 1e5 + 10;
int fail[N];
char str[N];
string vs[N];
vector<int> v[N];
int ans = 0;
int len;
int dp[N][26];
void getfail(int len)
{
	int j = 0;
	fail[1] = 0;
	for (int i = 2; i <= len; i++)
	{
		while (j && str[i] != str[j + 1]) j = fail[j];
		if (str[i] == str[j + 1]) j++;
		fail[i] = j;
	}
}
int getdp(int j, char c)
{
	if (j == 0) return j;
	if (dp[j][c - 'a'] != -1) return dp[j][c - 'a'];
	if (c == str[j + 1]) return j;
	return dp[j][c - 'a'] = getdp(fail[j], c);
}
void dfs(int x, int j)
{
	for (auto& c : vs[x])
	{
		j = getdp(j, c);
		if (str[j + 1] == c) j++;
		if (j == len)
		{
			ans++;
			j = fail[j];
		}
	}
	for (auto& y : v[x])
	{
		dfs(y, j);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, -1);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x >> vs[i];
		v[x].push_back(i);
	}
	scanf("%s", str + 1);
	len = strlen(str + 1);
	getfail(len);
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}