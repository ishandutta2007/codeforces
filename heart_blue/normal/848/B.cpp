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
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
map<int, vector<tuple<int, int, int>>> mc[3];
pair<int, int> ans[N];
vector<tuple<int, int, int>> check(const vector<tuple<int, int, int>>& vp1,
	const vector<tuple<int, int, int>>& vp2)
{
	auto ret = vp1;
	for (auto& p : vp2)
		ret.push_back(p);
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, w, h;
	scanf("%d%d%d", &n, &w, &h);
	for (int i = 1; i <= n; i++)
	{
		int g, p, t;
		scanf("%d%d%d", &g, &p, &t);
		if (g == 1) mc[1][p - t].emplace_back(1, p, i), mc[2][p - t];
		else mc[2][p - t].emplace_back(2, p, i), mc[1][p - t];
	}
	for (auto& p : mc[1])
	{
		auto& vp1 = p.second;
		auto& vp2 = mc[2][p.first];
		sort(vp1.begin(), vp1.end());
		sort(vp2.rbegin(), vp2.rend());
		auto v1 = check(vp1, vp2);
		auto v2 = check(vp2, vp1);
		for (int i = 0; i < v2.size(); i++)
		{
			int pos = get<2>(v2[i]);
			int o, k;
			tie(o, k, ignore) = v1[i];
			if (o == 1) ans[pos] = { k,h };
			else ans[pos] = { w,k };
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}