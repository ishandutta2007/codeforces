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

const int MAXN = 100005;

int n;
int a[MAXN];

ll ans;

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = 0;i <= n;i++)
	{
		int l = min(a[i],a[i + 1]),r = max(a[i],a[i + 1]);
		ans += (ll)(r - l) * (l + n - r + 1);
	}
	printf("%I64d\n",ans / 2);
	return 0;
}