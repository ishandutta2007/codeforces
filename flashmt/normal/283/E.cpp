#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

vector < pair<int,int> > query[100100];
int active[600600], sum[600600], a[100100];

void doFlip(int nd, int l, int r)
{
	sum[nd] = r - l + 1 - sum[nd];
	active[nd] ^= 1;
}

void flip(int nd, int l, int r, int x, int y)
{
	if (l == x && r == y) doFlip(nd, l, r);
	else
	{
		int m = (l + r) / 2;
		if (active[nd]) 
		{
			doFlip(nd * 2, l, m); 
			doFlip(nd * 2 + 1, m + 1, r);
			active[nd] = 0;
		}
		if (x <= m) flip(nd * 2, l, m, x, min(y, m));
		if (m < y) flip(nd * 2 + 1, m + 1, r, max(x, m + 1), y);
		sum[nd] = sum[nd * 2] + sum[nd * 2 + 1];
	}
}

int get(int nd, int l, int r, int x)
{
	if (l == r) return sum[nd];
	int m = (l + r) / 2;
	if (active[nd])
	{
		doFlip(nd * 2, l, m); 
		doFlip(nd * 2 + 1, m + 1, r);
		active[nd] = 0;
	}
	if (x <= m) return get(nd * 2, l, m, x);
	return get(nd * 2 + 1, m + 1, r, x);
}

int main()
{
	//freopen("e.in","r",stdin);
	int n, Q, L, R;
	
	cin >> n >> Q;
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	sort(a, a + n);

	while (Q--)
	{
		cin >> L >> R;
		L = lower_bound(a, a + n, L) - a;
		R = upper_bound(a, a + n, R) - a;
		if (L < R)
		{
			query[L].push_back(make_pair(L, R - 1));
			query[R].push_back(make_pair(L, R - 1));
		}
	}
		
	long long total = 0;
	for (int i = 0; i < n; i++)
	{
		if (i) flip(1, 0, n - 1, i - 1, i - 1);
		for (int j = 0; j < int(query[i].size()); j++)
			flip(1, 0, n - 1, query[i][j].first, query[i][j].second);
		long long win = sum[1] - get(1, 0, n - 1, i);
		total += win * (win - 1) / 2;
	}
	
	long long ans = 1LL * n * (n - 1) * (n - 2) / 6 - total;
	cout << ans << endl;
}