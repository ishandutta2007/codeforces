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
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

const int MAXN = 200005;
const ll MOD = 1000000007;

int n,l,r;
int c[3];

ll f[MAXN][3];

ll calc(int v)
{
	int L = l,R = r;
	while ((L + 3) % 3 != v)
		L++;
	while ((R + 3) % 3 != v)
		R--;
	return (R - L) / 3 + 1;
}

int main()
{
	cin >> n >> l >> r;
	c[0] = calc(0);
	c[1] = calc(1);
	c[2] = calc(2);
	f[0][0] = 1;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j < 3;j++)
			for (int k = 0;k < 3;k++)
				(f[i][j] += f[i - 1][(j - k + 3) % 3] * c[k]) %= MOD;
	cout << f[n][0] << endl;
	return 0;
}