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
const int N = 5e3 + 10;

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
		vector<int> v(n);
		map<int, int> mc;
		for (auto& x : v)
		{
			scanf("%d", &x);
			mc[x] ^= 1;
		}
		int sum = 0;
		for (auto& p : mc)
		{
			sum += p.second;
		}
		if (sum > 0)
		{
			puts("-1");
			continue;
		}
		int cur = 0;
		vector<pair<int, int>> ans2;
		vector<int> ans1;
		while (!v.empty())
		{
			int pos = find(v.begin() + 1, v.end(), v[0]) - v.begin();
			int l = cur + 1;
			int r = cur + pos + 1;
			int o = r;
			for (int i = l + 1; i < r; i++)
			{
				ans2.emplace_back(o++, v[i - l]);
			}
			ans1.push_back((r - l) * 2);
			reverse(v.begin(), v.begin() + pos + 1);
			v.erase(v.begin() + pos);
			v.erase(v.begin());
			cur += (r - l) * 2;
		}
		printf("%d\n", ans2.size());
		for (auto [l, r] : ans2)
			printf("%d %d\n", l, r);
		printf("%d\n", ans1.size());
		for (int i = 0; i < ans1.size(); i++)
			printf("%d%c", ans1[i], " \n"[i + 1 == ans1.size()]);
	}
	return 0;
}