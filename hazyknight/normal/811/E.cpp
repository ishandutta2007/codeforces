#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int MAXN = 100005;

int n,m,q;

struct Node
{
	int cnt;
	int lc[15],rc[15];
	int idl[15],idr[15];
	void update(int src,int lat)
	{
		for (int i = 1;i <= n;i++)
		{
			if (idl[i] == src)
				idl[i] = lat;
			if (idr[i] == src)
				idr[i] = lat;
		}
	}
}node[MAXN << 2];

int tot;
int col[15][MAXN];

Node merge(Node a,Node b)
{
	Node ret;
	for (int i = 1;i <= n;i++)
		ret.lc[i] = a.lc[i],ret.rc[i] = b.rc[i];
	ret.cnt = a.cnt + b.cnt;
	for (int i = 1;i <= n;i++)
		if (a.rc[i] == b.lc[i] && a.idr[i] != b.idl[i])
		{
			tot++;
			ret.cnt--;
			int x = a.idr[i],y = b.idl[i];
			a.update(x,tot);
			a.update(y,tot);
			b.update(x,tot);
			b.update(y,tot);
		}
	for (int i = 1;i <= n;i++)
		ret.idl[i] = a.idl[i],ret.idr[i] = b.idr[i];
	return ret;
}

void build_tree(int o,int l,int r)
{
	if (l == r)
	{
		for (int i = 1;i <= n;i++)
		{
			if (col[i][l] != col[i - 1][l])
				tot++,node[o].cnt++;
			node[o].lc[i] = node[o].rc[i] = col[i][l];
			node[o].idl[i] = node[o].idr[i] = tot;
		}
		return;
	}
	int mid = (l + r) >> 1;
	build_tree(o << 1,l,mid);
	build_tree(o << 1 | 1,mid + 1,r);
	node[o] = merge(node[o << 1],node[o << 1 | 1]);
}

Node query(int o,int l,int r,int x,int y)
{
	if (l >= x && r <= y)
		return node[o];
	int mid = (l + r) >> 1;
	if (mid < x)
		return query(o << 1 | 1,mid + 1,r,x,y);
	else if (mid + 1 > y)
		return query(o << 1,l,mid,x,y);
	else
		return merge(query(o << 1,l,mid,x,y),query(o << 1 | 1,mid + 1,r,x,y));
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			cin >> col[i][j];
	build_tree(1,1,m);
	for (int l,r,i = 1;i <= q;i++)
	{
		cin >> l >> r;
		cout << query(1,1,m,l,r).cnt << endl;
	}
	return 0;
}