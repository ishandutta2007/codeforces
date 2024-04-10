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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
vector<int> vp[N];
int belong[N];
int flag[N];
int s[N];
int top;
string str;
string ans1, ans2;
bool dfs(int x)
{
	if (flag[x ^ 1]) return false;
	if (flag[x]) return true;
	flag[x] = 1;
	s[top++] = x;
	for (auto &y : vp[x])
	{
		if (!dfs(y)) return false;
	}
	return true;
}
bool check(int n)
{
	MEM(flag, 0);
	for (int i = 0; i < n; i += 2)
	{
		if (flag[i] || flag[i + 1]) continue;
		top = 0;
		int o = i;
		if (ans1[i / 2] > ans2[i / 2]) o ^= 1;
		if (!dfs(o))
		{
			while (top) flag[s[--top]] = 0;
			if (!dfs(o ^ 1)) return false;
		}
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string alpha;
	cin >> alpha;
	int fv, fc;
	fv = fc = -1;
	for (int i = 0; i < alpha.length(); i++)
	{
		belong[i + 'a'] = alpha[i] == 'C';
		if (alpha[i] == 'V' && fv == -1) fv = i;
		if (alpha[i] == 'C' && fc == -1) fc = i;
	}
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		char c1, c2;
		cin >> x >> c1 >> y >> c2;
		x = (x - 1) << 1 | (c1 == 'C');
		y = (y - 1) << 1 | (c2 == 'C');
		vp[x].push_back(y);
		vp[y ^ 1].push_back(x ^ 1);
	}
	cin >> str;
	ans1 = str;
	ans2 = str;
	for (int i = 0; i < str.length(); i++)
	{
		int x = i << 1 | belong[str[i]];
		vp[x ^ 1].push_back(x);
	}
	for (int i = str.length(); i >= 0; i--)
	{
		vector<int> key;
		if (i < str.length())
		{
			int x = i << 1 | belong[str[i]];
			vp[x ^ 1].pop_back();
			int v, c;
			v = -1, c = -1;
			for (int j = str[i] - 'a' + 1; j < alpha.length(); j++)
			{
				if (belong[j + 'a'] == 0 && v == -1) v = j;
				if (belong[j + 'a'] == 1 && c == -1) c = j;
			}
			if (v == -1)
			{
				key.push_back(i << 1);
				vp[i << 1].push_back(i << 1 | 1);
			}
			if (c == -1)
			{
				key.push_back(i << 1 | 1);
				vp[i << 1 | 1].push_back(i << 1);
			}
			ans1[i] = v + 'a';
			ans2[i] = c + 'a';
		}
		if (check(2 * n))
		{
			for (int o = 0; o < 2 * n; o += 2)
			{
				if (flag[o]) putchar(ans1[o / 2]);
				else putchar(ans2[o / 2]);
			}
			return 0;
		}
		while (!key.empty()) vp[key.back()].pop_back(), key.pop_back();
		if (i < str.length())
		{
			if (fv == -1)
			{
				vp[i << 1].push_back(i << 1 | 1);
			}
			if (fc == -1)
			{
				vp[i << 1 | 1].push_back(i << 1);
			}
			ans1[i] = 'a' + fv;
			ans2[i] = 'a' + fc;
		}
	}
	puts("-1");
	return 0;
}