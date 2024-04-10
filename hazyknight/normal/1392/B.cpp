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
		scanf("%d%lld",&n,&t);
		if (t >= 3)
		{
			t -= 3;
			t %= 2;
			t += 3;
		}
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		while (t--)
		{
			int MAX = -1e9;
			for (int i = 1;i <= n;i++)
				MAX = max(MAX,a[i]);
			for (int i = 1;i <= n;i++)
				a[i] = MAX - a[i];
		}
		for (int i = 1;i <= n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}