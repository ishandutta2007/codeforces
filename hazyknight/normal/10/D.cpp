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

const int MAXN = 505;

int n,m,tot,I,J,ans;
int a[MAXN];
int b[MAXN];
int sel[MAXN];
int nxta[MAXN << 1];
int nxtb[MAXN << 1];
int val[MAXN << 1];
int rematch[MAXN << 1];
int f[MAXN][MAXN];

map<int,int> match;
pair<int,int> pre[MAXN][MAXN];
 
int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		val[++tot] = a[i];
	}
	cin >> m;
	for (int i = 1;i <= m;i++)
	{
		cin >> b[i];
		val[++tot] = b[i];
	}
	sort(val + 1,val + tot + 1);
	tot = unique(val + 1,val + tot + 1) - val - 1;
	for (int i = 1;i <= tot;i++)
		rematch[match[val[i]] = i] = val[i];
	for (int i = 1;i <= n;i++)
		a[i] = match[a[i]];
	for (int i = 1;i <= m;i++)
		b[i] = match[b[i]];
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			f[i][j] = (a[i] == b[j]);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (f[i][j])
			{
				memset(nxta,0,sizeof(nxta));
				memset(nxtb,0,sizeof(nxtb));
				for (int k = i + 1;k <= n;k++)
					if (!nxta[a[k]])
						nxta[a[k]] = k;
				for (int k = j + 1;k <= m;k++)
					if (!nxtb[b[k]])
						nxtb[b[k]] = k;
				for (int k = a[i] + 1;k <= tot;k++)
					if (nxta[k] && nxtb[k] && f[nxta[k]][nxtb[k]] < f[i][j] + 1)
					{
						f[nxta[k]][nxtb[k]] = f[i][j] + 1;
						pre[nxta[k]][nxtb[k]] = make_pair(i,j);
					}
			}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (f[i][j] > ans)
			{
				ans = f[i][j];
				I = i;
				J = j;
			}
	while (f[I][J] >= 1)
	{
		sel[f[I][J]] = a[I];
		pair<int,int> nxt = pre[I][J];
		I = nxt.first;
		J = nxt.second;
	}
	cout << ans << endl;
	for (int i = 1;i <= ans;i++)
		cout << rematch[sel[i]] << ' ';
	cout << endl;
	return 0;
}