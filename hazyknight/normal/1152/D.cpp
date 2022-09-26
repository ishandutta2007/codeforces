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

const int MAXN = 1005;
const int MOD = 1000000007;

int n;
int f[MAXN][MAXN][2];

int main()
{
	cin >> n;
	for (int i = 0;i <= n;i++)
	{
		f[i][i + 1][0] = -1e9;
		f[n + 1][i][0] = -1e9;
	}
	f[n][n][0] = f[n][n][1] = 0;
	for (int i = n;i >= 0;i--)
		for (int j = i - (j == n);j >= 0;j--)
		{
			f[i][j][0] = (f[i][j + 1][1] + f[i + 1][j][1]) % MOD;
			f[i][j][1] = (f[i][j + 1][0] + f[i + 1][j][1] + 1) % MOD;
			f[i][j][1] = (f[i][j][0] + ((i + j) & 1)) % MOD;
		}
	cout << f[0][0][1] << endl;
	return 0;
}