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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
map<string, vector<int>> ms;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, len;
	scanf("%d%d", &n, &len);
	while (n--)
	{
		string s;
		int val;
		cin >> s >> val;
		ms[s].push_back(val);
	}
	int maxv = 0;
	int ans = 0;
	for (auto& p : ms)
	{
		auto s1 = p.first;
		auto& v1 = p.second;
		auto s2 = s1;
		if (v1.empty()) continue;
		reverse(s2.begin(), s2.end());
		sort(v1.rbegin(), v1.rend());
		int sum1 = 0;
		int sum2 = 0;
		if (s1 == s2)
		{
			for (int i = 0; i + 1 < v1.size(); i += 2)
			{
				sum1 += max(0, v1[i] + v1[i + 1]);
			}
			sum2 += v1[0];
			for (int i = 1; i + 1 < v1.size(); i += 2)
			{
				sum2 += max(0, v1[i] + v1[i + 1]);
			}
		}
		else
		{
			auto& v2 = ms[s2];
			int sz = min(v1.size(), v2.size());
			sort(v2.rbegin(), v2.rend());
			for (int i = 0; i < sz; i++)
			{
				sum1 += max(0, v1[i] + v2[i]);
			}
			v2.clear();
		}
		ans += sum1;
		maxv = max(maxv, sum2 - sum1);
	}
	printf("%d\n", ans + maxv);
	return 0;
}