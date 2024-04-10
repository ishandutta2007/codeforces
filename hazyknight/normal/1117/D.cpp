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

const int MAXM = 105;
const ll MOD = 1000000007;

struct Matrix
{
	int r,c;
	ll a[MAXM][MAXM];
	
	Matrix(int R = 0,int C = 0)
	{
		r = R;
		c = C;
		for (int i = 1;i <= r;i++)
			for (int j = 1;j <= c;j++)
				a[i][j] = 0;
	}
	
	Matrix operator * (const Matrix &p)
	{
		Matrix res(r,p.c);
		for (int i = 1;i <= res.r;i++)
			for (int j = 1;j <= res.c;j++)
				for (int k = 1;k <= c;k++)
					(res.a[i][j] += a[i][k] * p.a[k][j]) %= MOD;
		return res;
	}
}st,trans,unit;

ll n,m;

Matrix power(Matrix a,ll b)
{
	Matrix res = unit;
	while (b)
	{
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output2.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	if (n < m)
	{
		cout << 1 << endl;
		return 0;
	}
	st = Matrix(1,m);
	trans = unit = Matrix(m,m);
	for (int i = 1;i <= m;i++)
		unit.a[i][i] = 1;
	trans.a[1][1] = trans.a[m][1] = 1;
	for (int i = 2;i <= m;i++)
		trans.a[i - 1][i] = 1;
	for (int i = 1;i <= m;i++)
		st.a[1][i] = 1;
	st = st * power(trans,n - m + 1);
	cout << st.a[1][1] << endl;
	return 0;
}