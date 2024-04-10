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

int n;

ll ans = -1e18;
ll MIN = 1e18,MAX = -1e18;
ll a[MAXN];
ll b[MAXN];
ll sum[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i < n;i++)
	{
		b[i] = abs(a[i + 1] - a[i]);
		if (i & 1)
			sum[i] = sum[i - 1] + b[i];
		else
			sum[i] = sum[i - 1] - b[i];
	}
	for (int i = n - 1;i >= 1;i--)
	{
		MAX = max(MAX,sum[i]);
		MIN = min(MIN,sum[i]);
		if (i & 1)
			ans = max(ans,MAX - sum[i - 1]);
		else
			ans = max(ans,-(MIN - sum[i - 1]));
	}
	cout << ans << endl;
	return 0;
}