#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int BASE = 95542721;
const int PERIOD = 48;

int n, a[100100], reserve[800800], f[400400][50];

int cube(int x)
{
	return 1LL * x * x % BASE * x % BASE;
}

void init(int nd, int l, int r)
{
	if (l == r)
		for (int i = 0; i < PERIOD; i++)
			f[nd][i] = i ? cube(f[nd][i - 1]) : a[l];
	else
	{
		int m = (l + r) / 2;
		init(nd * 2, l, m);
		init(nd * 2 + 1, m + 1, r);
		for (int i = 0; i < PERIOD; i++)
			f[nd][i] = (f[nd * 2][i] + f[nd * 2 + 1][i]) % BASE;
	}
}

void updateNode(int nd, int v)
{
	rotate(f[nd], f[nd] + v, f[nd] + PERIOD);
	reserve[nd] = (reserve[nd] + v) % PERIOD;
}

void update(int nd, int l, int r, int x, int y)
{
	if (l == x && r == y) updateNode(nd, 1);
	else
	{
		int m = (l + r) / 2;
		if (reserve[nd])
		{
			updateNode(nd * 2, reserve[nd]);
			updateNode(nd * 2 + 1, reserve[nd]);
			reserve[nd] = 0;
		}			
		if (x <= m) update(nd * 2, l, m, x, min(y, m));
		if (m < y) update(nd * 2 + 1, m + 1, r, max(x, m + 1), y);
		for (int i = 0; i < PERIOD; i++) 
			f[nd][i] = (f[nd * 2][i] + f[nd * 2 + 1][i]) % BASE;
	}
}

int get(int nd, int l, int r, int x, int y)
{
	if (l == x && r == y) return f[nd][0];
	int m = (l + r) / 2, res = 0;
	if (reserve[nd])
	{
		updateNode(nd * 2, reserve[nd]);
		updateNode(nd * 2 + 1, reserve[nd]);
		reserve[nd] = 0;
	}			
	if (x <= m) res = get(nd * 2, l, m, x, min(y, m));
	if (m < y) res += get(nd * 2 + 1, m + 1, r, max(x, m + 1), y);
	return res % BASE;
}

int main()
{
	int x, y, Q, type;
	
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	init(1, 1, n);
	
	cin >> Q;
	while (Q--)
	{
		scanf("%d%d%d", &type, &x, &y);
		if (type == 2) update(1, 1, n, x, y);
		else printf("%d\n", get(1, 1, n, x, y));
	}
}