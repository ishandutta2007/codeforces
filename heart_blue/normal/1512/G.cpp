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
const int N = 1e5 + 10;
int p[N];
int a[N];
int tot = 0;
vector<tuple<int, int, int>> vp;
bool isprime(int x)
{
	if (x < N) return a[x] == 0;
	for (int i = 0; p[i] * p[i] <= x; i++)
	{
		if (x % p[i] == 0)
			return false;
	}
	return true;
}
void init()
{
	a[0] = a[1] = 1;
	const int maxv = 1e7;
	for (int i = 2; i < N; i++)
	{
		if (a[i]) continue;
		p[tot++] = i;
		for (int j = i + i; j < N; j += i)
			a[j] = 1;
		LL cur = 1LL * i * i;
		if (cur > maxv) continue;
		while (cur <= maxv)
		{
			LL sum = (cur * i - 1) / (i - 1);
			if (sum > maxv) break;
			vp.emplace_back(sum, cur, i);
			cur *= i;
		}
	}
	sort(vp.begin(), vp.end());
}
inline LL multy(LL a, LL b)
{
	if (a > INF * INF / b) return INF * INF;
	else return a * b;
}
LL ans = INF;
set<int> s;
void dfs(vector<int>& v, int cur, int x, int key)
{
	if (key >= ans) return;
	if (x == 1)
	{
		ans = key;
		return;
	}
	for (int i = cur; i < v.size(); i++)
	{
		if (x < v[i]) break;
		if (x % v[i]) continue;
		int d = v[i];
		if (isprime(d - 1) && s.count(d - 1) == 0)
		{
			s.insert(d - 1);
			dfs(v, i, x / d, key * (d - 1));
			s.erase(d - 1);
		}
		int ptr = lower_bound(vp.begin(), vp.end(), make_tuple(d, -1, -1)) - vp.begin();
		while (ptr < vp.size())
		{
			int sum, pro, y;
			tie(sum, pro, y) = vp[ptr++];
			if (sum != d) break;
			if (s.count(y)) continue;
			s.insert(y);
			dfs(v, i, x / d, key * pro);
			s.erase(y);
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int ncase;
	cin >> ncase;
	map<int, int> mc;
	while (ncase--)
	{
		int n;
		cin >> n;
		if (mc.count(n))
		{
			printf("%d\n", mc[n]);
			continue;
		}
		ans = INF;
		vector<int> v;
		for (int i = 1; i * i <= n; i++)
		{
			if (n % i) continue;
			v.push_back(i);
			if (i * i != n)
				v.push_back(n / i);
		}
		sort(v.begin(), v.end());
		v.erase(v.begin());
		dfs(v, 0, n, 1);
		if (ans == INF) ans = -1;
		mc[n] = ans;
		printf("%d\n", ans);
	}
	return 0;
}