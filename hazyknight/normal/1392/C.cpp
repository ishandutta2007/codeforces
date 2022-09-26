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
#include <bitset>

using namespace std;

const int MAXN = 200005;

int T,n;
int a[MAXN];

long long t;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		long long ans = 0;
		for (int i = n;i >= 2;i--)
			ans += max(0,a[i - 1] - a[i]);
		printf("%lld\n",ans);
	}
	return 0;
}