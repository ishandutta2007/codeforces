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
const int N = 1e5 + 10;
vector<int> v[N];
int p[N];
int flag[N];
int a[N];
int fa[N][20];
void init()
{
	int k = 0;
	for (int i = 2; i < N; i++)
	{
		if (v[i].empty())
		{
			v[i].push_back(i);
			p[k++] = i;
		}
		for (int j = 0; j < k && i * p[j] < N; j++)
		{
			v[i * p[j]] = v[i];
			v[i * p[j]].push_back(p[j]);
			if (i % p[j] == 0)
			{
				v[i * p[j]].pop_back();
				break;
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	int ptr = 1;
	for (int i = 1; i <= n; i++)
	{
		while (ptr <= n)
		{
			int ok = 1;
			for (auto& x : v[a[ptr]])
			{
				if (flag[x])
				{
					ok = 0;
					break;
				}
			}
			if (ok == 0) break;
			for (auto& x : v[a[ptr]])
			{
				flag[x] = 1;
			}
			ptr++;
		}
		fa[i][0] = ptr;
		for (auto& x : v[a[i]])
			flag[x] = 0;
	}
	fa[n + 1][0] = n + 1;
	for (int o = 0; o + 1 < 20; o++)
	{
		for (int i = 1; i <= n + 1; i++)
		{
			fa[i][o + 1] = fa[fa[i][o]][o];
		}
	}
	while (q--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		int ans = 0;
		for (int i = 19; i >= 0; i--)
		{
			if (fa[l][i] <= r)
				l = fa[l][i], ans |= 1 << i;
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}