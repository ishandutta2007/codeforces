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
const int N = 1e2 + 10;
int ans[N][N];
char key[N * N];
vector<pair<int, int>> vp[N * N];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, a, b, c;
	cin >> n >> m >> a >> b >> c;
	if ((n * m) % 2 == 1)
	{
		puts("IMPOSSIBLE");
		return 0;
	}
	int l = 1, r = m;
	int u = 1, d = n;
	int cur = 1;
	if (n & 1)
	{
		if (a * 2 < m)
		{
			puts("IMPOSSIBLE");
			return 0;
		}
		for (int i = 1; i <= m; i += 2)
		{
			ans[n][i] = ans[n][i + 1] = cur;
			vp[cur].emplace_back(n, i);
			vp[cur].emplace_back(n, i + 1);
			cur++;
		}
		a -= m / 2;
		d--;
	}
	if (m & 1)
	{
		if (b * 2 < n)
		{
			puts("IMPOSSIBLE");
			return 0;
		}
		for (int i = 1; i <= n; i += 2)
		{
			ans[i][m] = ans[i + 1][m] = cur;
			vp[cur].emplace_back(i, m);
			vp[cur].emplace_back(i + 1, m);
			cur++;
		}
		b -= n / 2;
		r--;
	}
	a = a / 2 * 2;
	b = b / 2 * 2;
	if (a * 2 + b * 2 + c * 4 < (r - l + 1) * (d - u + 1))
	{
		puts("IMPOSSIBLE");
		return 0;
	}
	for (int i = 1; i <= d; i += 2)
	{
		for (int j = 1; j <= r; j += 2)
		{
			if (c > 0)
			{
				vp[cur].emplace_back(i, j);
				vp[cur].emplace_back(i, j + 1);
				vp[cur].emplace_back(i + 1, j);
				vp[cur].emplace_back(i + 1, j + 1);
				ans[i][j] = cur;
				ans[i][j + 1] = cur;
				ans[i + 1][j] = cur;
				ans[i + 1][j + 1] = cur;
				cur++;
				c--;
				continue;
			}
			if (a > 0)
			{
				vp[cur].emplace_back(i, j);
				vp[cur].emplace_back(i, j + 1);
				ans[i][j] = cur;
				ans[i][j + 1] = cur;
				cur++;

				vp[cur].emplace_back(i + 1, j);
				vp[cur].emplace_back(i + 1, j + 1);
				ans[i + 1][j] = cur;
				ans[i + 1][j + 1] = cur;
				cur++;

				a -= 2;
				continue;
			}
			if (b > 0)
			{
				vp[cur].emplace_back(i, j);
				vp[cur].emplace_back(i + 1, j);
				ans[i][j] = cur;
				ans[i + 1][j] = cur;
				cur++;

				vp[cur].emplace_back(i, j + 1);
				vp[cur].emplace_back(i + 1, j + 1);
				ans[i][j + 1] = cur;
				ans[i + 1][j + 1] = cur;
				cur++;

				b -= 2;
				continue;
			}
		}
	}
	for (int o = 1; o < cur; o++)
	{
		set<int> s;
		for (int i = 'a'; i <= 'z'; i++) s.insert(i);
		for (auto [x, y] : vp[o])
		{
			for (int t = 0; t < 4; t++)
			{
				s.erase(key[ans[x + dx[t]][y + dy[t]]]);
			}
		}
		key[o] = *s.begin();
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			putchar(key[ans[i][j]]);
		}
		puts("");
	}
	return 0;
}