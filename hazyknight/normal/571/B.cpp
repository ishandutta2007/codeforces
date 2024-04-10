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

using namespace std;

typedef long long ll;

const int MAXN = 300005;
const int MAXK = 5005;

int n,k;
int a[MAXN];
int f[MAXK][MAXK];

int main()
{
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	sort(a + 1,a + n + 1);
	int len = n / k,el = n % k,ell = k - el;
	f[0][0] = 0;
	for (int i = 0;i < k;i++)
		for (int j = 0;j <= min(i,el);j++)
		{
			int tot = j * (len + 1) + (i - j) * len,v = tot ? a[tot + 1] - a[tot] : 0;
			if (j < el)
				f[i + 1][j + 1] = max(f[i + 1][j + 1],f[i][j] + v);
			if (i - j < ell)
				f[i + 1][j] = max(f[i + 1][j],f[i][j] + v);
		}
	printf("%d\n",a[n] - a[1] - f[k][el]);
	return 0;
}