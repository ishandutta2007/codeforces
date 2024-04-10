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

const int MAXN = 105;

int T,n;
int a[MAXN];
int b[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		sort(a + 1,a + n + 1);
		for (int i = 1;i <= n;i++)
			scanf("%d",&b[i]);
		sort(b + 1,b + n + 1);
		for (int i = 1;i <= n;i++)
			printf("%d ",a[i]);
		printf("\n");
		for (int i = 1;i <= n;i++)
			printf("%d ",b[i]);
		printf("\n");
	}
	return 0;
}