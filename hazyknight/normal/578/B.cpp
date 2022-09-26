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

int n;
int a[MAXN];
int pre[MAXN];
int suf[MAXN];

ll ans,k,x;

int main()
{
	scanf("%d%lld%lld",&n,&k,&x);
	ll mul = 1;
	while (k--)
		mul *= x;
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++)
		pre[i] = pre[i - 1] | a[i];
	for (int i = n;i >= 1;i--)
		suf[i] = suf[i + 1] | a[i];
	for (int i = 1;i <= n;i++)
		ans = max(ans,pre[i - 1] | suf[i + 1] | (a[i] * mul));
	printf("%lld\n",ans);
	return 0;
}