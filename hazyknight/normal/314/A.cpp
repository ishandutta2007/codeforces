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

int n,k;

ll a[MAXN];

int main()
{
	scanf("%d%d",&n,&k);
	ll sum = 0,cnt = 0;
	for (int i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	for (int i = 1;i <= n;i++)
	{
		if (sum - a[i] * cnt * (n - i) < k)
		{
			printf("%d\n",i);
			continue;
		}
		sum += a[i] * cnt;
		cnt++;
	}
	return 0;
}