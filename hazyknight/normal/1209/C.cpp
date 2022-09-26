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

int T,n;
int ans[MAXN];

char s[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%s",&n,s + 1);
		bool OK = 0;
		for (int i = 0;i <= 9;i++)
		{
			int a = 0,b = i;
			bool ok = 1;
			for (int j = 1;j <= n;j++)
			{
				if (s[j] - '0' >= b)
				{
					ans[j] = 2;
					b = s[j] - '0';
					continue;
				}
				if (s[j] - '0' <= i && s[j] - '0' >= a)
				{
					ans[j] = 1;
					a = s[j] - '0';
					continue;
				}
				ok = 0;
				break;
			}
			if (ok)
			{
				for (int j = 1;j <= n;j++)
					printf("%d",ans[j]);
				printf("\n");
				OK = 1;
				break;
			}
		}
		if (!OK)
			puts("-");
	}
	return 0;
}