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

using namespace std;

const int MAXN = 4005;

int T,n;
int a[MAXN];

bool f[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		n <<= 1;
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		int lst = 1;
		for (int i = 0;i <= n >> 1;i++)
			f[i] = 0;
		f[0] = 1;
		for (int i = 2;i <= n;i++)
			if (a[i] > a[lst])
			{
				int t = i - lst;
				lst = i;
				for (int j = n >> 1;j >= t;j--)
					f[j] |= f[j - t];
			}
		int t = n + 1 - lst;
				for (int j = n >> 1;j >= t;j--)
					f[j] |= f[j - t];
		puts(f[n >> 1] ? "YES" : "NO");
	}
	return 0;
}