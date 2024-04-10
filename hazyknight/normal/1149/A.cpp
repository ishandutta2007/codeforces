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

const int MAXN = 400005;

int n,a,tot;
int cnt[3];
int p[MAXN];

bool mark[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a);
		cnt[a]++;
	}
	if (cnt[2])
	{
		printf("2 ");
		cnt[2]--;
	}
	if (cnt[1])
	{
		printf("1 ");
		cnt[1]--;
	}
	while (cnt[2])
	{
		cnt[2]--;
		printf("2 ");
	}
	while (cnt[1])
	{
		cnt[1]--;
		printf("1 ");
	}
	printf("\n");
	return 0;
}