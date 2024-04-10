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

const int MAXN = 200005;

int n,q,ans;
int a[MAXN];
int cnt[MAXN];
int l[MAXN];
int r[MAXN];
int laz[MAXN];

int main()
{
	scanf("%d%d",&n,&q);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++)
	{
		cnt[a[i]]++;
		if (!l[a[i]])
			l[a[i]] = i;
		r[a[i]] = i;
	}
	for (int i = 1;i <= 200000;i++)
	{
		laz[l[i]]++;
		laz[r[i]]--;
	}
	int MAX = 0,sum = 0;
	for (int i = 1;i <= n;i++)
	{
		sum += laz[i];
		MAX = max(MAX,cnt[a[i]]);
		if (!sum)
		{
			ans += MAX;
			MAX = 0;
		}
	}
	printf("%d\n",n - ans);
	return 0;
}