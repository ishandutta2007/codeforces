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
const int CONS = 400000;

int n;

ll ans;
ll sum[MAXN + CONS];

int main()
{
	scanf("%d",&n);
	for (int b,i = 1;i <= n;i++)
	{
		scanf("%d",&b);
		sum[i - b + CONS] += b;
	}
	for (int i = 0;i <= CONS + n;i++)
		ans = max(ans,sum[i]);
	printf("%lld\n",ans);
	return 0;
}