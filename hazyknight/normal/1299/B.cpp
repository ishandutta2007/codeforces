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

typedef long long ll;

const int MAXN = 100005;

int n;
int x[MAXN];
int y[MAXN];

int main()
{
	scanf("%d",&n);
	if (n & 1)
	{
		puts("NO");
		return 0;
	}
	for (int i = 0;i < n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for (int i = 0,j = n / 2;i < n / 2;i++,j++)
	{
		if (x[i + 1] - x[i] != x[j] - x[(j + 1) % n] || y[i + 1] - y[i] != y[j] - y[(j + 1) % n])
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}