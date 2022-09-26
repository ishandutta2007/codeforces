#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <set>

using namespace std;

int n,m;

long long a[300005];
long long b[300005];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%I64d",&a[i]);
	scanf("%d",&m);
	for (int i = 1;i <= m;i++)
		scanf("%I64d",&b[i]);
	int ans = 0;
	long long sa = 0,sb = 0,i = 1,j = 1;
	while (i <= n && j <= m)
	{
		if (!sa || sa < sb)
			sa += a[i++];
		else if (sa > sb)
			sb += b[j++];
		else
			sa = sb = 0,ans++;
	}
	while (i <= n)
		sa += a[i++];
	while (j <= m)
		sb += b[j++];
	if (sa == sb && sa)
		sa = sb = 0,ans++;
	if (sa || sb)
		printf("-1");
	else
		printf("%d\n",ans);
	return 0;
}