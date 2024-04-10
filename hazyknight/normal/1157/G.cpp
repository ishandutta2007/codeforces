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

const int MAXN = 205;

int n,m;
int r[MAXN];
int c[MAXN];
int a[MAXN][MAXN];
int b[MAXN][MAXN];

bool ok()
{
	int lst = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
		{
			if (b[i][j] < lst)
				return 0;
			lst = b[i][j];
		}
	return 1;
}

void print()
{
	for (int j = 1;j <= m;j++)
		c[j] = a[1][j] ^ b[1][j];
	for (int j = 2;j <= n;j++)
		r[j] = a[j][1] ^ c[1] ^ b[j][1];
	cout << "YES" << endl;
	for (int j = 1;j <= n;j++)
		cout << r[j];
	cout << endl;
	for (int j = 1;j <= m;j++)
		cout << c[j];
	cout << endl;
	exit(0);
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			cin >> a[i][j];
	for (int i = 0;i <= m;i++)
	{
		for (int j = 1;j <= m;j++)
			b[1][j] = (j > i);
		for (int j = 2;j <= n;j++)
			b[j][1] = 1;
		for (int j = 2;ok && j <= n;j++)
			for (int k = 2;ok && k <= m;k++)
				b[j][k] = a[j][k] ^ b[1][k] ^ a[1][k] ^ b[1][1] ^ a[1][1] ^ b[j][1] ^ a[j][1];
		if (ok())
			print();
	}
	for (int i = 0;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
			b[j][1] = (j > i);
		for (int j = 2;j <= n;j++)
			b[1][j] = 0;
		for (int j = 2;ok && j <= n;j++)
			for (int k = 2;ok && k <= m;k++)
				b[j][k] = a[j][k] ^ b[1][k] ^ a[1][k] ^ b[1][1] ^ a[1][1] ^ b[j][1] ^ a[j][1];
		if (ok())
			print();
	}
	cout << "NO" << endl;
	return 0;
}