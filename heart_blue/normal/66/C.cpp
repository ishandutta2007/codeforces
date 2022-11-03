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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<vector<string>> vs;
	string str;
	while (getline(cin, str))
	{
		vector<string> v;
		for (auto& c : str)
		{
			if (c == ':') c = ' ';
			if (c == '\\') c = ' ';
		}
		stringstream sin(str);
		while (sin >> str)
		{
			v.emplace_back(str);
		}
		v.pop_back();
		vs.emplace_back(v);
	}
	sort(vs.begin(), vs.end());
	int sum = 1;
	int ans1 = 1;
	for (int i = 1; i < vs.size(); i++)
	{
		if (vs[i][0] == vs[i - 1][0] && vs[i][1] == vs[i - 1][1]) sum++;
		else sum = 1;
		ans1 = max(ans1, sum);
	}
	sum = vs[0].size() - 2;
	int ans2 = 0;
	ans2 = max(ans2, sum);
	for (int i = 1; i < vs.size(); i++)
	{
		auto& v1 = vs[i - 1];
		auto& v2 = vs[i];
		if (v1[0] == v2[0] && v1[1] == v2[1])
		{
			int sz = min(v1.size(), v2.size());
			sum += v2.size() - 2;
			for (int j = 2; j < sz; j++)
			{
				if (v1[j] == v2[j])
				{
					sum--;
				}
				else
					break;
			}
		}
		else
		{
			sum = v2.size() - 2;
		}
		ans2 = max(ans2, sum);
	}
	printf("%d %d\n", ans2, ans1);
	return 0;
}