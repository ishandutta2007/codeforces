#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int MAXN = 405;
const ll MOD = 1000000007;

int n;

ll f[MAXN][MAXN];

int main()
{
	cin >> n;
	f[1][0] = f[1][1] = 1;
	for (int i = 2;i <= n;i++)
		for (int j = 0;j <= n - i + 1;j++)
		{
			for (int k = 0;k <= j;k++)
				(f[i][j] += f[i - 1][k] * f[i - 1][j - k]) %= MOD;
			for (int k = 0;k < j;k++)
				(f[i][j] += f[i - 1][k] * f[i - 1][j - 1 - k]) %= MOD;
			for (int k = 0;k <= j;k++)
				(f[i][j] += f[i - 1][k] * f[i - 1][j - k] % MOD * k * 4) %= MOD;
			for (int k = 0;k <= j + 1;k++)
				(f[i][j] += f[i - 1][k] * f[i - 1][j + 1 - k] % MOD * j * (j + 1)) %= MOD;
		}
	cout << f[n][1] << endl;
	return 0;
}