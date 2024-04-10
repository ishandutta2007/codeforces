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

const int MAXN = 200005;

int n,tot;
int a[MAXN];
int b[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		if (!a[i])
		{
			i--;
			n--;
			continue;
		}
	}
	n++;
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&b[i]);
		if (!b[i])
		{
			i--;
			n--;
			continue;
		}
	}
	for (int i = 1;i <= n;i++)
		if (a[i] == b[1])
		{
			for (int j = i;j <= n;j++)
				if (b[++tot] != a[j])
				{
					puts("NO");
					return 0;
				}
			for (int j = 1;j < i;j++)
				if (b[++tot] != a[j])
				{
					puts("NO");
					return 0;
				}
			break;
		}
	puts("YES");
	return 0;
}