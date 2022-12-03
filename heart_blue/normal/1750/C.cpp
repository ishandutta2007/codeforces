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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
vector<pair<int, int>> build(string &str)
{
	str += '*';
	int last = 0;
	vector<pair<int, int>> ret;
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] != str[i - 1])
		{
			ret.emplace_back(last + 1, i);
			last = i;
		}
	}
	str.pop_back();
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
		if (n == 1)
		{
			if (s2 == "1") puts("NO");
			else
			{
				puts("YES");
				if (s1 == "1") puts("1"), puts("1 1");
				else puts("0");
			}
			continue;
		}
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += s1[i] ^ s2[i];
		if (sum != 0 && sum != n)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		vector<pair<int, int>> ans;
		auto vp = build(s1);
		for (int i = (s1[0] == '0' ? 1 : 0); i < vp.size(); i += 2)
		{
			ans.push_back(vp[i]);
		}
		if (ans.size() & 1) sum ^= n;
		if (sum == n)
		{
			ans.emplace_back(1, n);
			ans.emplace_back(1, 1);
			ans.emplace_back(2, n);
		}
		printf("%d\n", ans.size());
		for (auto [l, r] : ans)
			printf("%d %d\n", l, r);
	}
	return 0;
}