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

typedef long long ll;

const int MAXN = 300005;

int n;
int a[MAXN];

ll ans;

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	ll cnt = 0;
	for (int i = 1;i <= n;i++)
	{
		ll r = min(cnt,(ll)a[i] >> 1);
		ans += r;
		cnt -= r;
		a[i] -= r << 1;
		ans += a[i] / 3;
		a[i] %= 3;
		cnt += a[i];
	}
	printf("%lld\n",ans);
	return 0;
}