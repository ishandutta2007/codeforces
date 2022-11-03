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
const int N = 5e5 + 10;
int in[N], out[N];
vector<int> vp[N];
int depth[N];
vector<int> d[N];
vector<int> v[N];
int dfn = 0;
char str[N];
void dfs(int x, int fa = -1)
{
	in[x] = ++dfn;
	depth[x] = 1;
	if (fa != -1) depth[x] = depth[fa] + 1;
	d[depth[x]].push_back(in[x]);
	int tmp = 0;
	if (!v[depth[x]].empty()) tmp = v[depth[x]].back();
	v[depth[x]].push_back((1 << (str[x] - 'a')) ^ tmp);
	for (auto &y : vp[x])
	{
		dfs(y, x);
	}
	out[x] = dfn;
}
inline bool getans(vector<int> &v, int l, int r)
{
	int tmp;
	if (l == -1) tmp = v[r];
	else tmp = v[r] ^ v[l];
	int cnt = 0;
	while (tmp)
	{
		tmp -= tmp&-tmp;
		cnt++;
		if (cnt > 1) return false;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; i++)
	{
		int fa;
		scanf("%d", &fa);
		vp[fa].push_back(i);
	}
	scanf("%s", str + 1);
	dfs(1);
	while (m--)
	{
		int x, h;
		scanf("%d%d", &x, &h);
		if (d[h].empty())
		{
			puts("Yes");
			continue;
		}
		auto pl = lower_bound(d[h].begin(), d[h].end(), in[x]);
		auto pr = upper_bound(d[h].begin(), d[h].end(), out[x]);
		if (pl == pr)
		{
			puts("Yes");
			continue;
		}
		int l = pl - d[h].begin(), r = pr - d[h].begin() - 1;
		if (getans(v[h], l - 1, r)) puts("Yes");
		else puts("No");
	}
	return 0;
}