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
const int N = 1e6 + 10;
int flag[N];
vector<string> vs[N][6];
vector<string> vs2[N];
vector<vector<string>> ans;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	flag['a'] = 1;
	flag['e'] = 2;
	flag['i'] = 3;
	flag['o'] = 4;
	flag['u'] = 5;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		char c = 0;
		int cnt = 0;
		for (auto& x : str)
		{
			if (flag[x]) c = x, cnt++;
		}
		vs[cnt][flag[c]].push_back(str);
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < 6; j++)
		{
			auto& v = vs[i][j];
			while (v.size() >= 2)
			{
				int cnt = 2;
				ans.push_back(vector<string>());
				while (cnt--)
				{
					ans.back().push_back(v.back());
					v.pop_back();
				}
			}
			if (!v.empty())
				vs2[i].push_back(v.back());
		}
	}
	int ptr = 1;
	for (int i = 0; i < ans.size(); i++)
	{
		vector<string>& v = ans[i];
		while (ptr < N && vs2[ptr].size() < 2) ptr++;
		if (ptr == N)
		{
			if (i + 1 != ans.size())
			{
				for (auto& s : ans.back())
				{
					ans[i].push_back(s);
				}
				ans.pop_back();
			}
			continue;
		}
		int cnt = 2;
		while (cnt--)
		{
			v.push_back(vs2[ptr].back());
			vs2[ptr].pop_back();
		}
	}
	while (!ans.empty() && ans.back().size() < 4)
		ans.pop_back();
	printf("%d\n", ans.size());
	for (auto& v : ans)
	{
		printf("%s %s\n", v[3].c_str(), v[0].c_str());
		printf("%s %s\n", v[2].c_str(), v[1].c_str());
	}
	return 0;
}