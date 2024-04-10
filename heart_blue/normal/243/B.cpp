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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> v[N];
int n, m, h, t;
vector<int> ans1;
vector<int> ans2;
inline int Find(vector<int> &v, int x)
{
	auto iter = lower_bound(v.begin(), v.end(), x);
	if (iter == v.end()) return -1;
	if (*iter != x) return -1;
	return x;
}
void check(int x, int y)
{
	if (v[x].size() > v[y].size()) swap(x, y);
	if (v[x].size() + v[y].size() + 2 < h + t) return;
	vector<int> vp;
	for (auto &u : v[x])
	{
		if (u == y) continue;
		int res = Find(v[y], u);
		if (res != -1) vp.push_back(res);
	}
	int sz1 = v[x].size() - vp.size() - 1;
	int sz2 = v[y].size() - vp.size() - 1;
	int sz = vp.size();
	if (max(0, h - sz1) + max(0, t - sz2) <= sz)
	{
		for (auto &u : v[x])
		{
			if (u == y) continue;
			if (Find(vp, u) != -1) continue;
			if (ans1.size() < h) ans1.push_back(u);
		}
		for (auto &u : v[y])
		{
			if (u == x) continue;
			if (Find(vp, u) != -1) continue;
			if (ans2.size() < t) ans2.push_back(u);
		}
		while (ans1.size() < h && !vp.empty())
		{
			ans1.push_back(vp.back());
			vp.pop_back();
		}
		while (ans2.size() < t && !vp.empty())
		{
			ans2.push_back(vp.back());
			vp.pop_back();
		}
	}
	else if (max(0, t - sz1) + max(0, h - sz2) <= sz)
	{
		swap(h, t);
		for (auto &u : v[x])
		{
			if (u == y) continue;
			if (Find(vp, u) != -1) continue;
			if (ans1.size() < h) ans1.push_back(u);
		}
		for (auto &u : v[y])
		{
			if (u == x) continue;
			if (Find(vp, u) != -1) continue;
			if (ans2.size() < t) ans2.push_back(u);
		}
		while (ans1.size() < h && !vp.empty())
		{
			ans1.push_back(vp.back());
			vp.pop_back();
		}
		while (ans2.size() < t && !vp.empty())
		{
			ans2.push_back(vp.back());
			vp.pop_back();
		}
		swap(x, y), swap(h, t);
		swap(ans1, ans2);
	}
	else return;
	puts("YES");
	printf("%d %d\n", x, y);
	for (auto &u : ans1) printf("%d ", u);
	puts("");
	for (auto &u : ans2) printf("%d ", u);
	puts("");
	exit(0);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d%d", &n, &m, &h, &t);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		sort(v[i].begin(), v[i].end());
	for (int i = 1; i <= n; i++)
	{
		for (auto &y : v[i])
		{
			if (i > y) continue;
			check(i, y);
		}
	}
	puts("NO");
	return 0;
}