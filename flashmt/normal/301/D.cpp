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

struct event
{
	int x, y, isQuery;
	
	event() {}
	event(int _x, int _y, int _isQuery) : x(_x), y(_y), isQuery(_isQuery) {}
	
	bool operator < (event u) const
	{
		if (x != u.x) return x < u.x;
		if (y != u.y) return y < u.y;
		return abs(isQuery) < abs(u.isQuery);
	}
};

int n, Q, f[200200], p[200200], E;
long long ans[200200];
event e[3300300];

void add(int x)
{
	for (int i = x; i <= n; i += i & -i) f[i]++;
}

int get(int x)
{
	int res = 0;
	for (int i = x; i; i -= i & -i) res += f[i];
	return res;
}

int main()
{
	int x, y;
	cin >> n >> Q;
	for (int i = 1; i <= n; i++) scanf("%d", &x), p[x] = i;
	for (int i = 1; i * 2 <= n; i++)
		for (int j = i * 2; j <= n; j += i)
			e[E++] = event(p[i], p[j], 0);
			
	for (int i = 1; i <= Q; i++)
	{
		scanf("%d%d", &x, &y);
		e[E++] = event(y, y, i);
		e[E++] = event(x - 1, x - 1, i);
		e[E++] = event(y, x - 1, -i);
		e[E++] = event(x - 1, y, -i);
		ans[i] = y - x + 1;
	}
	
	sort(e, e + E);
	for (int i = 0; i < E; i++)
		if (e[i].isQuery)
		{
			int id = e[i].isQuery, sign = 1;
			if (id < 0) id = -id, sign = -1;
			ans[id] += sign * get(e[i].y);
		}
		else add(e[i].y);
		
	for (int i = 1; i <= Q; i++) printf("%I64d\n", ans[i]);
}