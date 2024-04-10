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

int n = 1, a[200200];
long long sum, f[2000200];

void add(int nd, int l, int r, int x, int y, int v)
{
	if (l == x && r == y) f[nd] += v;
	else
	{
		int m = (l + r) / 2;
		f[nd * 2] += f[nd];
		f[nd * 2 + 1] += f[nd];
		f[nd] = 0;
		if (x <= m) add(nd * 2, l, m, x, min(y, m), v);
		if (m < y) add(nd * 2 + 1, m + 1, r, max(x, m + 1), y, v);
	}
}

long long get(int nd, int l, int r, int x)
{
	if (l == r) return f[nd];
	int m = (l + r) / 2;
	f[nd * 2] += f[nd];
	f[nd * 2 + 1] += f[nd];
	f[nd] = 0;
	if (x <= m) return get(nd * 2, l, m, x);
	return get(nd * 2 + 1, m + 1, r, x);
}

void remove(int nd, int l, int r, int x)
{
	if (l == r) f[nd] = 0;
	else
	{
		int m = (l + r) / 2;
		f[nd * 2] += f[nd];
		f[nd * 2 + 1] += f[nd];
		if (x <= m) remove(nd * 2, l, m, x);
		else remove(nd * 2 + 1, m + 1, r, x);
	}
}

int main()
{
	int Q, type, x, y;
	cin >> Q;
	while (Q--)
	{
		scanf("%d", &type);
		
		if (type == 1)
		{
			scanf("%d%d", &x, &y);
			sum += 1LL * x * y;
			add(1, 1, 200000, 1, x, y);
		}
		
		if (type == 2)
		{
			n++;
			scanf("%d", a + n);
			sum += a[n];
		}
		
		if (type == 3) 
		{
			sum = sum - a[n] - get(1, 1, 200000, n);
			remove(1, 1, 200000, n--);
		}
		
		printf("%.9lf\n", 1.0 * sum / n);
	}
}