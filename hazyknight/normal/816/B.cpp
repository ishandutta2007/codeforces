#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <queue>

using namespace std;

const int MAXN = 200005;

int n,k,q,a,b;
int sum[MAXN];
int laz[MAXN << 2];

void push_down(int o)
{
	laz[o << 1] += laz[o];
	laz[o << 1 | 1] += laz[o];
	laz[o] = 0;
}

void update(int o,int l,int r,int x,int y)
{
	if (l >= x && r <= y)
	{
		laz[o]++;
		return;
	}
	push_down(o);
	int mid = (l + r) >> 1;
	if (mid >= x)
		update(o << 1,l,mid,x,y);
	if (mid + 1 <= y)
		update(o << 1 | 1,mid + 1,r,x,y);
}

int query(int o,int l,int r,int p)
{
	if (l == r)
		return laz[o];
	push_down(o);
	int mid = (l + r) >> 1;
	if (mid >= p)
		return query(o << 1,l,mid,p);
	else
		return query(o << 1 | 1,mid + 1,r,p);
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k >> q;
	for (int i = 1;i <= n;i++)
		cin >> a >> b,update(1,1,200000,a,b);
	for (int i = 1;i <= 200000;i++)
		sum[i] = sum[i - 1] + (query(1,1,200000,i) >= k);
	for (int i = 1;i <= q;i++)
	{
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << endl;
	}
	return 0;
}