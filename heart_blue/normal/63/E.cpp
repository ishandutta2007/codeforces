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
const int N = 2e6 + 10;
string str[5];
int id[20][20];
int dx[] = { 1,1,-1,-1,0,0 };
int dy[] = { 1,-1,1,-1,2,-2 };
vector<int> v;
int dp[N];
int dfs(int x)
{
	if (x == 0) return 0;
	if (dp[x] != -1) return dp[x];
	dp[x] = 0;
	for (auto& y : v)
	{
		if ((x & y) != y) continue;
		if (dfs(x ^ y) == 0)
		{
			dp[x] = 1;
			break;
		}
	}
	return dp[x];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, -1);
	int tot = 1 << 19;
	int mask = 1 << 19;
	int key = 0;
	int cur = 0;
	for (int i = 0; i < 5; i++)
	{
		getline(cin, str[i]);
		for (int j = 0; j < str[i].length(); j++)
		{
			if (str[i][j] == ' ') continue;
			id[i][j] = cur++;
			if (str[i][j] == 'O')
				key |= 1 << id[i][j];
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < str[i].length(); j++)
		{
			if (str[i][j] != 'O') continue;
			for (int o = 0; o < 6; o++)
			{
				int t = 0;
				for (int k = 0; ; k++)
				{
					int x = i + dx[o] * k;
					int y = j + dy[o] * k;
					if (x < 0 || x >= 5) break;
					if (y < 0 || y >= str[x].length()) break;
					if (str[x][y] != 'O') break;
					t |= 1 << id[x][y];
					v.push_back(t);
				}
			}
		}
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	if (!dfs(key)) puts("Lillebror");
	else puts("Karlsson");
	return 0;
}