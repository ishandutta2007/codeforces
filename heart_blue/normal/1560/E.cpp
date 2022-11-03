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
const int N = 1e6 + 10;
bool solve()
{
	string str;
	cin >> str;
	map<int, int> mc, cnt, flag;
	for (auto& c : str)
	{
		mc[c]++;
		flag[c] = 1;
	}
	string ans1, ans2;
	int len = 0;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		if (!flag.count(str[i])) continue;
		if (mc[str[i]] % flag.size()) return false;
		len += cnt[str[i]] = mc[str[i]] / flag.size();
		flag.erase(str[i]);
		ans2.push_back(str[i]);
	}
	reverse(ans2.begin(), ans2.end());
	ans1 = str.substr(0, len);
	int ptr = 0;
	for (int i = 0; i < str.length(); i *= 1)
	{
		int j = i + len;
		string key;
		for (int j = 0; j < ans1.length(); j++)
		{
			if (cnt.count(ans1[j]))
				key += ans1[j];
		}
		if (key != str.substr(i, len)) return false;
		char c = ans2[ptr++];
		len -= cnt[c];
		cnt.erase(c);
		i = j;
	}
	printf("%s %s\n", ans1.c_str(), ans2.c_str());
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		if (!solve())
			puts("-1");
	}
	return 0;
}