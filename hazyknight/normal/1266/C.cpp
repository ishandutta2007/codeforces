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

int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	if (n == 1 && m == 1)
	{
		puts("0");
		return 0;
	}
	if (m == 1)
	{
		for (int i = 1;i <= n;i++)
			printf("%d\n",i + 1);
		return 0;
	}
	for (int i = 1;i <= n;i++,printf("\n"))
		for (int j = 1;j <= m;j++)
			printf("%d ",i * (j + n));
	return 0;
}