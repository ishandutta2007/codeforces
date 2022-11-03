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
const int N = 2e2 + 10;
int flag[N];
bool check(string &s1, string &s2)
{
	int n = s1.length();
	for (int i = 0; i < n; i++)
	{
		if (s1[i] == '?')
		{
			if (flag[s2[i]] == 0) return false;
		}
		else
		{
			if (s1[i] != s2[i]) return false;
		}
	}
	return true;
}
bool check(string &s)
{
	for (auto &c : s) if (flag[c]) return false;
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string alpha;
	cin >> alpha;
	for (auto &c : alpha) flag[c] = 1;
	string str;
	cin >> str;
	int o = str.find('*');
	string str1, str2;
	if (o == -1) str1 = str;
	else
	{
		str1 = str.substr(0, o);
		str2 = str.substr(o + 1);
	}
	int l1 = str1.length(), l2 = str2.length();
	int l3 = 0;
	if (o != -1) l3 = INF;
	int q;
	cin >> q;
	while (q--)
	{
		string s;
		cin >> s;
		int n = s.length();
		if (s.length() < l1 + l2 || s.length() > l1 + l2 + l3)
		{
			puts("NO");
			continue;
		}
		string s1 = s.substr(0, l1);
		string s2 = s.substr(n - l2);
		string s3 = s.substr(l1, n - l1 - l2);
		if (check(str1, s1) && check(str2, s2) && check(s3)) puts("YES");
		else puts("NO");
	}
	return 0;
}