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
const int N = 1e4 + 10;
LL check(string &s1, string &s2)
{
	LL ans = 1;
	int n = s1.length();
	for (int i = 0; i < n; i++)
	{
		if (s1[i] == '?' && s2[i] == '?')
		{
			ans = ans * 55 % INF;
		}
		else if (s1[i] == '?')
		{
			ans = ans*('9' - s2[i] + 1) % INF;
		}
		else if (s2[i] == '?')
		{
			ans = ans*(s1[i] - '0' + 1) % INF;
		}
		else if (s1[i] < s2[i]) return 0;
	}
	return ans;
}
LL check2(string &s1, string &s2)
{
	LL ans = 1;
	int n = s1.length();
	for (int i = 0; i < n; i++)
	{
		if (s1[i] == '?' && s2[i] == '?') ans = ans * 10 % INF;
		else if (s1[i] != s2[i])
		{
			if (s1[i] != '?' && s2[i] != '?') return 0;
		}
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL tot = 1;
	int n;
	string s1, s2;
	cin >> n;
	cin >> s1 >> s2;
	auto cnt = [&](string &s)
	{
		for (auto &c : s)
		{
			if (c == '?')
			{
				tot = tot * 10 % INF;
			}
		}
	};
	cnt(s1);
	cnt(s2);
	tot -= check(s1, s2) + check(s2, s1) - check2(s1, s2);
	tot %= INF;
	if (tot < 0) tot += INF;
	cout << tot << endl;
	return 0;
}