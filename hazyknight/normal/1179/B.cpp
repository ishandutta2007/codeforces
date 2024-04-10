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

const int MAXN = 100005;

int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1,j = n;i <= j;i++,j--)
	{
		if (i == j)
		{
			for (int k = 1,l = m;k <= l;k++,l--)
			{
				if (k == l)
				{
					printf("%d %d\n",i,k);
					return 0;
				}
				printf("%d %d\n",i,k);
				printf("%d %d\n",i,l);
			}
			return 0;
		}
		for (int k = 1,l = m;k <= m;k++,l--)
		{
			printf("%d %d\n",i,k);
			printf("%d %d\n",j,l);
		}
	}
	return 0;
}