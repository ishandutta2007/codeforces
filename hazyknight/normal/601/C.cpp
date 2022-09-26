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
typedef long long ll;
typedef vector<db> Poly;

const int MAXN = 100005;
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
		return Complex(real * p.real - imag * p.imag,real * p.imag + imag * p.real);
	}
}a[MAXN << 2],b[MAXN << 2],wn[2][MAXN << 2];

int n,m,N;
int rev[MAXN << 2];

Poly v[MAXN];

void FFTinit(int l)
{
	N = 1;
	while (N < l)
		N <<= 1;
	int half = N >> 1;
	for (int i = 0;i < half;i++)
	{
		wn[0][half + i] = Complex(cos(PI * i / half),sin(PI * i / half));
		wn[1][half + i] = Complex(cos(PI * i / half),-sin(PI * i / half));
	}
	for (int i = half - 1;i >= 0;i--)
	{
		wn[0][i] = wn[0][i << 1];
		wn[1][i] = wn[1][i << 1];
	}
}

void init(int l)
{
	N = 1;
	while (N < l)
		N <<= 1;
	int half = N >> 1;
	for (int i = 1;i < N;i++)
		rev[i] = (rev[i >> 1] >> 1) + (i & 1) * half;
}

void FFT(Complex *v,int inv)
{
	for (int i = 0;i < N;i++)
		if (i < rev[i])
			swap(v[i],v[rev[i]]);
	for (int i = 1;i < N;i <<= 1)
		for (int j = 0;j < N;j += (i << 1))
		{
			Complex *l = v + j,*r = v + j + i,*w = wn[inv == -1] + i,A;
			for (int k = 0;k < i;k++,l++,r++,w++)
			{
				A = *w * *r;
				*r = *l - A;
				*l = *l + A;
			}
		}
	if (inv == -1)
	{
		Complex Inv(1.0 / N,0);
		for (int i = 0;i < N;i++)
			v[i] = v[i] * Inv;
	}
}

Poly MUL(Poly A,Poly B)
{
	int la = A.size(),lb = B.size();
	Poly c;
	c.resize(la + lb - 1);
	init(la + lb - 1);
	for (int i = 0;i < N;i++)
		a[i] = b[i] = Complex(0,0);
	for (int i = 0;i < A.size();i++)
		a[i] = Complex(A[i],0);
	for (int i = 0;i < B.size();i++)
		b[i] = Complex(B[i],0);
	FFT(a,1);
	FFT(b,1);
	for (int i = 0;i < N;i++)
		a[i] = a[i] * b[i];
	FFT(a,-1);
	for (int i = 0;i < la + lb - 1;i++)
		c[i] = a[i].real;
	return c;
}

Poly solve(int l,int r)
{
	if (l == r)
		return v[l];
	int mid = l + r >> 1;
	return MUL(solve(l,mid),solve(mid + 1,r));
}

int main()
{
	cin >> n >> m;
	FFTinit(n * m);
	int my = 0;
	for (int p,i = 1;i <= n;i++)
	{
		cin >> p;
		my += p;
		v[i].resize(m + 1);
		for (int j = 1;j <= m;j++)
			if (j != p)
				v[i][j] = 1.0 / (m - 1);
	}
	Poly res = solve(1,n);
	double P = 0;
	for (int i = n;i < my;i++)
		P += res[i];
	cout << fixed << setprecision(10) << 1 + P * (m - 1) << endl;
	return 0;
}