#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <bitset>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

const int MAXN = 15;
const int MAXT = 235;
const int MOD = 1000000007;

int n,T,ans;
int len[MAXN];
int tp[MAXN];
int f[1 << MAXN][3];

int main()
{
	cin >> n >> T;
	for (int i = 0;i < n;i++)
	{
		cin >> len[i] >> tp[i];
		tp[i]--;
		f[1 << i][tp[i]] = 1;
	}
	for (int i = 1;i < (1 << n);i++)
		for (int j = 0;j < 3;j++)
			if (f[i][j])
			{
				int sum = 0;
				for (int k = 0;k < n;k++)
					if (i >> k & 1)
						sum += len[k];
				if (sum == T)
				{
					(ans += f[i][j]) %= MOD;
					continue;
				}
				for (int k = 0;k < n;k++)
					if (sum + len[k] <= T && (~i >> k & 1) && tp[k] != j)
						(f[i | (1 << k)][tp[k]] += f[i][j]) %= MOD;
			}
	cout << ans << endl;
	return 0;
}