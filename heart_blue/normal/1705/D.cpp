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
vector<pair<int, int>> build(string str)
{
	str += '*';
	int pre = 0;
	vector<pair<int, int>> ret;
	int n = str.length();
	for (int i = 1; i < n; i++)
	{
		if (str[i] != str[i - 1]) ret.emplace_back(pre, i - 1), pre = i;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		string s1, s2;
		cin >> s1 >> s2;
		auto v1 = build(s1);
		auto v2 = build(s2);
		if (s1[0] != s2[0] || s1[n - 1] != s2[n - 1] || v1.size() != v2.size())
		{
			puts("-1");
			continue;
		}
		LL ans = 0;
		for (int i = 0; i < v1.size(); i++)
		{
			ans += abs(v1[i].second - v2[i].second);
		}
		printf("%lld\n", ans);
	}
	return 0;
}