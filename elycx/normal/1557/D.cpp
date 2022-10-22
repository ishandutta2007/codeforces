#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ll long long
#define maxn 600005
using namespace std;
int n, m, pos, tl, tr, a[maxn * 2];
struct node
{
	int Ls, Rs;
};
vector<node> tmp[maxn];
int t[maxn * 4], tag[maxn * 4];
int f[maxn], lst[maxn];
void pushup(int x)
{
	if(f[t[lc(x)]] > f[t[rc(x)]]) t[x] = t[lc(x)];
	else t[x] = t[rc(x)];
}
void pushdown(int x)
{
	if(!tag[x]) return;
	t[lc(x)] = tag[lc(x)] = t[rc(x)] = tag[rc(x)] = tag[x];
	tag[x] = 0;
}
void modify(int x, int l, int r, int a, int b, int c)
{
	if(a <= l && r <= b)
	{
		t[x] = c;
		tag[x] = c;
		return;
	}
	pushdown(x);
	int mid = (l + r) >> 1;
	if(a <= mid) modify(lc(x), l, mid, a, b, c);
	if(b > mid) modify(rc(x), mid + 1, r, a, b, c);
	pushup(x);
}
int que(int x, int l, int r, int a, int b)
{
	if(a <= l && r <= b) return t[x];
	pushdown(x);
	int mid = (l + r) >> 1, res = 0, tp = 0;
	if(a <= mid) tp = que(lc(x), l, mid, a, b);
	if(f[tp] > f[res]) res = tp;
	if(b > mid) tp = que(rc(x), mid + 1, r, a, b);
	if(f[tp] > f[res]) res = tp;
	return res;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &pos, &tl, &tr);
		tmp[pos].push_back((node){tl, tr});
		a[i * 2 - 1] = tl;
		a[i * 2] = tr;
	}
	sort(a + 1, a + 2 * m + 1);
	int len = unique(a + 1, a + 2 * m + 1) - a - 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < tmp[i].size(); j++)
		{
			tmp[i][j].Ls = lower_bound(a + 1, a + len + 1, tmp[i][j].Ls) - a;
			tmp[i][j].Rs = lower_bound(a + 1, a + len + 1, tmp[i][j].Rs) - a;
			//printf("%d %d\n", tmp[i][j].Ls, tmp[i][j].Rs);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < tmp[i].size(); j++)
		{
			int temp = que(1, 1, len, tmp[i][j].Ls, tmp[i][j].Rs);
			if(f[temp] > f[lst[i]]) lst[i] = temp;
		}
		f[i] = f[lst[i]] + 1;
		for (int j = 0; j < tmp[i].size(); j++)
		{
			modify(1, 1, len, tmp[i][j].Ls, tmp[i][j].Rs, i);
		}
	}
	int temp = que(1, 1, len, 1, len);
	printf("%d\n", n - f[temp]);
	for (int j = n; j > temp; j--) printf("%d ", j);
	while(temp != 0)
	{
		for (int j = temp - 1; j > lst[temp]; j--) printf("%d ", j);
		temp = lst[temp];
	}
	return 0;
}