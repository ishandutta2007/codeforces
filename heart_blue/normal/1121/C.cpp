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
const int N = 2e5 + 10;
int per(int tot, int cur)
{
	return (cur * 100 + tot / 2) / tot;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	map<pair<int, int>, int> mc;
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		q.push(x);
	}
	int cur = 0;
	map<int, int> ans;
	while (!q.empty() || !mc.empty())
	{
		while (mc.size() < k && !q.empty())
		{
			mc[make_pair(q.front(), q.size())] = 0;
			q.pop();
		}
		vector<pair<int, int>> vp;
		int key = per(n, cur);
		for (auto& p : mc)
		{
			p.second++;
			if (p.second == key) ans[p.first.second] = 1;
			if (p.second == p.first.first)
				vp.emplace_back(p.first);
		}
		for (auto& p : vp)
			mc.erase(p), cur++;
	}
	printf("%d\n", ans.size());
	return 0;
}