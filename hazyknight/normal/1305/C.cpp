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

int n,m;
int a[200005];

long long ans = 1;

int main()
{
	scanf("%d%d",&n,&m);
	if (n > m)
	{
		puts("0");
		return 0;
	}
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++)
		for (int j = i + 1;j <= n;j++)
			(ans *= abs(a[i] - a[j])) %= m;
	printf("%lld\n",ans);
	return 0;
}