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

const int MAXN = 100005;

int n,p,l,r;
int fac[MAXN];
int inv[MAXN];
int cnt[MAXN];

int power(int a,int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1)
			res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
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

int getinv(int a,int p)
{
	int x,y;
	exgcd(a,p,x,y);
	if (x < 0)
		x += p;
	return x;
}

void init(int p,int p1)
{
	fac[0] = 1;
	cnt[0] = 0;
	for (int i = 1;i <= n;i++)
	{
		int I = i;
		cnt[i] = cnt[i - 1];
		while (I % p1 == 0)
		{
			I /= p1;
			cnt[i]++;
		}
		fac[i] = (ll)fac[i - 1] * I % p;
	}
	inv[n] = getinv(fac[n],p);
	for (int i = n;i >= 1;i--)
	{
		int I = i;
		while (I % p1 == 0)
			I /= p1;
		inv[i - 1] = (ll)inv[i] * I % p;
	}
}

int C(int x,int y,int p,int p1,int c1)
{
	if (x < y || y < 0 || cnt[x] - cnt[y] - cnt[x - y] >= c1)
		return 0;
	return (ll)fac[x] * inv[y] % p * inv[x - y] % p * power(p1,cnt[x] - cnt[y] - cnt[x - y]) % p;
}

int solve(int p,int p1,int c1)
{
	init(p,p1);
	int res = 0;
	for (int i = l;i <= n;i++)
	{
		int L = (l + i + 1 ) / 2,R = min(i,(r + i) / 2);
		if (L <= R)
			res = (res + (ll)C(n,i,p,p1,c1) * ((ll)C(i,L,p,p1,c1) - C(i,R + 1,p,p1,c1) + p) % p) % p;
	}
	return res;
}

int main()
{
	cin >> n >> p >> l >> r;
	int M = 1,C = 0;
	for (int i = 2;i * i <= p;i++)
		if (p % i == 0)
		{
			int cnt = 0,m1 = 1;
			while (p % i == 0)
			{
				p /= i;
				cnt++;
				m1 *= i;
			}
			int c1 = solve(m1,i,cnt);
			C = (ll)getinv(m1,M) * (C - c1) % M * m1 + c1;
			M = M * m1;
			if (C < 0)
				C += M;
		}
	if (p != 1)
	{
		int c1 = solve(p,p,1);
		C = (ll)getinv(p,M) * (C - c1) % M * p + c1;
		M = M * p;
		if (C < 0)
			C += M;
	}
	cout << C << endl;
	return 0;
}