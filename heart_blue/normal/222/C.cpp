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
int flag[N];
int p[N];
int a[N], b[N];
map<int, int> m1, m2;
void init()
{
	MEM(flag, 0);
	int k = 0;
	for (int i = 2; i < N; i++)
	{
		if (flag[i]) continue;
		for (int j = i; j < N; j += i) flag[j] = 1;
		p[k++] = i;
	}
}
void check(int x, map<int, int> &m)
{
	for (int i = 0; p[i] * p[i] <= x; i++)
	{
		while (x%p[i] == 0) x /= p[i], m[p[i]]++;
	}
	m[x]++;
}
int refrain(int x, map<int, int> &m)
{
	int o = x;
	for (int i = 0; p[i] * p[i] <= o; i++)
	{
		if (o%p[i] == 0)
		{
			while (o%p[i] == 0) o /= p[i];
			while (x%p[i] == 0 && m[p[i]] > 0) x /= p[i], m[p[i]]--;
		}
	}
	if (m[o] > 0) m[o]--, x /= o;
	return x;
}
void combine(map<int, int> &m1, map<int, int> &m2)
{
	for (auto &p : m1)
	{
		if (!m2.count(p.first))
		{
			p.second = 0;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]), check(a[i], m1);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]), check(b[i], m2);
	for (auto &p : m1)
	{
		if (m2.count(p.first))
			p.second = m2[p.first] = min(m2[p.first], p.second);
	}
	combine(m1, m2);
	combine(m2, m1);
	printf("%d %d\n", n, m);
	for (int i = 0; i < n; i++) printf("%d%c", refrain(a[i], m1), " \n"[i == n - 1]);
	for (int i = 0; i < m; i++) printf("%d%c", refrain(b[i], m2), " \n"[i == m - 1]);

	return 0;
}