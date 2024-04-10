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

typedef long long ll;

const int MAXN = 200005;

int n,m,N;
int match[MAXN];

ll sum[MAXN];

bool rev;

pair<int,int> a[MAXN];
pair<int,int> b[MAXN];

priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > C,D;

void add(int p,int v)
{
	while (p <= n)
	{
		sum[p] += v;
		p += p & -p;
	}
}

ll query(int p)
{
	ll res = 0;
	while (p >= 1)
	{
		res += sum[p];
		p -= p & -p;
	}
	return res;
}

void modify(int l,int r,int v)
{
	if (rev)
	{
		l = -l;
		r = -r;
		swap(l,r);
	}
	l = (l % n + n) % n;
	r = (r % n + n) % n;
	l++,r++;
	if (l <= r)
	{
		add(l,v);
		if (r < n)
			add(r + 1,-v);
	}
	else
	{
		add(1,v);
		add(r + 1,-v);
		add(l,v);
	}
}

void solve()
{
	//b <= a
	for (int i = 1,l = 1,r = 0;i <= n;i++)
	{
		while (r < n && b[r + 1].first <= a[i].first)
			r++;
		while (l <= r && a[i].first - b[l].first >= m - a[i].first + b[l].first)
			l++;
		if (1 <= r)
			modify(1 - i,r - i,m - a[i].first);
		if (l <= r)
			modify(l - i,r - i,2 * a[i].first - m);
	}
	//b > a
	for (int i = n,l = n + 1,r = n;i >= 1;i--)
	{
		while (l > 1 && b[l - 1].first > a[i].first)
			l--;
		while (l <= r && b[r].first - a[i].first >= m - b[r].first + a[i].first)
			r--;
		if (l <= n)
			modify(l - i,n - i,a[i].first);
		if (l <= r)
			modify(l - i,r - i,-2 * a[i].first);
	}
}

int main()
{
	scanf("%d%d",&m,&n);
	N = n;
	for (int v,i = 1;i <= n;i++)
	{
		scanf("%d",&v);
		C.push(make_pair(v,i));
	}
	for (int v,i = 1;i <= n;i++)
	{
		scanf("%d",&v);
		D.push(make_pair(v,i));
	}
	int ta = 0,tb = 0;
	while (!C.empty() && !D.empty())
	{
		if (C.top().first == D.top().first)
		{
			match[C.top().second] = D.top().second;
			C.pop();
			D.pop();
			continue;
		}
		if (C.top().first < D.top().first)
		{
			a[++ta] = C.top();
			C.pop();
		}
		else
		{
			b[++tb] = D.top();
			D.pop();
		}
	}
	while (!C.empty())
	{
		a[++ta] = C.top();
		C.pop();
	}
	while (!D.empty())
	{
		b[++tb] = D.top();
		D.pop();
	}
	n = ta;
	swap(a,b);
	rev = 1;
	solve();
	swap(a,b);
	rev = 0;
	solve();
	ll MIN = 1e18;
	int pos = 0;
	for (int i = 1;i <= n;i++)
		if (query(i) < MIN)
		{
			MIN = query(i);
			pos = i;
		}
	if (!n)
		MIN = 0;
	printf("%lld\n",MIN);
	for (int i = 1;i <= n;i++)
		match[a[i].second] = b[(i + pos - 2) % n + 1].second;
	for (int i = 1;i <= N;i++)
		printf("%d ",match[i]);
	printf("\n");
	return 0;
}