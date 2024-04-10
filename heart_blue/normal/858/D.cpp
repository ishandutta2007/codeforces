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
const int N = 7e4 + 10;
map<string, pair<int, int>> mp;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<string> ans(n);
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		map<string, int> m;
		for (int j = 0; j < 9; j++)
		{
			for (int k = 1; j + k <= 9; k++)
			{
				m[str.substr(j, k)] = 1;
			}
		}
		for (auto &p : m)
		{
			mp[p.first].second++;
			mp[p.first].first = i;
		}
	}
	for (auto &p : mp)
	{
		int o, c;
		tie(o, c) = p.second;
		if (c != 1) continue;
		if (ans[o].empty() || ans[o].length() > p.first.length()) 
			ans[o] = p.first;
	}
	for (int i = 0; i < n; i++)
	{
		puts(ans[i].c_str());
	}
	return 0;
}