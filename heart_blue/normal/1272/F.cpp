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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int dp[N][N][N];
tuple<int, int, int> pre[N][N][N];
char s1[N];
char s2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, 0x3f);
	scanf("%s", s1 + 1);
	scanf("%s", s2 + 1);
	int n = strlen(s1 + 1);
	int m = strlen(s2 + 1);
	dp[0][0][0] = 0;
	int minv = INF;
	queue<tuple<int, int, int>> q;
	q.emplace(0, 0, 0);
	while (!q.empty())
	{
		auto [o, x, y] = q.front();
		q.pop();
		string str = "()";
		for (auto& c : str)
		{
			int oo = o, xx = x, yy = y;
			if (c == '(') oo++;
			else oo--;
			if (oo < 0) continue;
			if (oo == N) continue;
			if (s1[xx + 1] == c) xx++;
			if (s2[yy + 1] == c) yy++;
			if (dp[oo][xx][yy] > dp[o][x][y] + 1)
			{
				dp[oo][xx][yy] = dp[o][x][y] + 1;
				pre[oo][xx][yy] = { o,x,y };
				q.emplace(oo, xx, yy);
			}
		}
	}
	int o = 0, x = n, y = m;
	string ans;
	while (o > 0 || x > 0 || y > 0)
	{
		auto [oo, xx, yy] = pre[o][x][y];
		if (o > oo) ans.push_back('(');
		else ans.push_back(')');
		tie(o, x, y) = pre[o][x][y];
	}
	reverse(ans.begin(), ans.end());
	puts(ans.c_str());
	return 0;
}