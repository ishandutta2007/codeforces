#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

typedef long long ll;

inline char gc()
{
	static char buf[262144],*p1 = buf,*p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,262144,stdin),p1 == p2) ? EOF : *p1++;
}

void read(int &v)
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

const int MAXN = 100005;
const int MAXP = 11;

int n,m,tot,MOD;
int v[MAXN];
int sum2[MAXP][MAXN << 2];
int laz2[MAXP][MAXN << 2];

ll a[MAXP];
ll b[MAXP];
ll c[MAXP];
ll table[MAXP][35];
ll sum1[MAXP][MAXN << 2];
ll laz1[MAXP][MAXN << 2];

inline ll power(ll a,ll b,ll p)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			(res *= a) %= p;
		(a *= a) %= p;
		b >>= 1;
		if (!res)
			return 0;
	}
	return res;
}

ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll r = exgcd(b,a % b,y,x);
    y -= a / b * x;
    return r;
}

inline ll inv(ll a,ll p)
{
	ll x,y;
	exgcd(a,p,x,y);
	return x % p;
}

inline void merge(ll &m1,ll &c1,ll m2,ll c2)
{
    ll g = __gcd(m1,m2),M = m1 / g * m2;
    c1 = inv(m1 / g,m2 / g) * ((c2 - c1) / g) % (m2 / g) * m1 + c1;
    m1 = M;
}

inline void pushup(int id,int o)
{
	sum1[id][o] = (sum1[id][o << 1] + sum1[id][o << 1 | 1]) % b[id];
}

inline void mdf1(int id,int o,ll v)
{
	(sum1[id][o] *= v) %= b[id];
	(laz1[id][o] *= v) %= b[id];
}

inline void mdf2(int id,int o,ll v)
{
	sum2[id][o] += v;
	if (v >= 0)
	{
		if (sum1[id][o] && v < c[id])
			(sum1[id][o] *= table[id][v]) %= b[id];
		else
			sum1[id][o] = 0;
	}
	else
	{
		if (sum2[id][o] < c[id])
			sum1[id][o] = laz1[id][o] * table[id][sum2[id][o]] % b[id];
		else
			sum1[id][o] = 0;
	}
	laz2[id][o] += v;
}

inline void pushdown(int id,int o)
{
	if (laz1[id][o] != 1)
	{
		mdf1(id,o << 1,laz1[id][o]);
		mdf1(id,o << 1 | 1,laz1[id][o]);
		laz1[id][o] = 1;
	}
	if (laz2[id][o])
	{
		mdf2(id,o << 1,laz2[id][o]);
		mdf2(id,o << 1 | 1,laz2[id][o]);
		laz2[id][o] = 0;
	}
}

void buildtree(int id,int o,int l,int r)
{
	laz1[id][o] = 1;
	if (l == r)
	{
		int V = v[l];
		sum1[id][o] = V;
		while (V % a[id] == 0)
		{
			sum2[id][o]++;
			V /= a[id];
		}
		laz1[id][o] = V % b[id];
		return;
	}
	int mid = (l + r) >> 1;
	buildtree(id,o << 1,l,mid);
	buildtree(id,o << 1 | 1,mid + 1,r);
	pushup(id,o);
}

void modify(int id,int o,int l,int r,int x,int y,ll v1,ll v2)
{
	if (l >= x && r <= y)
	{
		mdf1(id,o,v1);
		mdf2(id,o,v2);
		return;
	}
	pushdown(id,o);
	int mid = (l + r) >> 1;
	if (mid >= x)
		modify(id,o << 1,l,mid,x,y,v1,v2);
	if (mid + 1 <= y)
		modify(id,o << 1 | 1,mid + 1,r,x,y,v1,v2);
	pushup(id,o);
}

ll query(int id,int o,int l,int r,int x,int y)
{
	if (l >= x && r <= y)
		return sum1[id][o];
	pushdown(id,o);
	int mid = (l + r) >> 1;
	if (mid + 1 > y)
		return query(id,o << 1,l,mid,x,y);
	if (mid < x)
		return query(id,o << 1 | 1,mid + 1,r,x,y);
	return (query(id,o << 1,l,mid,x,y) + query(id,o << 1 | 1,mid + 1,r,x,y)) % b[id];
}

int main()
{
	read(n),read(MOD);
	for (int i = 2;i * i <= MOD;i++)
		if (MOD % i == 0)
		{
			a[++tot] = i;
			b[tot] = 1;
			while (MOD % i == 0)
			{
				c[tot]++;
				b[tot] *= i;
				MOD /= i;
			}
		}
	if (MOD != 1)
	{
		a[++tot] = MOD;
		b[tot] = MOD;
		c[tot] = 1;
	}
	for (int i = 1;i <= tot;i++)
	{
		table[i][0] = 1;
		for (int j = 1;j < c[i];j++)
			table[i][j] = table[i][j - 1] * a[i];
	}
	for (int i = 1;i <= n;i++)
		read(v[i]);
	for (int i = 1;i <= tot;i++)
		buildtree(i,1,1,n);
	read(m);
	int tp,l,r,v;
	while (m--)
	{
		read(tp);
		if (tp == 1)
		{
			read(l),read(r),read(v);
			for (int i = 1;i <= tot;i++)
			{
				int V = v,cnt = 0;
				while (V % a[i] == 0)
				{
					V /= a[i];
					cnt++;
				}
				modify(i,1,1,n,l,r,V,cnt);
			}
		}
		if (tp == 2)
		{
			read(l),read(v);
			for (int i = 1;i <= tot;i++)
			{
				int V = v,cnt = 0;
				while (V % a[i] == 0)
				{
					V /= a[i];
					cnt++;
				}
				modify(i,1,1,n,l,l,inv(V,b[i]),-cnt);
			}
		}
		if (tp == 3)
		{
			read(l),read(r);
			ll M = 1,C = 0;
			for (int i = 1;i <= tot;i++)
				merge(M,C,b[i],query(i,1,1,n,l,r));
			printf("%d\n",(int)((C + M) % M));
		}
	}
	return 0;
}