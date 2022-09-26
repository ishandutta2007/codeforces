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

int n,tot;
int sum[1000005];

long long ans;

bool ok[MAXN];

vector<int> a[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		int l;
		scanf("%d",&l);
		a[i].resize(l);
		for (int j = 0;j < l;j++)
		{
			scanf("%d",&a[i][j]);
			if (j - 1 >= 0 && a[i][j] > a[i][j - 1])
				ok[i] = 1;
		}
		if (ok[i])
		{
			ans += n;
			tot++;
		}
	}
	for (int i = 1;i <= n;i++)
		if (!ok[i])
		{
			ans += tot;
			sum[a[i][0]]++;
		}
	for (int i = 1000000;i >= 0;i--)
		sum[i] += sum[i + 1];
	for (int i = 1;i <= n;i++)
		if (!ok[i])
			ans += sum[a[i].back() + 1];
	printf("%lld\n",ans);
	return 0;
}