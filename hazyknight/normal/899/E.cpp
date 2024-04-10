#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 200005;

struct Node
{
	int vall,valr;
	int llen,rlen,mlen,size;
	bool mark,same;
	pair<int,int> mmax;
	pair<int,int> lmax;
	pair<int,int> rmax;
}node[MAXN << 2];

int n,x,y,ans;
int a[MAXN];

void clear(int o)
{
	node[o].lmax = node[o].rmax = node[o].mmax = make_pair(-1,-1);
	node[o].vall = node[o].valr = -1;
	node[o].llen = node[o].rlen = node[o].mlen = -1;
	node[o].size = -1;
	node[o].same = false;
	node[o].mark = true;
}

void push_up(int o)
{
	int lch = (o << 1),rch = (o << 1 | 1);
	if (node[lch].mark && node[rch].mark)
	{
		clear(o);
		return;
	}
	else if (node[lch].mark)
	{
		node[o] = node[rch];
		return;
	}
	else if (node[rch].mark)
	{
		node[o] = node[lch];
		return;
	}
	else
	{
		node[o].size = node[lch].size + node[rch].size;
		node[o].same = (node[lch].same && node[rch].same && node[lch].valr == node[rch].vall);
		node[o].vall = node[lch].vall;
		node[o].valr = node[rch].valr;
		node[o].lmax = node[lch].lmax;
		node[o].llen = node[lch].llen;
		if (node[lch].same && node[lch].valr == node[rch].vall)
		{
			node[o].lmax = make_pair(node[lch].lmax.first,node[rch].lmax.second);
			node[o].llen = node[lch].size + node[rch].llen;
		}
		node[o].rmax = node[rch].rmax;
		node[o].rlen = node[rch].rlen;
		if (node[rch].same && node[lch].valr == node[rch].vall)
		{
			node[o].rmax = make_pair(node[lch].rmax.first,node[rch].rmax.second);
			node[o].rlen = node[rch].size + node[lch].rlen;
		}
		if (node[lch].mlen >= node[rch].mlen)
		{
			node[o].mmax = node[lch].mmax;
			node[o].mlen = node[lch].mlen;
			if (node[lch].valr == node[rch].vall && node[lch].rlen + node[rch].llen > node[o].mlen)
			{
				node[o].mmax = make_pair(node[lch].rmax.first,node[rch].lmax.second);
				node[o].mlen = node[lch].rlen + node[rch].llen;
			}
		}
		else
		{
			node[o].mmax = node[rch].mmax;
			node[o].mlen = node[rch].mlen;
			if (node[lch].valr == node[rch].vall && node[lch].rlen + node[rch].llen >= node[o].mlen)
			{
				node[o].mmax = make_pair(node[lch].rmax.first,node[rch].lmax.second);
				node[o].mlen = node[lch].rlen + node[rch].llen;
			}
		}
	}
}

void build_tree(int o,int l,int r)
{
	if (l == r)
	{
		node[o].vall = node[o].valr = a[l];
		node[o].mmax = node[o].lmax = node[o].rmax = make_pair(l,l);
		node[o].llen = node[o].rlen = node[o].mlen = 1;
		node[o].same = true;
		node[o].size = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build_tree(o << 1,l,mid);
	build_tree(o << 1 | 1,mid + 1,r);
	push_up(o);
}

void push_down(int o)
{
	if (node[o].mark)
	{
		clear(o << 1);
		clear(o << 1 | 1);
	}
}

void update(int o,int l,int r)
{
	if (l >= x && r <= y)
	{
		clear(o);
		return;
	}
	push_down(o);
	int mid = (l + r) >> 1;
	if (mid >= x)
		update(o << 1,l,mid);
	if (mid + 1 <= y)
		update(o << 1 | 1,mid + 1,r);
	push_up(o);
}

void print(int o,int l,int r)
{
//	cout << '[' << l << ',' << r << ']' << endl;
//	cout << "same=" << node[o].same << endl;
//	cout << "[->" << node[o].vall << "->" << node[o].valr << ']' << endl;
//	cout << "llen=" << node[o].llen << "rlen=" << node[o].rlen << endl;
//	cout << "l=(" << node[o].lmax.first << ',' << node[o].lmax.second << ')' << endl;
//	cout << "r=(" << node[o].rmax.first << ',' << node[o].rmax.second << ')' << endl;
//	cout << "m=(" << node[o].mmax.first << ',' << node[o].mmax.second << ')' << endl;
	if (l == r)
	{
		if (!node[o].mark)
			cout << node[o].vall << ' ';
		return;
	}
	push_down(o);
	int mid = (l + r) >> 1;
	print(o << 1,l,mid);
	print(o << 1 | 1,mid + 1,r);
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	build_tree(1,1,n);
	while (node[1].mmax.first != -1)
	{
		ans++;
		x = node[1].mmax.first,y = node[1].mmax.second;
		update(1,1,n);
	//	print(1,1,n);
	}
	cout << ans << endl;
	return 0;
}