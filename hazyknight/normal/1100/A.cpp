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

const int MAXN = 105;

int n,k,sum,ans;
int a[MAXN];

int main()
{
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	for (int b = 1;b <= n;b++)
	{
		int tmp = sum;
		for (int i = b;i >= 1;i -= k)
			tmp -= a[i];
		for (int i = b + k;i <= n;i += k)
			tmp -= a[i];
		ans = max(ans,abs(tmp));
	}
	cout << ans << endl;
	return 0;
}