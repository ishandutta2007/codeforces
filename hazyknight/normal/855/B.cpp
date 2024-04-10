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

int n,p,q,R;
int a[MAXN];

ll ans;
ll l[MAXN];
ll r[MAXN];

int main()
{
	scanf("%d%d%d%d",&n,&p,&q,&R);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	l[0] = -4e18;
	for (int i = 1;i <= n;i++)
		l[i] = max(l[i - 1],(ll)a[i] * p);
	r[n + 1] = -4e18;
	for (int i = n;i >= 1;i--)
		r[i] = max(r[i + 1],(ll)a[i] * R);
	ans = -4e18;
	for (int i = 1;i <= n;i++)
		ans = max(ans,l[i] + r[i] + (ll)a[i] * q);
	printf("%lld\n",ans);
	return 0;
}