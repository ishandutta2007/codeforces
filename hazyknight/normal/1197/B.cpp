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

int T,n;
int a[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++)
		if (a[i] == n)
		{
			for (int j = 1;j < i;j++)
				if (a[j] > a[j + 1])
				{
					puts("NO");
					return 0;
				}
			for (int j = n;j > i;j--)
				if (a[j] > a[j - 1])
				{
					puts("NO");
					return 0;
				}
		}
	puts("YES");
	return 0;
}