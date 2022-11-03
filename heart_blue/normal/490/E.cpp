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
bool check(string& s1, string& s2, int cur = 0, int o = 1)
{
	if (cur == s1.length())
	{
		return o == 0;
	}
	if (isdigit(s2[cur]))
	{
		if (o == 0)
			return check(s1, s2, cur + 1, o);
		else
		{
			if (s1[cur] > s2[cur]) return false;
			else if (s1[cur] == s2[cur])
				return check(s1, s2, cur + 1, o);
			else
				return check(s1, s2, cur + 1, 0);
		}
	}
	else
	{
		if (o == 0)
		{
			s2[cur] = '0';
			return check(s1, s2, cur + 1, 0);
		}
		else
		{
			s2[cur] = s1[cur];
			if (check(s1, s2, cur + 1, 1))
				return true;
			s2[cur] = '?';
			if (s1[cur] != '9')
			{
				s2[cur] = s1[cur] + 1;
				return check(s1, s2, cur + 1, 0);
			}
			return false;
		}
	}
}
vector<string> vs;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vs.push_back("");
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		if (s.length() < vs.back().length())
		{
			puts("NO");
			return 0;
		}
		if (s.length() > vs.back().length())
		{
			int flag = 1;
			for (auto& c : s)
			{
				if (c == '?')
					c = flag + '0';
				flag = 0;
			}
			vs.push_back(s);
			continue;
		}
		if (!check(vs.back(), s))
		{
			puts("NO");
			return 0;
		}
		//cout << s << "*" << endl;
		vs.push_back(s);
	}
	puts("YES");
	vs.erase(vs.begin());
	for (auto& s : vs)
		puts(s.c_str());
	return 0;
}