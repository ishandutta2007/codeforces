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
const int N = 2e5 + 10;
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
		string s1, s2;
		reverse(str.begin(), str.end());
		for (auto& c : str)
		{
			if (s1.empty() || s1.back() >= c) s1 += c;
			else s2 += min('9', char(c + 1));
		}
		sort(s1.begin(), s1.end());
		sort(s2.rbegin(), s2.rend());
		string ans;
		for (auto& c : s1)
		{
			while (!s2.empty() && s2.back() <= c)
			{
				ans += s2.back();
				s2.pop_back();
			}
			ans += c;
		}
		reverse(s2.begin(), s2.end());
		puts((ans + s2).c_str());

	}
	return 0;
}