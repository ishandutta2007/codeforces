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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
map<int, int> in;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	set<int> s1, s2, sp;
	int q;
	scanf("%d", &q);
	LL ans = 1;
	while (q--)
	{
		int x;
		scanf("%*s%d", &x);
		if (in[x] == 0)
		{
			if (!s1.empty() && x <= *s1.rbegin())
			{
				s1.emplace(x);
				in[x] = 1;
				continue;
			}
			if (!s2.empty() && x >= *s2.begin())
			{
				s2.emplace(x);
				in[x] = 2;
				continue;
			}
			sp.emplace(x);
			in[x] = 3;
			continue;
		}
		if (in[x] == 1)
		{
			if (x != *s1.rbegin())
			{
				puts("0");
				return 0;
			}
			s1.erase(x);
			for (auto& y : sp)
				s2.emplace(y), in[y] = 2;
			sp.clear();
			in[x] = 0;
			continue;
		}
		if (in[x] == 2)
		{
			if (x != *s2.begin())
			{
				puts("0");
				return 0;
			}
			s2.erase(x);
			for (auto& y : sp)
				s1.emplace(y), in[y] = 1;
			sp.clear();
			in[x] = 0;
			continue;
		}
		in[x] = 0;
		ans = ans * 2 % INF;
		for (auto& y : sp)
		{
			if (y < x) s1.emplace(y), in[y] = 1;
			if (y > x) s2.emplace(y), in[y] = 2;
		}
		sp.clear();
	}
	ans = ans * (sp.size() + 1) % INF;
	printf("%lld\n", ans);
	return 0;
}