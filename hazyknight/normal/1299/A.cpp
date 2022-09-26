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

int n,ans = -1;
int a[MAXN];
int b[MAXN];

vector<int> v[31];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		for (int j = 0;j <= 30;j++)
			if (a[i] >> j & 1)
				v[j].push_back(i);
	}
	for (int i = 30;i >= 0;i--)
		if (v[i].size() == 1)
		{
			swap(a[1],a[v[i][0]]);
			break;
		}
	for (int i = 1;i <= n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}