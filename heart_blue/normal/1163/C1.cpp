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
const int N = 2e3 + 10;
LL ans = 0;
int tot = 0;
map<pair<int, int>, int> mc;
pair<int, int> p[N];
int flag[N][N];
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}

void refrain(int& n, int& m)
{
	if (n < 0) n = -n, m = -m;
	int g = gcd(abs(n), abs(m));
	n /= g, m /= g;
	if (n == 0) m = abs(m);
}
void add(int n, int m)
{
	refrain(n, m);
	tot++;
	mc[{n, m}]++;
	ans += tot - mc[{n, m}];
}
bool check(int x1, int y1, int x2, int y2)
{
	return x1 * y2 == y1 * x2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &p[i].first, &p[i].second);
	}
	for (int i = 1; i <= n; i++)
	{
		map<pair<int, int>, vector<int>> mv;
		for (int j = i + 1; j <= n; j++)
		{
			if (flag[i][j]) continue;
			int x = p[j].first - p[i].first, y = p[j].second - p[i].second;
			refrain(x, y);
			mv[{x, y}].emplace_back(j);
		}
		for (auto& p : mv)
		{
			auto& v = p.second;
			add(p.first.first, p.first.second);
			for (auto& x : v)
			{
				for (auto& y : v)
				{
					flag[x][y] = 1;
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}