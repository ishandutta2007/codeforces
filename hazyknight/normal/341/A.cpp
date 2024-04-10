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

ll n,ans;
ll a[MAXN];

int main()
{
	scanf("%lld",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%lld",&a[i]);
		ans += a[i];
	}
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++)
	{
		ans += 2 * (i - 1) * a[i];
		ans += 2 * (n - i) * -a[i];
	}
	ll g = __gcd(n,ans);
	ans /= g;
	n /= g;
	printf("%lld %lld\n",ans,n);
	return 0;
}