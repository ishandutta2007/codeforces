#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int MAXN = 200005;

struct Query
{
	int tp,l,r;
}a[MAXN];

int n,tot;
int val[MAXN];
int fa[MAXN];
int L[MAXN];
int R[MAXN];

vector<int> tag[MAXN << 2];

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

int find(int v)
{
	int low = 1,high = tot;
	while (low < high)
	{
		int mid = low + high >> 1;
		if (val[mid] < v)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

void Merge(int u,int v)
{
	u = getroot(u);
	v = getroot(v);
	if (u == v)
		return;
	fa[u] = v;
	L[v] = min(L[v],L[u]);
	R[v] = max(R[v],R[u]);
}

void merge(int o,int l,int r,int p,int id)
{
	if (tag[o].size())
	{
		for (int i = 0;i < tag[o].size();i++)
			Merge(tag[o][i],id);
		tag[o].clear();
		tag[o].push_back(id);
	}
	if (l == r)
		return;
	int mid = l + r >> 1;
	if (mid >= p)
		merge(o << 1,l,mid,p,id);
	else
		merge(o << 1 | 1,mid + 1,r,p,id);
}

void modify(int o,int l,int r,int x,int y,int id)
{
	if (l >= x && r <= y)
	{
		tag[o].push_back(id);
		return;
	}
	int mid = l + r >> 1;
	if (mid >= x)
		modify(o << 1,l,mid,x,y,id);
	if (mid + 1 <= y)
		modify(o << 1 | 1,mid + 1,r,x,y,id);
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d%d%d",&a[i].tp,&a[i].l,&a[i].r);
		if (a[i].tp == 1)
		{
			val[++tot] = a[i].l;
			val[++tot] = a[i].r;
		}
	}
	sort(val + 1,val + tot + 1);
	tot = unique(val + 1,val + tot + 1) - val - 1;
	int cur = 0;
	for (int i = 1;i <= n;i++)
	{
		if (a[i].tp == 1)
		{
			cur++;
			a[i].l = find(a[i].l);
			a[i].r = find(a[i].r);
			fa[cur] = cur;
			L[cur] = a[i].l;
			R[cur] = a[i].r;
			merge(1,1,tot,a[i].l,cur);
			merge(1,1,tot,a[i].r,cur);
			if (a[i].l + 1 <= a[i].r - 1)
				modify(1,1,tot,a[i].l + 1,a[i].r - 1,cur);
		}
		else
		{
			int ru = getroot(a[i].l),rv = getroot(a[i].r);
			puts(ru == rv || (L[ru] > L[rv] && L[ru] < R[rv]) || (R[ru] > L[rv] && R[ru] < R[rv]) ? "YES" : "NO");
		}
	}
	return 0;
}