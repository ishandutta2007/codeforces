#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int MAXN = 400005;

int n,I,ans = 1e9;
int a[MAXN];
int b[MAXN];
int LG2[MAXN];

int main()
{
	scanf("%d%d",&n,&I);
	LG2[1] = 1;
	for (int i = 2;i <= n;i++)
		LG2[i] = LG2[i >> 1] + 1;
	for (int i = 1;i <= n;i++)
		if ((i & -i) == i)
			LG2[i]--;
	I <<= 3;
	I /= n;
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	sort(a + 1,a + n + 1);
	a[0] = -1;
	for (int i = 1;i <= n;i++)
	{
		if (a[i] == a[i - 1])
			b[i] = b[i - 1];
		else
			b[i] = b[i - 1] + 1;
	}
	for (int i = 1,j = 1;i <= n;i++)
	{
		while (j < i && LG2[b[i] - b[j] + 1] > I)
			j++;
		ans = min(ans,n - (i - j + 1));
	}
	printf("%d\n",ans);
	return 0;
}