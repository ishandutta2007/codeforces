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

const int MAXN = 105;
const int p = 998244353;
const int g = 3;

struct Matrix
{
	int r,c;
	int a[MAXN][MAXN];
	Matrix(int R = 0,int C = 0)
	{
		r = R;
		c = C;
		memset(a,0,sizeof(a));
	}
	Matrix operator * (const Matrix &t)const
	{
		Matrix res(r,t.c);
		for (int k = 1;k <= c;k++)
			for (int i = 1;i <= res.r;i++)
			{
				ll r = a[i][k];
				for (int j = 1;j <= res.c;j++)
					res.a[i][j] = (r * t.a[k][j] + res.a[i][j]) % (p - 1);
			}
		return res;
	}
}trans,st;

int k,n,a,b;

map<int,int> hs;

int gcd(int a,int b)
{
	return b ? gcd(b,a % b) : a;
}

void exgcd(int a,int b,int &x,int &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return;
	}
	exgcd(b,a % b,y,x);
	y -= a / b * x;
}

int power(int a,int b,int mod)
{
	int res = 1;
	while (b)
	{
		if (b & 1)
			res = (ll)res * a % mod;
		a = (ll)a * a % mod;
		b >>= 1;
	}
	return res;
}

Matrix power(Matrix a,int b)
{
	Matrix res = a;
	b--;
	while (b)
	{
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

int inverse(int a,int mod)
{
	int x,y;
	exgcd(a,mod,x,y);
	return (x % mod + mod) % mod;
}

int BSGS(int g,int b,int mod)
{
	int sz = (int)ceil(sqrt(mod) + 1),cur = 1;
	for (int i = 0;i < sz;i++)
	{
		if (cur == b)
			return i;
		hs[cur] = i + 1;
		cur = (ll)cur * g % mod;
	}
	int base = inverse(cur,mod);
	cur = (ll)base * b % mod;
	for (int i = sz;i <= mod - 1;i += sz)
	{
		int j = hs[cur] - 1;
		if (j != -1)
			return i + j;
		cur = (ll)cur * base % mod;
	}
	return -1;
}

int main()
{
	cin >> k;
	trans = Matrix(k,k);
	st = Matrix(1,k);
	for (int i = 1;i <= k;i++)
		cin >> trans.a[i][1];
	for (int i = 2;i <= k;i++)
		trans.a[i - 1][i] = 1;
	st.a[1][1] = 1;
	cin >> n >> b;
	st = st * power(trans,n - k);
	a = st.a[1][1];
	int indb = BSGS(g,b,p),mod = p - 1,d = gcd(a,mod);
	if (indb % d != 0)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << power(g,(ll)indb / d * inverse(a / d,mod / d) % (mod / d),p) << endl;
	return 0;
}