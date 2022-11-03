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
const int N = 1e5 + 10;
vector<int> v[N];
int w[N];
pair<LL, LL> res[N];
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n%m);
}
pair<LL, LL> combine(pair<LL, LL> p1, pair<LL, LL> p2)
{
	if (p1.first == -1) return p2;
	if (p1.first == 0 || p2.first == 0) return { 0LL,1LL };
	LL lcm = p1.second / gcd(p1.second, p2.second) * p2.second;
	return { p1.first / lcm * lcm + p2.first / lcm * lcm,lcm };
}
LL multy(LL a, LL b)
{
	if (a > INF*INF / b) return INF * INF;
	else return a * b;
}
void dfs(int x, int fa = 0)
{
	int sons = 0;
	LL lcm = 1;
	LL minv = INF * INF;
	for (auto &y : v[x])
	{
		if (y == fa) continue;
		dfs(y, x);
		lcm = multy(lcm / gcd(lcm, res[y].second), res[y].second);
		sons++;
		minv = min(minv, res[y].first);
	}
	if (sons == 0)
	{
		res[x] = { w[x] * 1LL,1LL };
		return;
	}
	minv = minv / lcm * lcm;
	res[x] = { minv*sons,multy(sons,lcm) };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	LL tot = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
		tot += w[i];
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	printf("%lld\n", tot - res[1].first);
	return 0;
}