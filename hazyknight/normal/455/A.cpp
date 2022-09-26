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

using namespace std;

typedef long long ll;

const int MAXN = 100005;

int n,a;

ll cnt[MAXN];
ll f[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a);
		cnt[a]++;
	}
	f[0] = f[1] = 0;
	for (int i = 2;i <= 100001;i++)
		f[i] = max(f[i - 1],f[i - 2] + cnt[i - 1] * (i - 1));
	printf("%lld\n",f[100001]);
	return 0;
}