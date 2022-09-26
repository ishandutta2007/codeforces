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

int n;
int a[MAXN];
int b[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&b[i]);
	int MAX = 0;
	for (int i = 1;i <= n;i++)
	{
		a[i] = b[i] + MAX;
		MAX = max(MAX,a[i]);
	}
	for (int i = 1;i <= n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}