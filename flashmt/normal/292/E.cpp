#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

int a[100100], b[100100], n, Q;
pair <int,int> f[800800];

void assign(int nd, pair <int,int> u)
{
	f[nd] = u;
}

void add(int nd, int l, int r, int x, int y, int u, int v)
{
	if (l == x && r == y) assign(nd, make_pair(u, v));
	else
	{
		if (f[nd].first) 
		{
			assign(nd * 2, f[nd]);
			assign(nd * 2 + 1, f[nd]);
			f[nd] = make_pair(0, 0);
		}
		int m = (l + r) / 2;
		if (x <= m) add(nd * 2, l, m, x, min(y, m), u, v);
		if (m < y) add(nd * 2 + 1, m + 1, r, max(x, m + 1), y, u, v);
	}
}

pair <int,int> get(int nd, int l, int r, int x)
{
	if (f[nd].first) return f[nd];
	if (l == r) return make_pair(0, 0);
	int m = (l + r) / 2;
	if (x <= m) return get(nd * 2, l, m, x);
	return get(nd * 2 + 1, m + 1, r, x);
}

int main()
{
	//freopen("e.in", "r", stdin);
	int x, y, k, type;
	
	cin >> n >> Q;
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= n; i++) scanf("%d", b + i);
	for (int i = 0; i < 800000; i++) f[i] = make_pair(0, 0);
	
	while (Q--)
	{
		scanf("%d", &type);
		if (type == 1)
		{
			scanf("%d%d%d", &x, &y, &k);
			add(1, 1, n, y, y + k - 1, x, y);
		}
		else 
		{
			scanf("%d", &x);
			pair <int,int> t = get(1, 1, n, x);
			if (!t.first) printf("%d\n", b[x]);
			else printf("%d\n", a[x - t.second + t.first]);
		}
	}
}