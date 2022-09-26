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

const int MAXN = 100005;

int n;

ll a[MAXN];

vector<pair<ll,ll> > v[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i = 2;i <= n;i += 2)
	{
		scanf("%I64d",&a[i]);
		for (int j = 1;j * j <= a[i];j++)
			if (a[i] % j == 0 && j * j != a[i] && ((a[i] / j) & 1) == (j & 1))
				v[i].push_back(make_pair((a[i] / j - j) / 2,(a[i] / j + j) / 2));
	}
	ll cur = 0;
	for (int i = 1;i < n;i += 2)
	{
		ll MIN = (1ll << 60) - 1,to = -1;
		for (int j = 0;j < v[i + 1].size();j++)
			if (v[i + 1][j].first > cur && v[i + 1][j].second < MIN)
			{
				MIN = v[i + 1][j].second;
				to = v[i + 1][j].first;
			}
		if (to == -1)
		{
			printf("No\n");
			return 0;
		}
		a[i] = to * to - cur * cur;
		cur = MIN;
	}
	printf("Yes\n");
	for (int i = 1;i <= n;i++)
		printf("%I64d ",a[i]);
	printf("\n");
	return 0;
}