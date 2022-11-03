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
const int N = 3e5 + 10;
int gl[N][20];
int gr[N][20];
int l[N];
int r[N];
int a[N];
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
void init(int n)
{
	for (int o = 1; o < 20; o++)
	{
		for (int i = 1; i + (1 << o) <= n + 1; i++)
		{
			gr[i][o] = gcd(gr[i][o - 1], gr[i + (1 << (o - 1))][o - 1]);
		}
		for (int i = (1 << o); i <= n; i++)
		{
			gl[i][o] = gcd(gl[i][o - 1], gl[i - (1 << (o - 1))][o - 1]);
		}
	}
}
int solve(int x)
{
	l[x] = r[x] = 0;
	int t = x;
	for (int i = 19; i >= 0; i--)
	{
		if (gr[t][i] == 0) continue;
		if (gr[t][i] % a[x] == 0)
		{
			r[x] |= 1 << i;
			t += 1 << i;
		}
	}
	t = x;
	for (int i = 19; i >= 0; i--)
	{
		if (gl[t][i] == 0) continue;
		if (gl[t][i] % a[x] == 0)
		{
			l[x] |= 1 << i;
			t -= 1 << i;
		}
	}
	return l[x] + r[x];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	MEM(gr, 0);
	MEM(gl, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		gr[i][0] = gl[i][0] = a[i];
	}
	init(n);
	int maxv = 0;
	for (int i = 1; i <= n; i++)
	{
		maxv = max(maxv, solve(i));
	}
	int cnt = 0;
	map<int, int> mc;
	for (int i = 1; i <= n; i++)
	{
		if (maxv == l[i] + r[i]) mc[i - l[i] + 1] = 1;
	}
	printf("%d %d\n", mc.size(), maxv - 2);
	for (auto &p : mc)
	{
		printf("%d ", p.first);
	}
	return 0;
}