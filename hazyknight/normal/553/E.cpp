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

typedef double db;

inline char gc()
{
	static char buf[524288],*p1 = buf,*p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,524288,stdin),p1 == p2) ? EOF : *p1++;
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

const int MAXN = 51;
const int MAXM = 101;
const int MAXT = 65605;
const db PI = acos(-1);

struct Complex
{
	db real,imag;
	
	Complex (db R = 0,db I = 0)
	{
		real = R;
		imag = I;
	}
	
	Complex operator + (const Complex &p)const
	{
		return Complex(real + p.real,imag + p.imag);
	}
	
	Complex operator - (const Complex &p)const
	{
		return Complex(real - p.real,imag - p.imag);
	}
	
	Complex operator * (const Complex &p)const
	{
		return Complex(real * p.real - imag * p.imag,real * p.imag + p.real * imag);
	}
	
	Complex operator * (const db &p)const
	{
		return Complex(real * p,imag * p);
	}
}wn[2][MAXT],a[MAXT],b[MAXT],p[MAXM][MAXT];

struct Edge
{
	int to;
	int w;
	int id;
	int nxt;
}edge[MAXM];

int n,m,t,x,id,N;
int first[MAXN];
int rev[MAXT];

db f[MAXN][MAXT];

bool inqueue[MAXN];

queue<int> Q;

void addE(int u,int v,int w,int ID)
{
	edge[++id] = (Edge){v,w,ID,first[u]};
	first[u] = id;
}

void init(int l)
{
	N = 1;
	while (N < l)
		N <<= 1;
	for (int i = 1;i < N;i++)
		rev[i] = (rev[i >> 1] >> 1) + (i & 1) * (N >> 1);
	int half = N >> 1;
	for (int i = 0;i < half;i++)
	{
		wn[0][i + half] = Complex(cos(PI * i / half),sin(PI * i / half));
		wn[1][i + half] = Complex(cos(PI * i / half),-sin(PI * i / half));
	}
	for (int i = half - 1;i >= 0;i--)
	{
		wn[0][i] = wn[0][i << 1];
		wn[1][i] = wn[1][i << 1];
	}
}

void FFT(Complex *a,bool inv)
{
	for (int i = 0;i < N;i++)
		if (i < rev[i])
			swap(a[i],a[rev[i]]);
	for (int i = 1;i < N;i <<= 1)
		for (int j = 0;j < N;j += i << 1)
		{
			Complex *l = a + j,*r = a + j + i,*w = wn[inv] + i,A;
			for (int k = 0;k < i;k++,l++,r++,w++)
			{
				A = *r * *w;
				*r = *l - A;
				*l = *l + A;
			}
		}
	if (inv)
	{
		db Inv = 1.0 / N;
		for (int i = 0;i < N;i++)
			a[i] = a[i] * Inv;
	}
}

bool update(int u,int cur,int w,int v)
{
	for (int i = 0;i < N;i++)
		b[i] = a[i] * p[cur][i];
	FFT(b,1);
	bool flag = 0;
	for (int i = 0;i <= t + 1;i++)
		if (f[v][i] > b[t + i].real + w)
		{
			flag = 1;
			f[v][i] = b[t + i].real + w;
		}
	return flag;
}

void SPFA()
{
	for (int i = 1;i < n;i++)
		for (int j = 0;j <= t + 1;j++)
			f[i][j] = 1e9;
	f[n][t + 1] = x;
	Q.push(n);
	inqueue[n] = 1;
	while (!Q.empty())
	{
		int u = Q.front();
		inqueue[u] = 0;
		for (int i = 0;i < N;i++)
		{
			if (i <= t)
				a[i] = Complex(f[u][i],0);
			else
				a[i] = Complex(f[u][t + 1],0);
		}
		FFT(a,0);
		Q.pop();
		for (int i = first[u];i;i = edge[i].nxt)
			if (update(u,edge[i].id,edge[i].w,edge[i].to) && !inqueue[edge[i].to])
			{
				Q.push(edge[i].to);
				inqueue[edge[i].to] = 1;
			}
	}
}

int main()
{
	read(n),read(m),read(t),read(x);
	init(t << 1 | 1);
	for (int u,v,w,i = 1;i <= m;i++)
	{
		read(u),read(v),read(w);
		addE(v,u,w,i);
		for (int P,j = 1;j <= t;j++)
		{
			read(P);
			p[i][t - j] = Complex(P / 100000.0,0);
		}
		FFT(p[i],0);
	}
	SPFA();
	printf("%.7lf\n",f[1][0]);
	return 0;
}