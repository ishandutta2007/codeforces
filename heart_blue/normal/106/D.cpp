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
const int M = 1e3 + 10;
char str[M][M];
map<int, int> mc[M][M];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int h, w;
	scanf("%d%d", &h, &w);
	for (int i = 1; i <= h; i++) scanf("%s", str[i] + 1);
	for (int i = 1; i <= h; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= w; j++)
		{
			mc[i][j]['W'] = cnt;
			if (str[i][j] == '#') cnt = 0;
			else cnt++;
		}
		for (int j = w; j >= 1; j--)
		{
			mc[i][j]['E'] = cnt;
			if (str[i][j] == '#') cnt = 0;
			else cnt++;
		}
	}
	for (int j = 1; j <= w; j++)
	{
		int cnt = 0;
		for (int i = 1; i <= h; i++)
		{
			mc[i][j]['N'] = cnt;
			if (str[i][j] == '#') cnt = 0;
			else cnt++;
		}
		for (int i = h; i >= 1; i--)
		{
			mc[i][j]['S'] = cnt;
			if (str[i][j] == '#') cnt = 0;
			else cnt++;
		}
	}
	int sz;
	scanf("%d", &sz);
	vector<pair<char, int>> vp(sz);
	for (auto& p : vp)
		scanf(" %c %d", &p.first, &p.second);
	string ans;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			if (!isalpha(str[i][j])) continue;
			int flag = 1;
			int cx = i, cy = j;
			for (auto& p : vp)
			{
				char c;
				int x;
				tie(c, x) = p;
				if (mc[cx][cy][c] < x)
				{
					flag = 0;
					break;
				}
				if (c == 'W') cy -= x;
				if (c == 'E') cy += x;
				if (c == 'N') cx -= x;
				if (c == 'S') cx += x;
				if (str[cx][cy] == '#')
				{
					flag = 0;
					break;
				}
			}
			if (flag) ans.push_back(str[i][j]);
		}
	}
	sort(ans.begin(), ans.end());
	if (ans.empty()) puts("no solution");
	else puts(ans.c_str());
	return 0;
}