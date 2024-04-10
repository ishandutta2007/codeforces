#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>

using namespace std;

const int MAXN = 200005;

struct Node
{
	int to[105];
	bool change;
	void reset()
	{
		for (int i = 1;i <= 100;i++)
			to[i] = i;
		change = false;
	}
	Node(){reset();}
	void mark(int f,int t)
	{
		change = true;
		for (int i = 1;i <= 100;i++)
			if (to[i] == f)
				to[i] = t;
	}
}node[MAXN << 2];

int n,m,x,y,f,t;
int a[MAXN];

void push_down(int o)
{
	if (!node[o].change)
		return;
	node[o << 1].change = node[o << 1 | 1].change = true;
	for (int i = 1;i <= 100;i++)
		node[o << 1].to[i] = node[o].to[node[o << 1].to[i]];
	for (int i = 1;i <= 100;i++)
		node[o << 1 | 1].to[i] = node[o].to[node[o << 1 | 1].to[i]];
	node[o].reset();
}

void update(int o,int l,int r)
{
	if (l >= x && r <= y)
	{
		node[o].mark(f,t);
		return;
	}
	push_down(o);
	int mid = (l + r) >> 1;
	if (mid >= x)
		update(o << 1,l,mid);
	if (mid + 1 <= y)
		update(o << 1 | 1,mid + 1,r);
}

void print(int o,int l,int r)
{
	if (l == r)
	{
		cout << node[o].to[a[l]] << ' ';
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
	cin >> m;
	for (int i = 1;i <= m;i++)
	{
		cin >> x >> y >> f >> t;
		update(1,1,n);
	}
	print(1,1,n);
	cout << endl;
	return 0;
}