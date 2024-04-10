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

int n,ans;
int a[MAXN];
int b[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = 0;i <= 25;i++)
	{
		for (int j = 1;j <= n;j++)
			b[j] = a[j] & ((1 << (i + 1)) - 1);
		sort(b + 1,b + n + 1);
		int cnt = 0;
		for (int j = 1,k = n + 1;j <= n;j++)
		{
			k = max(k,j + 1);
			while (k - 1 >= j + 1 && b[j] + b[k - 1] >= (1 << i))
				k--;
			cnt ^= n - k + 1;
		}
		for (int j = 1,k = n + 1;j <= n;j++)
		{
			k = max(k,j + 1);
			while (k - 1 >= j + 1 && b[j] + b[k - 1] >= (1 << (i + 1)))
				k--;
			cnt ^= n - k + 1;
		}
		for (int j = 1,k = n + 1;j <= n;j++)
		{
			k = max(k,j + 1);
			while (k - 1 >= j + 1 && b[j] + b[k - 1] >= (1 << (i + 1)) + (1 << i))
				k--;
			cnt ^= n - k + 1;
		}
		if (cnt & 1)
			ans += 1 << i;
	}
	printf("%d\n",ans);
	return 0;
}