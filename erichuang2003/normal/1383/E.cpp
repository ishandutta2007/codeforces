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
 
const int MAXN = 1000005;
const int MOD = 1000000007;
 
int T,n,ans;
int f[MAXN];
int cnt[MAXN];
int nxt[MAXN];
int to[MAXN][2];
 
char s[MAXN];
 
int main()
{
	scanf("%s",s + 1);
	n = strlen(s + 1);
	f[0] = 1;
	for (int i = 1;i <= n;i++)
	{
		if (s[i] == '0')
			cnt[i] = cnt[i - 1] + 1;
		else
			cnt[i] = 0;
	}
	to[n][0] = to[n][1] = 1e9;
	for (int i = 0;i <= n;i++)
		nxt[i] = 1e9;
	nxt[cnt[n]] = n;
	for (int i = n - 1;i >= 0;i--)
	{
		to[i][0] = nxt[cnt[i] + 1];
		to[i][1] = nxt[0];
		nxt[cnt[i]] = i;
		if (i == cnt[i] && to[i][0] != i + 1)
			to[i][0] = 1e9;
	}
	for (int i = 0;i < n;i++)
	{
		if (to[i][0] != 1e9)
			(f[to[i][0]] += f[i]) %= MOD;
		if (to[i][1] != 1e9)
			(f[to[i][1]] += f[i]) %= MOD;
	}
	for (int i = 1;i <= n;i++)
		if (cnt[i] <= cnt[n])
			(ans += f[i]) %= MOD;
	if (cnt[n] != n)
	{
		for (int i = 1;i <= n;i++)
			if (cnt[i] == i && cnt[i] <= cnt[n])
				ans--;
	}
	cout << (ans + MOD) % MOD << endl;
	return 0;
}