#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int base = int(1e9 + 7);

int n, a[100100], val[800800], c[6][6];
long long f[6][800800], s[6][100100], p[100100][6];

void updateNode(int nd, int l, int r, int v)
{
	for (int i = 0; i < 6; i++) 
		f[i][nd] = (s[i][r] - s[i][l - 1] + base) % base * v % base;
	val[nd] = v;
}

void update(int nd, int l, int r, int x, int y, int v)
{
	if (l == x && r == y)
	{
		updateNode(nd, l, r, v);
		return;
	}
	
	int m = (l + r) / 2;
	if (val[nd] >= 0) 
	{
		updateNode(nd * 2, l, m, val[nd]);
		updateNode(nd * 2 + 1, m + 1, r, val[nd]);
		val[nd] = -1;
	}
	
	if (x <= m) update(nd * 2, l, m, x, min(y, m), v);
	if (m < y) update(nd * 2 + 1, m + 1, r, max(x, m + 1), y, v);
	for (int i = 0; i < 6; i++)
		f[i][nd] = (f[i][nd * 2] + f[i][nd * 2 + 1]) % base;
}

int get(int nd, int l, int r, int x, int y, int z, int L)
{
	if (l == x && r == y)
	{
		long long res = 0;
		for (int i = 0; i <= z; i++)
			res += f[z - i][nd] * p[L][i] % base * c[z][i] % base;
		res %= base;
		if (res < 0) res += base;
		return int(res);
	}
	
	int m = (l + r) / 2, res = 0;
	if (val[nd] >= 0) 
	{
		updateNode(nd * 2, l, m, val[nd]);
		updateNode(nd * 2 + 1, m + 1, r, val[nd]);
		val[nd] = -1;
	}
	
	if (x <= m) res += get(nd * 2, l, m, x, min(y, m), z, L);
	if (m < y) res += get(nd * 2 + 1, m + 1, r, max(x, m + 1), y, z, L);
	return res % base;
}

int main()
{
	memset(val, -1, sizeof(val));
	for (int i = 0; i <= 100000; i++)
	{
		p[i][0] = 1;
		for (int j = 1; j < 6; j++) p[i][j] = p[i][j - 1] * i % base;
	}
	for (int i = 0; i < 6; i++)
		for (int j = 0; j <= i; j++)
		{
			c[i][j] = j ? abs(c[i - 1][j]) + abs(c[i - 1][j - 1]) : 1;
			if (j % 2) c[i][j] = -c[i][j];
		}
	
	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d", a + i);
		for (int j = 0; j < 6; j++)
			s[j][i] = (s[j][i - 1] + p[i][j]) % base;
		update(1, 1, n, i, i, a[i]);
	}
	
	while (m--)
	{
		char c;
		int x, y, z;
		scanf(" %c%d%d%d", &c, &x, &y, &z);
		if (c == '=') update(1, 1, n, x, y, z);
		else printf("%d\n", get(1, 1, n, x, y, z, x - 1));
	}
}