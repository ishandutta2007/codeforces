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
#include <complex>
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
map<int, vector<int>> mc;
tuple<int, int, int, int> solve(vector<int>& v, int o)
{
	vector<int> key;
	for (int i = 0; i < v.size(); i++)
	{
		if (i > 0 && v[i] - v[i - 1] > 1)
		{
			key.push_back(-(v[i] - v[i - 1] - 1));
		}
		key.push_back(1);
	}
	int cur = v[0] - 1;
	int sum = 0;
	int l = 0;
	tuple<int, int, int, int> maxv = { 1,cur + 1,cur + 1,o };
	for (auto& x : key)
	{
		if (sum + x <= x)
		{
			l = cur + 1;
			sum = x;
		}
		else
		{
			sum += x;
		}
		cur += abs(x);
		maxv = max(maxv, { sum, l, cur, o });
	}
	return maxv;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		mc.clear();
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			mc[x].push_back(i);
		}
		tuple<int, int, int, int> ans = { -1,-1,-1,-1 };
		for (auto& [x, v] : mc)
			ans = max(ans, solve(v,x));
		auto [res, l, r, o] = ans;
		printf("%d %d %d\n", o, l, r);
	}

	return 0;
}