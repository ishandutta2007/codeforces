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

int n;
int a[300005];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	int ans = 0;
	for (int i = 1;i <= n;i++)
		if (a[i] != a[n])
		{
			ans = max(ans,n - i);
			break;
		}
	for (int i = n;i >= 1;i--)
		if (a[i] != a[1])
		{
			ans = max(ans,i - 1);
			break;
		}
	printf("%d\n",ans);
	return 0;
}