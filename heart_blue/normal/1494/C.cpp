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
const int N = 2e5 + 10;
int a[N];
int b[N];
int solve(int n, int m, int o)
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] * o > 0)
			v1.push_back(a[i] * o);
	}
	for (int i = 1; i <= m; i++)
	{
		if (b[i] * o > 0)
			v2.push_back(b[i] * o);
	}
	int cnt = 0;
	int ans = 0;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	map<int, int> mc;
	for (auto& x : v1)
	{
		auto iter = lower_bound(v2.begin(), v2.end(), x);
		if (iter != v2.end() && *iter == x) cnt++, mc[x]++;
	}
	ans = cnt;
	int ptr = 0;
	for (auto& x : v2)
	{
		while (ptr < v1.size() && v1[ptr] <= x)
			ptr++;
		if (mc.count(x)) cnt--;
		if (ptr == 0) continue;
		int r = x;
		int l = x - ptr + 1;
		int res = upper_bound(v2.begin(), v2.end(), r) - lower_bound(v2.begin(), v2.end(), l);
		ans = max(ans, res + cnt);
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
		printf("%d\n", solve(n, m, 1) + solve(n, m, -1));
	}
	return 0;
}