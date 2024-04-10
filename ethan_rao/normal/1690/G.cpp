#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 2, M = 8e5 + 2;
const int inf = 1.2e9;
struct Q
{
	int x, y;
	Q(int a = 0, int b = 0) : x(a), y(b) {}
};
Q b[N];
int l[M], r[M], mx[M], cnt[M];
int a[N], ys[N];
int n, m, q, i, x, y, z;
int cal(int x, int pre)
{
	int res = 0, c;
	while (mx[x] > pre && l[x] < r[x])
	{
		c = x << 1;
		if (mx[c] > pre)
			res += cnt[x], x = c;
		else
			x = c | 1;
	}
	return res + (mx[x] > pre);
}
void pushup(int x)
{
	int c = x << 1;
	mx[x] = max(mx[c], mx[c | 1]);
	cnt[x] = cal(c | 1, mx[c]);
}
void build(int x)
{
	if (l[x] == r[x])
		return ys[l[x]] = x, void();
	int c = x << 1;
	l[c] = l[x];
	r[c] = l[x] + r[x] >> 1;
	l[c | 1] = r[c] + 1;
	r[c | 1] = r[x];
	build(c);
	build(c | 1);
	pushup(x);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int testcase;
	for (cin >> testcase; testcase--;)
	{
		cin >> n >> q;
		for (i = 0; i < n; i++)
		{
			b[i].x = i + 1;
			cin >> b[i].y;
			a[i] = b[i].y;
		}
		for (i = 0; i < q; i++)
		{
			cin >> b[i + n].x >> b[i + n].y;
			b[i + n].y = (a[b[i + n].x - 1] -= b[i + n].y);
		}
		q += n;
		for (i = 0; i < q; i++)
			b[i].y = inf - b[i].y;
		r[l[1] = 1] = n;
		build(1);
		for (i = 0; i < q; i++)
		{
			x = b[i].x, y = b[i].y;
			z = ys[x];
			mx[z] = y;
			while (z >>= 1)
				pushup(z);
			if (i >= n)
				cout << cal(1, 0) << " \n"[i + 1 == q];
		}
	}
}