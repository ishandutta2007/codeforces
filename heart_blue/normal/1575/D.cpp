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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	if (str.length() == 1)
	{
		if (isdigit(str[0]) && str[0] != '0') puts("0");
		else puts("1");
		return 0;
	}
	if (str[0] == '0')
	{
		puts("0");
		return 0;
	}
	int ans = 0;
	vector<string> vs = { "00","25","50","75" };
	for (char x = '0'; x <= '9'; x++)
	{
		if (str.find('X') == str.npos) x = '9';
		if (str[0] == 'X' && x == '0') continue;
		string s = str;
		for (auto& c : s)
		{
			if (c == 'X')
				c = x;
		}
		int sum = 1;
		for (int i = 0; i + 2 < str.length(); i++)
		{
			if (str[i] == '_')
			{
				if (i == 0) sum *= 9;
				else sum *= 10;
			}
		}
		string s1 = s.substr(s.length() - 2);
		for (auto& s2 : vs)
		{
			if (s2 == "00" && str.length() == 2) continue;
			int ok = 1;
			for (int i = 0; i < 2; i++)
			{
				if (!isdigit(s1[i])) continue;
				if (s1[i] != s2[i]) ok = 0;
			}
			if (ok) ans += sum;
		}
	}
	printf("%d\n", ans);
	return 0;
}