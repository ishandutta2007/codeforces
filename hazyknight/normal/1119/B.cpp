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

int n,H;
int a[1005];
int b[1005];

int main()
{
	scanf("%d%d",&n,&H);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= i;j++)
			b[j] = a[j];
		sort(b + 1,b + i + 1);
		int tot = 0;
		for (int j = i;j >= 1;j -= 2)
		{
			tot += max(b[j],b[j - 1]);
			if (tot > H)
				break;
		}
		if (tot > H)
		{
			printf("%d\n",i - 1);
			return 0;
		}
	}
	printf("%d\n",n);
	return 0;
}