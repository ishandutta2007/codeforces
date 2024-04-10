#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int oo = 1000000000;

struct panel
{
	int h, l, r;
	
	bool operator < (panel u) const
	{
		return h > u.h;
	}
} a[100100];

int n, M, val[1200200], f[100100];
vector <int> X, adj[100100];

void add(int nd, int l, int r, int x, int y, int v)
{
	if (l == x && r == y) val[nd] = v;
	else
	{
		int m = (l + r) / 2;
		if (val[nd] >= 0) val[nd * 2] = val[nd * 2 + 1] = val[nd], val[nd] = -1;
		if (x <= m) add(nd * 2, l, m, x, min(y, m), v);
		if (m < y) add(nd * 2 + 1, m + 1, r, max(x, m + 1), y, v);
	}
}

int get(int nd, int l, int r, int x, int y)
{
	if (l == x && r == y) return val[nd];
	int m = (l + r) / 2, t, u;
	if (val[nd] >= 0) val[nd * 2] = val[nd * 2 + 1] = val[nd];
	if (x <= m) t = get(nd * 2, l, m, x, min(y, m));
	if (m < y) u = get(nd * 2 + 1, m + 1, r, max(x, m + 1), y);
	if (x <= m && m < y) return t == u ? t : -1;
	return x <= m ? t : u;
}

int main()
{
	int T;
	cin >> n >> T;
	for (int i = 0; i < n; i++) scanf("%d%d%d", &a[i].h, &a[i].l, &a[i].r);
	a[n].h = T; 
	a[n].l = a[n + 1].l = -oo;
	a[n].r = a[n + 1].r = oo;
	n += 2;
	sort(a, a + n);
	
	for (int i = 0; i < n; i++) X.push_back(a[i].l), X.push_back(a[i].r);
	sort(X.begin(), X.end());
	M = unique(X.begin(), X.end()) - X.begin();
	X.resize(M);
	
	for (int i = 0; i < n; i++)
	{
		a[i].l = lower_bound(X.begin(), X.end(), a[i].l) - X.begin();
		a[i].r = lower_bound(X.begin(), X.end(), a[i].r) - X.begin();
	}
	
	// downward
	memset(val, -1, sizeof(val));
	for (int i = 0; i < n; i++)
	{
		int t = get(1, 0, M - 1, a[i].l, a[i].l);
		if (t >= 0) adj[i].push_back(t);
		int u = get(1, 0, M - 1, a[i].r - 1, a[i].r - 1);
		if (u >= 0) adj[i].push_back(u);
		add(1, 0, M - 1, a[i].l, a[i].r - 1, i);
	}
	
	// upward
	memset(val, -1, sizeof(val));
	for (int i = n - 1; i >= 0; i--)
	{
		int t = get(1, 0, M - 1, a[i].l, a[i].l);
		if (t >= 0) adj[t].push_back(i);
		int u = get(1, 0, M - 1, a[i].r - 1, a[i].r - 1);
		if (u >= 0) adj[u].push_back(i);
		add(1, 0, M - 1, a[i].l, a[i].r - 1, i);
	}
	
	// calc
	memset(val, -1, sizeof(val));
	f[0] = oo * 2;
	for (int i = 0; i < n; i++)
	{
		for (int jj = 0; jj < int(adj[i].size()); jj++)
		{
			int j = adj[i][jj], L = max(a[i].l, a[j].l), R = min(a[i].r, a[j].r);
			if (get(1, 0, M - 1, L, R - 1) == j) f[i] = max(f[i], min(f[j], X[R] - X[L]));
		}
		add(1, 0, M - 1, a[i].l, a[i].r - 1, i);
	}
	
	cout << f[n - 1] << endl;
}