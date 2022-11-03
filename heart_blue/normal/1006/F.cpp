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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 20 + 10;
map<LL, LL> mc1[N][N], mc2[N][N];
LL a[N][N];
int d[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	LL k;
	cin >> n >> m >> k;
	int x = 1, y = m;
	while (x <= n)
	{
		d[x] = max(1, y);
		x++, y--;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= d[i]; j++)
		{
			for (auto &p : mc1[i - 1][j]) mc1[i][j][a[i][j] ^ p.first] += p.second;
			for (auto &p : mc1[i][j - 1]) mc1[i][j][a[i][j] ^ p.first] += p.second;
			if (i == 1 && j == 1) mc1[i][j][a[i][j]] = 1;
		}
	}
	for (int i = n; i >= 1; i--)
	{
		for (int j = m; j >= d[i]; j--)
		{
			for (auto &p : mc2[i][j + 1]) mc2[i][j][a[i][j] ^ p.first] += p.second;
			for (auto &p : mc2[i + 1][j]) mc2[i][j][a[i][j] ^ p.first] += p.second;
			if (i == n && j == m) mc2[i][j][a[i][j]] = 1;
		}
	}
	LL ans = 0;
	x = 1, y = m;
	while (x <= n && y >= 1)
	{
		auto &m1 = mc1[x][y];
		auto &m2 = mc2[x][y];
		for (auto &p : m1)
		{
			if (m2.count(k^p.first^a[x][y]))
			{
				ans += p.second*m2[k^p.first^a[x][y]];
			}
		}
		x++, y--;
	}
	printf("%lld\n", ans);
	return 0;
}