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

const int MAXN = 3005;
const int MOD = 998244353;

int n,m,ans;
int pw[MAXN];
int f[MAXN][MAXN];

char s[MAXN];
char t[MAXN];

int main()
{
	scanf("%s%s",s + 1,t + 1);
	n = strlen(s + 1);
	m = strlen(t + 1);
	pw[0] = 1;
	for (int i = 1;i <= n;i++)
		pw[i] = pw[i - 1] * 2 % MOD;
	for (int i = 1;i <= n;i++)
		if (i > m || t[i] == s[1])
		{
			f[i][i] = 2;
			if (i == 1 && i >= m)
				ans += 2;
		}
	for (int len = 2;len <= n;len++)
		for (int i = 1,j = len;j <= n;i++,j++)
		{
			if (i > m || t[i] == s[len])
				(f[i][j] += f[i + 1][j]) %= MOD;
			if (j > m || t[j] == s[len])
				(f[i][j] += f[i][j - 1]) %= MOD;
			if (i == 1 && j >= m)
				(ans += f[i][j]) %= MOD;
		}
	printf("%d\n",ans);
	return 0;
}