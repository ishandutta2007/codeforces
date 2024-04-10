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
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int MAXN = 200005;

int n,q;
int a[MAXN];
int tp[MAXN];
int x[MAXN];
int lst[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	for (int i = 1;i <= n;i++)
		lst[i] = 1;
	for (int p,y,i = 1;i <= q;i++)
	{
		scanf("%d",&tp[i]);
		if (tp[i] == 1)
		{
			scanf("%d%d",&p,&y);
			a[p] = y;
			lst[p] = i + 1;
		}
		else
			scanf("%d",&x[i]);
	}
	for (int i = q;i >= 1;i--)
		x[i] = max(x[i],x[i + 1]);
	for (int i = 1;i <= n;i++)
		printf("%d ",max(x[lst[i]],a[i]));
	printf("\n");
	return 0;
}