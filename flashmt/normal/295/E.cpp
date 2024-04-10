#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int n, a[100100], cur[100100], type[100100], x[100100], y[100100], sz, node[1600600];
long long f[1600600], s[1600600];
vector <int> X;

void add(int nd, int l, int r, int x, int v, int u)
{
	if (l == r)
	{
		node[nd] += u; s[nd] += v;
		return;
	}
	int m = (l + r) / 2;
	if (x <= m) add(nd * 2, l, m, x, v, u);
	else add(nd * 2 + 1, m + 1, r, x, v, u);
	f[nd] = f[nd * 2] + f[nd * 2 + 1] + s[nd * 2 + 1] * node[nd * 2] - s[nd * 2] * node[nd * 2 + 1];
	s[nd] = s[nd * 2] + s[nd * 2 + 1];
	node[nd] = node[nd * 2] + node[nd * 2 + 1];
}

long long get(int nd, int l, int r, int x, int y, long long &sum, int &cntNode)
{
	if (l == x && r == y)
	{
		sum = s[nd]; cntNode = node[nd];
		return f[nd];
	}
	int m = (l + r) / 2, cntNodeL = 0, cntNodeR = 0;
	long long fL = 0, fR = 0, sumL = 0, sumR = 0;
	if (x <= m) fL = get(nd * 2, l, m, x, min(y, m), sumL, cntNodeL);
	if (m < y) fR = get(nd * 2 + 1, m + 1, r, max(x, m + 1), y, sumR, cntNodeR);
	cntNode = cntNodeL + cntNodeR;
	sum = sumL + sumR;
	return fL + fR + sumR * cntNodeL - sumL * cntNodeR;
}

int getId(int x)
{
	return lower_bound(X.begin(), X.end(), x) - X.begin();
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d", a + i);
		cur[i] = a[i];
		X.push_back(cur[i]);
	}
	
	int Q;
	cin >> Q;
	for (int i = 1; i <= Q; i++)
	{
		scanf("%d%d%d", type + i, x + i, y + i);
		if (type[i] == 1)
		{
			cur[x[i]] += y[i];
			X.push_back(cur[x[i]]);
		}
	}
	
	sort(X.begin(), X.end());
	int sz = unique(X.begin(), X.end()) - X.begin();
	X.resize(sz);
	
	for (int i = 1; i <= n; i++) add(1, 0, sz - 1, getId(a[i]), a[i], 1);
	for (int i = 1; i <= Q; i++)
		if (type[i] == 1)
		{
			add(1, 0, sz - 1, getId(a[x[i]]), -a[x[i]], -1);
			a[x[i]] += y[i];
			add(1, 0, sz - 1, getId(a[x[i]]), a[x[i]], 1);
		}
		else
		{
			int L = lower_bound(X.begin(), X.end(), x[i]) - X.begin();
			int R = upper_bound(X.begin(), X.end(), y[i]) - X.begin();
			long long ans = 0, tmp;
			int tmpp;
			if (L < R) ans = get(1, 0, sz - 1, L, R - 1, tmp, tmpp);
			printf("%I64d\n", ans);
		}
			
}