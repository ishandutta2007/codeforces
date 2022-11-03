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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
vector<pair<int,int>> getans(string &s)
{
	vector<pair<int, int>> v;
	for (auto &c : s)
	{
		if (!v.empty() && v.back().first == c) v.back().second++;
		else v.emplace_back(c, 1);
	}
	return v;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		auto v1 = getans(s1);
		auto v2 = getans(s2);
		if (v1.size() != v2.size())
		{
			puts("NO");
			continue;
		}
		int flag = 1;
		for (int i = 0; i < v1.size(); i++)
		{
			if (v1[i].first != v2[i].first || v1[i].second > v2[i].second)
			{
				flag = 0;
				break;
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}