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
const int N = 2e5 + 10;
map<LL, int> mc[N];
int dfs(int x, LL o)
{
	if (mc[x].count(o)) return mc[x][o];
	int &ret = mc[x][o] = 0;
	int flag[70];
	MEM(flag, 0);
	for (int i = 1; i <= x; i++)
	{
		if (o >> i & 1) continue;
		flag[dfs(x - i, 1 << i | o)] = 1;
	}
	for (int i = 0; i < 70; i++)
	{
		if (flag[i] == 0)
		{
			ret = i;
			break;
		}
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int l, r, u, d;
	int n, m;
	l = INF, r = 0, u = INF, d = 0;
	cin >> n >> m;
	map<pair<int, int>, int> mp;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char c;
			cin >> c;
			if (c == '*')
			{
				mp[{i, j}] = 1;
				l = min(l, j);
				r = max(r, j);
				u = min(u, i);
				d = max(d, i);
			}
		}
	}
	int a[2] = { u, d };
	int b[2] = { l, r };
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (mp.count({ a[i], b[j] })) continue;
			cout << a[i] << ' ' << b[j] << endl;
		}
	}
	return 0;
}