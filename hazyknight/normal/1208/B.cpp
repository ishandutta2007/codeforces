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

const int MAXN = 2005;

int n,id,tot,ans;
int a[MAXN];
int cnt[MAXN];

map<int,int> match;

void add(int p,int v)
{
	tot -= (cnt[p] > 1);
	cnt[p] += v;
	tot += (cnt[p] > 1);
}

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (!match[a[i]])
			match[a[i]] = ++id;
		a[i] = match[a[i]];
	}
	ans = n;
	for (int i = 1;i <= n;i++)
	{
		memset(cnt,0,sizeof(cnt));
		for (int j = 1;j <= n;j++)
			add(a[j],1);
		if (!tot)
			ans = 0;
		for (int j = i;j <= n;j++)
		{
			add(a[j],-1);
			if (!tot)
				ans = min(ans,j - i + 1);
		}
	}
	cout << ans << endl;
	return 0;
}