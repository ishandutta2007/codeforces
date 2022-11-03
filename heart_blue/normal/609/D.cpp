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
const int N = 2e5 + 10;
int a[N];
int b[N];
vector<pair<int, int>> ans;
vector<pair<int, int>> vp1, vp2;
int n, m, k, s;
bool solve(int mid)
{
	pair<int, int> minv1 = { int(INF),int(INF) };
	pair<int, int> minv2 = minv1;
	for (int i = 1; i <= mid; i++)
	{
		minv1 = min(minv1, { a[i],i });
		minv2 = min(minv2, { b[i],i });
	}
	int ptr1 = 0, ptr2 = 0;
	LL cost = 0;
	int cnt = 0;
	ans.clear();
	while (ptr1 < vp1.size() && ptr2 < vp2.size())
	{
		if (cnt == k) break;
		if (vp1[ptr1].first * 1LL * minv1.first <= vp2[ptr2].first * 1LL * minv2.first)
		{
			ans.emplace_back(vp1[ptr1].second, minv1.second);
			cost += vp1[ptr1].first * 1LL * minv1.first;
			ptr1++;
		}
		else
		{
			ans.emplace_back(vp2[ptr2].second, minv2.second);
			cost += vp2[ptr2].first * 1LL * minv2.first;
			ptr2++;
		}
		cnt++;
	}
	while (ptr1 < vp1.size() && cnt < k)
	{
		ans.emplace_back(vp1[ptr1].second, minv1.second);
		cnt++;
		cost += vp1[ptr1].first * 1LL * minv1.first;
		ptr1++;
	}
	while (ptr2 < vp2.size() && cnt < k)
	{
		ans.emplace_back(vp2[ptr2].second, minv2.second);
		cnt++;
		cost += vp2[ptr2].first * 1LL * minv2.first;
		ptr2++;
	}
	return cost <= s;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d%d", &n, &m, &k, &s);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= m; i++)
	{
		int t, c;
		scanf("%d%d", &t, &c);
		if (t == 1) vp1.emplace_back(c, i);
		else vp2.emplace_back(c, i);
	}
	sort(vp1.begin(), vp1.end());
	sort(vp2.begin(), vp2.end());
	int l = 1, r = n;
	int res = -1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (solve(mid)) res = mid, r = mid - 1;
		else l = mid + 1;
	}
	if (res == -1) puts("-1"), exit(0);
	solve(res);
	printf("%d\n", res);
	for (auto& [q, d] : ans)
		printf("%d %d\n", q, d);
	return 0;
}