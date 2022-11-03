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
const int N = 1e4 + 10;
string ans;
bool dfs(string& s1, string& s2, int ptr1 = 0, int ptr2 = 0)
{
	if (ptr1 == s1.length())
	{
		if (ptr2 == s2.length()) return true;
		return false;
	}
	for (char c = '0'; c <= '9'; c++)
	{
		int x = s1[ptr1] - '0';
		int y = c - '0';
		int sum = x + y;
		string s = to_string(sum);
		reverse(s.begin(), s.end());
		if (s != s2.substr(ptr2, s.length())) continue;
		ans += c;
		if (dfs(s1, s2, ptr1 + 1, ptr2 + s.length()))
			return true;
		ans.pop_back();
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string a, s;
		cin >> a >> s;
		ans.clear();
		reverse(a.begin(), a.end());
		reverse(s.begin(), s.end());

		while (a.length() <= s.length() && !dfs(a, s))
		{
			a = a + '0';
		}
		reverse(ans.begin(), ans.end());
		if (ans.empty()) ans = "-1";
		printf("%lld\n", stoll(ans));
	}
	return 0;
}