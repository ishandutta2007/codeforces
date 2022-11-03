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
const int N = 2e3 + 20;
int key[] =
{
	0b1110111,
	0b0010010,
	0b1011101,
	0b1011011,
	0b0111010,
	0b1101011,
	0b1101111,
	0b1010010,
	0b1111111,
	0b1111011
};
int a[N];
int cnt[N];
int dp[N][N];
vector<int> v[N];
string ans;
void init()
{
	for (int i = 1; i < N; i++)
		cnt[i] = cnt[i >> 1] + (i & 1);
	for (int i = 0; i < 10; i++)
	{
		int o = key[i];
		for (int s = o; s; s = (s - 1) & o)
		{
			v[s].push_back(i);
		}
		v[0].push_back(i);
	}
	for (int i = 0; i < N; i++)
	{
		reverse(v[i].begin(), v[i].end());
	}
}
int dfs(int x, int y)
{
	if (y < 0) return 0;
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;
	for (auto& s : v[a[x]])
	{
		if (dfs(x + 1, y - (cnt[key[s]] - cnt[a[x]])))
		{
			dp[x][y] = 1;
			ans.push_back('0' + s);
			break;
		}
	}
	return dp[x][y];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	MEM(dp, -1);
	int n, k;
	cin >> n >> k;
	MEM(dp[n + 1], 0);
	dp[n + 1][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		a[i] = stoi(str, 0, 2);
	}
	if (!dfs(1, k)) puts("-1");
	else
	{
		reverse(ans.begin(), ans.end());
		puts(ans.c_str());
	}
	return 0;
}