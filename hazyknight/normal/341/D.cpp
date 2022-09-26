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

const int MAXN = 1005;
const int MAXM = 400005;

struct Opr
{
	int tp,r,c,id;
	ll v;
}opr[MAXM],a[MAXM];

int n,m,tot;

ll sum[MAXN];
ll ans[MAXM];

bool isq[MAXM];

vector<int> M[MAXN];
vector<int> Q[MAXN];

void modify(int p,ll v)
{
	while (p <= n)
	{
		sum[p] ^= v;
		p += p & -p;
	}
}

ll query(int p)
{
	ll res = 0;
	while (p >= 1)
	{
		res ^= sum[p];
		p -= p & -p;
	}
	return res;
}

void addq(int tp,int r,int c,ll v,int id)
{
	if (!r || !c)
		return;
	opr[++tot] = (Opr){tp,r,c,id,v};
}

bool cmpdn(const Opr &a,const Opr &b)
{
	return a.r == b.r ? a.tp > b.tp : a.r < b.r;
}

void solve(int l,int r)
{
	if (l == r)
		return;
	int mid = l + r >> 1,p = 0;
	for (int i = l;i <= mid;i++)
		if (opr[i].tp == 2)
			a[++p] = opr[i];
	for (int i = mid + 1;i <= r;i++)
		if (opr[i].tp == 1)
			a[++p] = opr[i];
	if (p <= 1000)
		sort(a + 1,a + p + 1,cmpdn);
	else
	{
		p = 0;
		for (int i = 1;i <= 1000;i++)
		{
			M[i].clear();
			Q[i].clear();
		}
		for (int i = l;i <= mid;i++)
			if (opr[i].tp == 2)
				M[opr[i].r].push_back(i);
		for (int i = mid + 1;i <= r;i++)
			if (opr[i].tp == 1)
				Q[opr[i].r].push_back(i);
		for (int i = 1;i <= n;i++)
		{
			for (int j = 0;j < M[i].size();j++)
				a[++p] = opr[M[i][j]];
			for (int j = 0;j < Q[i].size();j++)
				a[++p] = opr[Q[i][j]];
		}
	}
	for (int i = 1;i <= p;i++)
	{
		if (a[i].tp == 1)
			ans[a[i].id] ^= query(a[i].c);
		else if ((a[i].r & 1) && (a[i].c & 1))
			modify(a[i].c,a[i].v);
	}
	if (p <= 50)
	{
		for (int i = 1;i <= p;i++)
			if (a[i].tp == 2 && (a[i].r & 1) && (a[i].c & 1))
				modify(a[i].c,a[i].v);
	}
	else
		memset(sum,0,sizeof(sum));
	for (int i = 1;i <= p;i++)
	{
		if (a[i].tp == 1)
		{
			if (a[i].c & 1)
				ans[a[i].id] ^= query(n - a[i].c);
		}
		else if (a[i].r & 1)
			modify(n - a[i].c + 1,a[i].v);
	}
	if (p <= 50)
	{
		for (int i = 1;i <= p;i++)
			if (a[i].tp == 2 && (a[i].r & 1))
				modify(n - a[i].c + 1,a[i].v);
	}
	else
		memset(sum,0,sizeof(sum));
	reverse(a + 1,a + p + 1);
	for (int i = 1;i <= p;i++)
	{
		if (a[i].tp == 2)
			modify(n - a[i].c + 1,a[i].v);
		else if ((a[i].r & 1) && (a[i].c & 1))
			ans[a[i].id] ^= query(n - a[i].c);
	}
	if (p <= 50)
	{
		for (int i = 1;i <= p;i++)
			if (a[i].tp == 2)
				modify(n - a[i].c + 1,a[i].v);
	}
	else
		memset(sum,0,sizeof(sum));
	for (int i = 1;i <= p;i++)
	{
		if (a[i].tp == 1)
		{
			if (a[i].r & 1)
				ans[a[i].id] ^= query(a[i].c);
		}
		else if (a[i].c & 1)
			modify(a[i].c,a[i].v);
	}
	if (p <= 50)
	{
		for (int i = 1;i <= p;i++)
			if (a[i].tp == 2 && (a[i].c & 1))
				modify(a[i].c,a[i].v);
	}
	else
		memset(sum,0,sizeof(sum));
	solve(l,mid);
	solve(mid + 1,r);
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int tp,r0,r1,c0,c1,i = 1;i <= m;i++)
	{
		ll v;
		scanf("%d%d%d%d%d",&tp,&r0,&c0,&r1,&c1);
		if (tp == 2)
			scanf("%lld",&v);
		addq(tp,r1,c1,v,i);
		addq(tp,r0 - 1,c1,v,i);
		addq(tp,r1,c0 - 1,v,i);
		addq(tp,r0 - 1,c0 - 1,v,i);
		if (tp == 1)
			isq[i] = 1;
	}
	solve(1,tot);
	for (int i = 1;i <= m;i++)
		if (isq[i])
			printf("%lld\n",ans[i]);
	return 0;
}