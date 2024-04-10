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

const int MAXN = 500005;

int n,a,b,T,L,R,ans;
int c[MAXN];
int cst1[MAXN];
int cst2[MAXN];

char p[MAXN];

int main()
{
	scanf("%d%d%d%d%s",&n,&a,&b,&T,p + 1);
	for (int i = 1;i <= n;i++)
		c[i] = p[i] == 'w' ? b + 1 : 1;
	if (T < c[1])
	{
		puts("0");
		return 0;
	}
	T -= c[1];
	R = n,L = 2;
	for (int i = 2;i <= n;i++)
	{
		if (cst1[i - 1] + a + c[i] > T)
		{
			R = i - 1;
			break;
		}
		cst1[i] = cst1[i - 1] + a + c[i];
	}
	if (R == n)
	{
		printf("%d\n",n);
		return 0;
	}
	for (int i = n;i >= 2;i--)
	{
		if (cst2[i + 1] + a + c[i] > T)
		{
			L = i + 1;
			break;
		}
		cst2[i] = cst2[i + 1] + a + c[i];
	}
	for (int i = 1,j = L;i <= R;i++)
	{
		while (j <= n && cst1[i] + cst2[j] + (long long)min(i - 1,n + 1 - j) * a > T)
			j++;
		ans = max(ans,i + n - j + 1);
	}
	printf("%d\n",ans);
	return 0;
}