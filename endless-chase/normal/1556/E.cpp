#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, n, q, a[111111], b[111111], c[111111], l ,r;
long long pre[111111], mn[444444], mx[444444];
void pushup(int node)
{
	mn[node] = min(mn[node << 1], mn[(node << 1) | 1]);
	mx[node] = max(mx[node << 1], mx[(node << 1) | 1]);
}
void build(int l, int r, int node)
{
	if (l == r)
	{
		mn[node] = mx[node] = pre[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, node << 1);
	build(mid + 1, r, (node << 1) | 1);
	pushup(node);
}
long long qmn(int beg, int en, int l, int r, int node)
{
	if (l > en || r < beg) return 1e18;
	if (l >= beg && r <= en) return mn[node];
	int mid = (l + r) >> 1;
	return min(qmn(beg, en, l, mid, node << 1), qmn(beg, en, mid + 1, r, (node << 1) | 1));
}
long long qmx(int beg, int en, int l, int r, int node)
{
	if (l > en || r < beg) return -1e18;
	if (l >= beg && r <= en) return mx[node];
	int mid = (l + r) >> 1;
	return max(qmx(beg, en, l, mid, node << 1), qmx(beg, en, mid + 1, r, (node << 1) | 1));
}
int main()
{
	test = 1;
	while(test--)
	{
		scanf("%d%d", &n, &q);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		for (int i = 1; i <= n; i++)
		{
			c[i] = a[i] - b[i];
			pre[i] = pre[i - 1] + c[i];
		}
		build(1, n, 1);
		while(q--)
		{
			scanf("%d%d", &l, &r);
			if (pre[r] != pre[l - 1] || qmx(l, r, 1, n, 1) > pre[l - 1]) printf("-1\n");
			else printf("%lld\n", pre[l - 1] - qmn(l, r, 1, n, 1));
		}
	}
	return Accepted;
}