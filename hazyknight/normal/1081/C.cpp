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
#include <iomanip>
#include <assert.h>

using namespace std;

typedef long long ll;

const int MAXN = 2005;
const ll MOD = 998244353;

int n,m,k;

ll f[MAXN][MAXN];

int main()
{
	cin >> n >> m >> k;
	f[1][0] = m;
	for (int i = 1;i < n;i++)
		for (int j = 0;j <= k;j++)
			if (f[i][j])
			{
				(f[i + 1][j] += f[i][j]) %= MOD	;
				(f[i + 1][j + 1] += f[i][j] * (m - 1)) %= MOD;
			}
	cout << f[n][k] << endl;
	return 0;
}