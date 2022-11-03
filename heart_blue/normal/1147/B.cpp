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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	vector<pair<int, int>> vp;
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (x > y) swap(x, y);
		vp.emplace_back(x, y);
	}
	sort(vp.begin(), vp.end());
	set<int> s;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i) continue;
		s.emplace(i);
		s.emplace(n / i);
	}
	s.emplace(1);
	while (!s.empty())
	{
		int d = *s.rbegin();
		s.erase(d);
		vector<pair<int, int>> v;
		for (auto& p : vp)
		{
			int x, y;
			tie(x, y) = p;
			x += d;
			y += d;
			if (x > n) x -= n;
			if (y > n) y -= n;
			if (x > y) swap(x, y);
			v.emplace_back(x, y);
		}
		sort(v.begin(), v.end());
		if (v == vp) puts("Yes"), exit(0);
		int cur = 1;
		while (1)
		{
			auto iter = s.upper_bound(cur);
			if (iter == s.end()) break;
			cur = *iter;
			if (d % cur == 0)
				s.erase(cur);
		}
	}
	puts("No");
	return 0;
}