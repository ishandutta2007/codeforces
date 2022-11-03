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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string str;
		cin >> str;
		map<char, int> mc;
		for (auto& c : str)
			mc[c]++;
		if (mc.size() == 1)
		{
			puts(str.c_str());
			continue;
		}
		{
			int key = -1;
			for (auto [val, cnt] : mc)
			{
				if (cnt == 1)
				{
					key = val;
					break;
				}
			}
			if (key != -1)
			{
				str.erase(str.find(key), 1);
				sort(str.begin(), str.end());
				putchar(key);
				puts(str.c_str());
				continue;
			}
		}
		int n = str.length();
		string s1(mc.begin()->second, mc.begin()->first);
		mc.begin()->second = 0;
		string s2;
		for (auto [val, cnt] : mc)
			s2 += string(cnt, val);
		if (s1.length() <= n / 2 + 1)
		{
			reverse(s2.begin(), s2.end());
			string ans;
			ans.reserve(str.length());
			ans += s1.back();
			s1.pop_back();
			while (!s1.empty() && !s2.empty())
			{
				ans += s1.back();
				ans += s2.back();
				s1.pop_back();
				s2.pop_back();
			}
			reverse(s2.begin(), s2.end());
			ans += s1 + s2;
			puts(ans.c_str());
			continue;
		}
		if (mc.size() == 2)
		{
			char c = s1.front();
			s1.pop_back();
			putchar(c);
			puts((s2 + s1).c_str());
		}
		else
		{
			char c1 = s1.front();
			char c2 = s2.front();
			putchar(c1);
			putchar(c2);
			s1.pop_back();
			printf("%s", s1.c_str());
			s2.erase(s2.begin());
			auto iter = upper_bound(s2.begin(), s2.end(), c2);
			char c3 = *iter;
			putchar(c3);
			s2.erase(iter);
			puts(s2.c_str());
		}
	}
	return 0;

}