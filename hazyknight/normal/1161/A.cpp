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

const int MAXN = 100005;

int n,k,ans;
int st[MAXN];
int ed[MAXN];

int main()
{
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n;i++)
		st[i] = k + 1,ed[i] = 0;
	for (int a,i = 1;i <= k;i++)
	{
		scanf("%d",&a);
		st[a] = min(st[a],i);
		ed[a] = max(ed[a],i);
	}
	for (int i = 1;i <= n;i++)
		if (!ed[i])
			ans++;
	for (int i = 1;i < n;i++)
	{
		if (ed[i] < st[i + 1])
			ans++;
		if (ed[i + 1] < st[i])
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}