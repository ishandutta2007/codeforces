#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

const int MAXN = 105;
const int MAXV = 10005;

int n;
int cnt[MAXN];
int f[MAXN][MAXV];

void add(int &a,int b)
{
	a += b;
	if (a > 2)
		a = 2;
}

int main()
{
	cin >> n;
	for (int a,i = 1;i <= n;i++)
		cin >> a,cnt[a]++;
	for (int i = 1;i <= 100;i++)
		for (int j = i + 1;j <= 100;j++)
			if (cnt[i] + cnt[j] == n)
			{
				cout << n << endl;
				return 0;
			}
	f[0][0] = 1;
	for (int i = 0;i < 100;i++)
		for (int j = i;j >= 0;j--)
			for (int k = 10000;k >= 0;k--)
				if (f[j][k])
					for (int l = cnt[i + 1];l >= 1;l--)
						add(f[j + l][k + l * (i + 1)],f[j][k]);
	for (int i = 100;i >= 0;i--)
		for (int j = 1;j <= 100;j++)
			if (cnt[j] >= i && f[i][i * j] == 1) 
			{
				cout << i << endl;
				return 0;
			}
	return 0;
}