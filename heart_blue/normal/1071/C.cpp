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
const int N = 1e6 + 10;
int dis[N];
int pre[N];
void init(int n)
{
	map < int, int> mc;
	queue<int> q;
	q.push(0);
	dis[0] = 1;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; i + 2 * j < n; j++)
		{
			int x, y, z;
			x = 1 << i;
			y = 1 << (i + j);
			z = 1 << (i + 2 * j);
			v.push_back(x | y | z);
		}
	}
	int maxv = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		maxv = max(maxv, dis[x]);
		for (auto &o : v)
		{
			if (!dis[x^o])
			{
				pre[x^o] = x;
				dis[x^o] = dis[x] + 1;
				q.push(x^o);
			}
		}
	}
}
vector<tuple<int, int, int>> vp;
void init2()
{
	vector<int> v;
	int tot = 1 << 9;
	int mask = tot - 1;
	vp.push_back({ 0,0,0 });
	for (int i = 0; i < 9; i++)
	{
		for (int j = 1; i + 2 * j < 18; j++)
		{
			int x = 1 << i;
			int y = 1 << (i + j);
			int z = 1 << (i + 2 * j);
			v.push_back({ x | y | z });
		}
	}
	for (int i = 1; i < tot; i++)
	{
		int flag = 0;
		for (auto &x : v)
		{
			if (((i^x)&mask) == 0)
			{
				vp.push_back({ x,0,0 });
				break;
			}
			for (auto &y : v)
			{
				if (((i^x^y)&mask) == 0)
				{
					vp.push_back({ x,y,0 });
					flag = 1;
					break;
				}
				for (auto &z : v)
				{
					if (((i^x^y^z)&mask) == 0)
					{
						vp.push_back({ x,y,z });
						flag = 1;
						break;
					}
				}
				if (flag) break;
			}
			if (flag) break;
		}
	}
}
int a[N];
vector<tuple<int, int, int>> ans;
void check(int l, int r)
{
	int tot = 0;
	int n = r - l + 1;
	int o = 0;
	for (int i = l; i <= r; i++)
	{
		tot |= a[i] << o;
		o++;
	}
	while (tot)
	{
		int x = pre[tot];
		int o = x ^ tot;
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			if ((o >> i) & 1)
			{
				v.push_back(i + l);
				a[i + l] ^= 1;
			}
		}
		tot = x;
		if (!v.empty()) ans.push_back({ v[0],v[1],v[2] });
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	init(min(n, 9));
	if (n <= 9)
	{
		int tot = 0;
		for (int i = 1; i <= n; i++)
		{
			tot |= a[i] << (i - 1);
		}
		if (dis[tot] == 0)
		{
			puts("NO");
			return 0;
		}
		check(1, n);
		puts("YES");
		printf("%d\n", ans.size());
		for (auto &p : ans)
		{
			int x, y, z;
			tie(x, y, z) = p;
			printf("%d %d %d\n", x, y, z);
		}
		return 0;
	}
	init2();
	int c = 1;
	for (int i = 1; i + 18 - 1 <= n; i += 9)
	{
		c = i + 9;
		int cur = 0;
		for (int j = 0; j < 9; j++)
		{
			cur |= a[i + j] << j;
		}
		int x, y, z;
		tie(x, y, z) = vp[cur];
		vector<int> v;
		v.push_back(x);
		v.push_back(y);
		v.push_back(z);
		for (auto &x : v)
		{
			vector<int> vv;
			for (int o = 0; o < 18; o++)
			{
				if (x >> o & 1)
				{
					vv.push_back(i + o);
					a[i + o] ^= 1;
				}
			}
			if (!vv.empty()) ans.push_back({ vv[0],vv[1],vv[2] });
		}
	}
	check(c, min(c + 9 - 1, n));
	check(n - 9 + 1, n);
	puts("YES");
	printf("%d\n", ans.size());
	for (auto &p : ans)
	{
		int x, y, z;
		tie(x, y, z) = p;
		printf("%d %d %d\n", x, y, z);
	}
	return 0;
}