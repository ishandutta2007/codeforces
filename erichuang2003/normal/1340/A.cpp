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

int T,n;
int a[MAXN];
int pos[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			pos[a[i]] = i;
		}
		int cur = 1,N = n;
		bool ok = 1;
		while (cur <= n && ok)
		{
			int len = N - pos[cur] + 1;
			for (int j = 1;j <= len;j++)
				if (a[pos[cur] + j - 1] != j + cur - 1)
				{
					ok = 0;
					break;
				}
			N = pos[cur] - 1;
			cur += len;
		}
		puts(ok ? "Yes" : "No");
	}
	return 0;
}