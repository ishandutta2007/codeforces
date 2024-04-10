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

typedef long long ll;

const int MAXN = 7005;

int n;
int b[MAXN];
int deg[MAXN];

ll ans;
ll a[MAXN];

bool mark[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&b[i]);
		ans += b[i];
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			if (i != j)
				deg[i] += ((a[i] & a[j]) != a[i]);
	int cnt = n;
	while (1)
	{
		int pos = 0;
		for (int i = 1;i <= n;i++)
			if (!mark[i] && deg[i] == cnt - 1)
			{
				pos = i;
				break;
			}
		if (!pos)
			break;
		mark[pos] = 1;
		ans -= b[pos];
		cnt--;
		for (int i = 1;i <= n;i++)
			if (!mark[i])
				deg[i] -= ((a[i] & a[pos]) != a[i]);
	}
	printf("%lld\n",ans);
	return 0;
}