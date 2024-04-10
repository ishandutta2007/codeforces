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
const int N = 1e6 + 10;

void solve3(vector<pair<int, int>> v1, vector<pair<int, int>> v2, vector<pair<int, int>>& v3)
{
	reverse(v1.begin(), v1.end());
	reverse(v2.begin(), v2.end());
	while (!v1.empty() && v1.back().second != v2.back().second)
	{
		v3.push_back(v1.back());
		v1.pop_back();
	}
	while (!v1.empty() && !v2.empty())
	{
		int o = v1.back().second;
		while (!v1.empty() && v1.back().second == o)
		{
			v3.push_back(v1.back());
			v1.pop_back();
		}
		while (!v2.empty() && v2.back().second == o)
		{
			v3.push_back(v2.back());
			v2.pop_back();
		}
	}
	while (!v1.empty())
	{
		v3.push_back(v1.back());
		v1.pop_back();
	}
	while (!v2.empty())
	{
		v3.push_back(v2.back());
		v2.pop_back();
	}
}
void solve(vector<pair<int, int>>& vp, vector<int>& ans)
{
	vector<pair<int, int>> q;
	for (auto& p : vp)
	{
		if (q.empty() || q.back().second != p.second) q.emplace_back(1, p.second);
		else q.back().first++;
	}
	int sz = q.size();
	if (q.back().second == 0) sz--;
	int sum = 0;
	for (int i = 0; i < sz; i++)
	{
		sum += q[i].first;
		ans.push_back(sum);
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d", &n);
	vector<pair<int, int>> vp1, vp2, v1, v2;
	for (int i = 1; i <= n; i++)
	{
		int o;
		scanf("%d", &o);
		vp1.emplace_back(i, o);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int o;
		scanf("%d", &o);
		vp2.emplace_back(i + n, o);
	}
	vector<int> ans1, ans2;
	solve3(vp1, vp2, v1);
	solve(v1, ans1);
	solve3(vp2, vp1, v2);
	solve(v2, ans2);
	if (ans1.size() > ans2.size())
		ans1 = ans2, v1 = v2;
	for (auto& p : v1)
		printf("%d ", p.first);
	puts("");
	printf("%d\n", ans1.size());
	for (auto& x : ans1)
		printf("%d ", x);
	return 0;
}