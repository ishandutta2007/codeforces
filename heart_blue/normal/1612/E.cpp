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
map<int, int> mc[N];
vector<pair<int, int>> key;
bool cmp(const pair<LL, LL>& p1, const pair<LL, LL>& p2)
{
	auto [x1, y1] = p1;
	auto [x2, y2] = p2;
	return x1 * y2 > x2 * y1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x, k;
		scanf("%d%d", &x, &k);
		mc[x][k]++;
	}
	pair<LL, LL> maxv = { 0LL,1LL };
	for (int o = 1; o <= 30; o++)
	{
		vector<pair<int, int>> vp;
		for (int i = 1; i < N; i++)
		{
			if (mc[i].empty()) continue;
			int sum = 0;
			for (auto& p : mc[i])
			{
				auto [a, b] = p;
				sum += min(a, o) * b;
			}
			vp.emplace_back(sum, i);
		}
		sort(vp.rbegin(), vp.rend());
		while (vp.size() > o) vp.pop_back();
		if (vp.size() < o) continue;
		LL tot = 0;
		for (auto& p : vp)
		{
			tot += p.first;
		}
		if (cmp(make_pair(tot, o * 1LL), maxv))
		{
			maxv = make_pair(tot, o * 1LL);
			key = vp;
		}
	}
	printf("%d\n", key.size());
	for (auto& p : key)
		printf("%d ", p.second);
	return 0;
}