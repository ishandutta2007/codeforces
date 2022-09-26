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

const int MAXN = 250005;

int n;

ll m,ans;
ll fac[MAXN];

int main()
{
	scanf("%d%lld",&n,&m);
	fac[0] = 1;
	for (int i = 1;i <= n;i++)
		fac[i] = fac[i - 1] * i % m;
	for (int i = 1;i <= n;i++)
		(ans += fac[n - i] * (n - i + 1) % m * (n - i + 1) % m * fac[i]) %= m;
	printf("%lld\n",ans);
	return 0;
}