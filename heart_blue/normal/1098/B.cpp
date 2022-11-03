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
#include <regex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
string vs1[N];
string vs2[N];
string key1[N];
string key2[N];
int check(string& s, string& key)
{
	int cnt0 = 0;
	int cnt1 = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == key[i & 1]) cnt0++;
		if (s[i] == key[(i & 1) ^ 1]) cnt1++;
	}
	if (cnt1 > cnt0)
		swap(key[0], key[1]);
	return max(cnt0, cnt1);
}
pair<int, vector<int>> solve(int n, string vs[N], string key[N], vector<int> flag)
{
	string s[2];
	for (int i = 0; i < 4; i++)
	{
		s[flag[i]] += "ACGT"[i];
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		key[i] = s[i & 1];
		sum += check(vs[i], key[i]);
	}
	return { sum,flag };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> vs1[i];
		for (int j = 0; j < m; j++)
		{
			vs2[j].push_back(vs1[i][j]);
		}
	}
	vector<int> flag = { 0,0,1,1 };
	pair<int, vector<int>> ans1, ans2;
	ans1.first = ans2.first = -1;
	do
	{
		ans1 = max(ans1, solve(n, vs1, key1, flag));
		ans2 = max(ans2, solve(m, vs2, key2, flag));
	} while (next_permutation(flag.begin(), flag.end()));
	if (ans1.first >= ans2.first)
	{
		solve(n, vs1, key1, ans1.second);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				putchar(key1[i][j % 2]);
			}
			puts("");
		}
	}
	else
	{
		solve(m, vs2, key2, ans2.second);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				putchar(key2[j][i % 2]);
			}
			puts("");
		}
	}
	return 0;
}