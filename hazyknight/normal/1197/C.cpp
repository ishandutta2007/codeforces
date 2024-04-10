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

const int MAXN = 300005;

int T,n,k,ans;
int a[MAXN];

int main()
{
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = 1;i < n;i++)
	{
		a[i] = a[i + 1] - a[i];
		ans += a[i];
	}
	sort(a + 1,a + n);
	reverse(a + 1,a + n);
	for (int i = 1;i < k;i++)
		ans -= a[i];
	printf("%d\n",ans);
	return 0;
}