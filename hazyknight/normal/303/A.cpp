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

int n;

int main()
{
	scanf("%d",&n);
	if (~n & 1)
	{
		puts("-1");
		return 0;
	}
	for (int i = 0;i < n;i++)
		printf("%d ",i);
	printf("\n");
	for (int i = 0;i < n;i++)
		printf("%d ",i);
	printf("\n");
	for (int i = 0;i < n;i++)
		printf("%d ",2 * i % n);
	printf("\n");
	return 0;
}