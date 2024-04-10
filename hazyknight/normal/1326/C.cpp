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

const int MAXN = 200005;
const ll MOD = 998244353;

int n,k;
int a[MAXN];

ll ans;

int main()
{
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	ans = 1;
	int pos = 0;
	for (int i = 1;i <= n;i++)
		if (a[i] >= n - k + 1)
		{
			if (pos)
				(ans *= i - pos) %= MOD;
			pos = i;
		}
	printf("%lld %lld\n",(ll)(n - k + 1 + n) * k / 2,ans);
	return 0;
}