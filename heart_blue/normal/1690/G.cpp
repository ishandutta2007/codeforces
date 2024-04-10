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
const int N = 1e5 + 10;
int a[N];
set<pair<int, int>> s;
void change(int id, int x)
{
	auto [r, l] = *s.lower_bound(make_pair(id, -1));
	if (x >= a[l]) return;
	s.erase(make_pair(r, l));
	if (l < id) s.emplace(id - 1, l);
	while (1)
	{
		auto iter = s.lower_bound(make_pair(id, -1));
		if (iter == s.end()) break;
		auto [r1, l1] = *iter;
		if (a[l1] < x) break;
		r = r1;
		s.erase(make_pair(r1, l1));
	}
	s.emplace(r, id);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		s.clear();
		fill(a + 1, a + n + 1, int(INF));
		s.emplace(n, 1);
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			change(i, x);
			a[i] = x;
		}
		while (m--)
		{
			int id, x;
			scanf("%d%d", &id, &x);
			change(id, a[id] - x);
			a[id] -= x;
			printf("%d ", s.size());
		}
		puts("");
	}
	return 0;
}