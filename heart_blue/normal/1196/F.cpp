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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<pair<int, int>> vp[N];
LL dis[N];
vector<int> v;
vector<LL> ans;
void solve(int rt)
{
	for (auto& x : v)
	{
		dis[x] = INF * INF;
	}
	typedef pair<LL, int> Node;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	pq.emplace(0LL, rt);
	dis[rt] = 0;
	while (!pq.empty())
	{
		auto [d, x] = pq.top();
		pq.pop();
		if (d != dis[x]) continue;
		for (auto [y, w] : vp[x])
		{
			if (dis[y] > d + w)
			{
				dis[y] = d + w;
				pq.emplace(dis[y], y);
			}
		}
	}
	for (auto& x : v)
	{
		if (x > rt)
			ans.push_back(dis[x]);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	vector<tuple<int, int, int>> key;
	while (m--)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		key.emplace_back(w, x, y);
	}
	sort(key.begin(), key.end());
	while (key.size() > k) key.pop_back();
	for (auto [w, x, y] : key)
	{
		v.push_back(x);
		v.push_back(y);
		vp[x].emplace_back(y, w);
		vp[y].emplace_back(x, w);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (auto& x : v)
	{
		solve(x);
	}
	sort(ans.begin(), ans.end());
	printf("%lld\n", ans[k - 1]);
	return 0;
}