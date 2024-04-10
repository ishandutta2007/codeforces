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
int in[N];
map<int, vector<pair<int, int>>> mc1, mc2;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> ans;
void refrain()
{
	while (!pq.empty())
	{
		auto [h, id] = pq.top();
		if (in[id] == 0)
		{
			pq.pop();
		}
		else
			break;
	}
}
void add(int x, int y)
{
	if (!ans.empty() && ans.back() == make_pair(x, y))
		return;
	while (ans.size() >= 2)
	{
		int y1 = ans[ans.size() - 2].second;
		int y2 = ans[ans.size() - 1].second;
		if (y1 == y2 && y2 == y)
			ans.pop_back();
		else
			break;
	}
	ans.emplace_back(x, y);
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	set<int> s;
	for (int i = 1; i <= n; i++)
	{
		int h, l, r;
		scanf("%d%d%d", &h, &l, &r);
		mc1[l].emplace_back(h, i);
		mc2[r].emplace_back(h, i);
		s.insert(l);
		s.insert(r);
	}
	pq.emplace(0, 0);
	in[0] = 1;

	for (auto x : s)
	{
		add(x, pq.top().first);
		if (mc1.count(x))
		{
			auto& v = mc1[x];
			for (auto [h, pos] : v)
			{
				pq.emplace(h, pos);
				in[pos] ^= 1;
			}
		}
		if (mc2.count(x))
		{
			auto& v = mc2[x];
			for (auto [h, pos] : v)
			{
				in[pos] ^= 1;
			}
		}
		refrain();
		add(x, pq.top().first);
	}
	printf("%d\n", ans.size());
	for (auto [x, y] : ans)
		printf("%d %d\n", x, y);

	return 0;
}