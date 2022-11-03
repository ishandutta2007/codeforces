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
const int N = 1e5 + 10;
vector<int> solve(
	vector<pair<int, int>>& v0,
	vector<pair<int, int>>& v1,
	vector<pair<int, int>>& v2,
	vector<pair<int, int>>& v3,
	int k, int m, int& cur)
{
	priority_queue<pair<int, int>> pq0, pq1, pq2;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq3;
	int ans = 2 * INF;
	vector<int> res;
	int tot = 0;
	for (auto& p : v0) pq0.push(p), tot += p.first;
	for (auto& p : v1) pq1.push(p), tot += p.first;
	for (auto& p : v2) pq2.push(p), tot += p.first;
	int sum = 0;
	for (int i = 0; i <= v3.size(); i++)
	{
		while (!pq1.empty() && pq1.size() + i > k)
		{
			pq0.push(pq1.top());
			pq1.pop();
		}
		while (!pq2.empty() && pq2.size() + i > k)
		{
			pq0.push(pq2.top());
			pq2.pop();
		}
		while (!pq0.empty() && !pq3.empty())
		{
			auto p0 = pq0.top();
			auto p3 = pq3.top();
			if (p0 > p3)
			{
				tot -= pq0.top().first;
				tot += pq3.top().first;
				pq0.pop();
				pq3.pop();
				pq0.push(p3);
				pq3.push(p0);
			}
			else break;
		}
		while (!pq0.empty() && pq1.size() + pq2.size() + i + pq0.size() > m)
		{
			tot -= pq0.top().first;
			pq3.push(pq0.top());
			pq0.pop();
		}
		if (min(pq1.size(), pq2.size()) + i >= k && pq1.size() + pq2.size() + pq0.size() + i == m)
		{
			ans = min(ans, tot);
		}
		if (ans == cur) break;
		if (i == v3.size()) break;
		tot += v3[i].first;
		res.push_back(v3[i].second);
	}

	cur = ans;
	while (!pq0.empty())
	{
		res.push_back(pq0.top().second);
		pq0.pop();
	}
	while (!pq1.empty())
	{
		res.push_back(pq1.top().second);
		pq1.pop();
	}
	while (!pq2.empty())
	{
		res.push_back(pq2.top().second);
		pq2.pop();
	}
	return res;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	vector<pair<int, int>> v1;
	vector<pair<int, int>> v2;
	vector<pair<int, int>> v3;
	vector<pair<int, int>> v0;
	for (int i = 1; i <= n; i++)
	{
		int x, o1, o2;
		scanf("%d%d%d", &x, &o1, &o2);
		if (o1 == o2 && o1 == 1) v3.emplace_back(x, i);
		else if (o1 == 1) v1.emplace_back(x, i);
		else if (o2 == 1) v2.emplace_back(x, i);
		else v0.emplace_back(x, i);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	sort(v3.begin(), v3.end());
	int ans = -1;
	vector<int> key;
	solve(v0, v1, v2, v3, k, m, ans);
	if (ans == 2 * INF) puts("-1"), exit(0);
	key = solve(v0, v1, v2, v3, k, m, ans);
	printf("%d\n", ans);
	for (auto& x : key)
		printf("%d ", x);
	return 0;
}