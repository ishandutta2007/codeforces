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

const int MAXN = 300005;

inline char gc()
{
	static char buf[1048576],*p1 = buf,*p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1048576,stdin),p1 == p2 ) ? EOF : *p1++;
}

inline void read(int &v)
{
	v = 0;
	char c = gc();
	while (c < '0' || c > '9')
		c = gc();
	while (c >= '0' && c <= '9')
	{
		v = v * 10 + c - '0';
		c = gc();
	}
}

struct Query
{
	int tp,opt,x,y,z,id,ans,v1,v2,val;
	
	bool operator < (const Query &p)const
	{
		return id < p.id;
	}
}q[MAXN],tmp[MAXN];

int Case,n,m,TP;
int sum[MAXN << 1];

inline void modify(int p,int v)
{
	while (p <= 2 * n)
	{
		sum[p] += v;
		p += p & -p;
	}
}

inline int query(int p)
{
	int res = 0;
	while (p >= 1)
	{
		res += sum[p];
		p -= p & -p;
	}
	return res;
}

void divide(int l,int r)
{
	if (l == r)
		return;
	int mid = l + r >> 1;
	divide(l,mid);
	divide(mid + 1,r);
	int p1 = l,p2 = mid + 1,p = l;
	while (p1 <= mid && p2 <= r)
	{
		if (q[p1].v1 < q[p2].v1 || (q[p1].v1 == q[p2].v1 && q[p1].tp < q[p2].tp))
		{
			if (q[p1].tp == 1 && q[p1].opt == TP)
				modify(q[p1].v2,q[p1].val);
			tmp[p++] = q[p1++];
		}
		else
		{
			if (q[p2].tp == 2)
				q[p2].ans += query(q[p2].v2);
			tmp[p++] = q[p2++];
		}
	}
	while (p1 <= mid)
	{
		if (q[p1].tp == 1 && q[p1].opt == TP)
			modify(q[p1].v2,q[p1].val);
		tmp[p++] = q[p1++];
	}
	while (p2 <= r)
	{
		if (q[p2].tp == 2)
			q[p2].ans += query(q[p2].v2);
		tmp[p++] = q[p2++];
	}
	for (int i = l;i <= mid;i++)	
		if (q[i].tp == 1 && q[i].opt == TP)
			modify(q[i].v2,-q[i].val);
	for (int i = l;i <= r;i++)
		q[i] = tmp[i];
}

void solve()
{
	for (int i = 1;i <= m;i++)
	{
		q[i].v1 = q[i].y;
		q[i].v2 = 2 * n - q[i].x - q[i].y - q[i].z + 1;
		q[i].val = 1;
	}
	sort(q + 1,q + m + 1);
	divide(1,m);
	for (int i = 1;i <= m;i++)
	{
		q[i].v1 = q[i].x;
		q[i].v2 = 2 * n - q[i].x - q[i].y - q[i].z + 1;
		q[i].val = 1;
	}
	sort(q + 1,q + m + 1);
	divide(1,m);
	for (int i = 1;i <= m;i++)
	{
		q[i].v1 = n - q[i].x + 1 + (q[i].tp == 1);
		q[i].v2 = n - q[i].y + 1 + (q[i].tp == 1);
		q[i].val = 1;
	}
	sort(q + 1,q + m + 1);
	divide(1,m);
	for (int i = 1;i <= m;i++)
	{
		q[i].v1 = 2 * n - q[i].x - q[i].y - q[i].z + 1;
		q[i].v2 = 1;
		q[i].val = -1;
	}
	sort(q + 1,q + m + 1);
	divide(1,m);
}

int main()
{
	read(n),read(m);
	for (int i = 1;i <= m;i++)
	{
		read(q[i].tp);
		if (q[i].tp == 1)
			read(q[i].opt),read(q[i].x),read(q[i].y),read(q[i].z);
		else
			read(q[i].x),read(q[i].y);
		q[i].id = i;
	}
	TP = 1;
	solve();
	for (int i = 1;i <= m;i++)
	{
		int X = n + 1 - q[i].y,Y = q[i].x;
		q[i].x = X;
		q[i].y = Y;
	}
	TP = 2;
	solve();
	for (int i = 1;i <= m;i++)
	{
		int X = n + 1 - q[i].y,Y = q[i].x;
		q[i].x = X;
		q[i].y = Y;
	}
	TP = 4;
	solve();
	for (int i = 1;i <= m;i++)
	{
		int X = n + 1 - q[i].y,Y = q[i].x;
		q[i].x = X;
		q[i].y = Y;
	}
	TP = 3;
	solve();
	sort(q + 1,q + m + 1);
	for (int i = 1;i <= m;i++)
		if (q[i].tp == 2)
			printf("%d\n",q[i].ans);
	return 0;
}