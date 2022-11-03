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
set<LL> sp;
map<LL, vector<LL>> mv;
map<LL, set<pair<int, int>>> ms;
map<LL, int> mc;
void del(set<pair<int, int>>& s, int x)
{
	auto [r, l] = *s.lower_bound(make_pair(x, -1));
	if (x < l || x > r) return;
	s.erase(make_pair(r, l));
	if (x > l) s.emplace(x - 1, l);
	if (r > x) s.emplace(r, x + 1);
}
void add(set<pair<int, int>>& s, int x)
{
	auto iter = s.lower_bound(make_pair(x, -1));
	auto [r2, l2] = *iter;
	if (x >= l2 && x <= r2) return;
	iter--;
	auto [r1, l1] = *iter;
	if (r1 + 2 == l2)
	{
		s.erase(make_pair(r2, l2));
		s.erase(make_pair(r1, l1));
		s.emplace(r2, l1);
	}
	else if (x + 1 == l2)
	{
		s.erase(make_pair(r2, l2));
		s.emplace(r2, x);
	}
	else if (r1 + 1 == x)
	{
		s.erase(make_pair(r1, l1));
		s.emplace(x, l1);
	}
	else
		s.emplace(x, x);
}
void solve(LL x)
{
	auto& s = ms[x];
	if (s.empty())
	{
		s.emplace(-1, -1);
		int inf = 1e9;
		s.emplace(inf, inf);
	}
	int cur = s.begin()->first + 1;
	while (mc.count(cur * x))
	{
		add(s, cur);
		mv[cur * x].push_back(x);
		cur = s.begin()->first + 1;
	}
	printf("%lld\n", cur * x);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	scanf("%d", &q);
	char op;
	LL x;
	mc[0] = 1;
	while (q--)
	{
		scanf(" %c %lld", &op, &x);
		if (op == '+')
		{
			mc[x] = 1;
		}
		if (op == '-')
		{
			mc.erase(x);
			for (auto& d : mv[x])
				del(ms[d], x / d);
		}
		if (op == '?')
		{
			solve(x);
		}
	}
	return 0;
}