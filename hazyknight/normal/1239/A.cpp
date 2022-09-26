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

const int MAXN = 100005;
const int MOD = 1000000007;

int n,m;
int f[MAXN];
int g[MAXN];

int main()
{
	cin >> n >> m;
	if (n > m)
		swap(n,m);
	f[1] = 2;
	f[2] = 4;
	for (int i = 3;i <= m;i++)
		f[i] = (f[i - 1] + f[i - 2]) % MOD;
	g[1] = f[m];
	g[2] = f[m] + 2;
	for (int i = 3;i <= n;i++)
		g[i] = (g[i - 1] + f[i - 2]) % MOD;
	cout << g[n] << endl;
	return 0;
}