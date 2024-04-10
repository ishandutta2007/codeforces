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

const int MAXN = 200005;

int n,m;
int a[MAXN];

bool ok(int d)
{
	long long sum = 0;
	for (int i = 1;i <= n;i++)
		sum += max(0,a[i] - (i - 1) / d);
	return sum >= m;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	reverse(a + 1,a + n + 1);
	if (!ok(n))
	{
		cout << -1 << endl;
		return 0;
	}
	int low = 1,high = n;
	while (low < high)
	{
		int mid = (low + high) >> 1;
		if (ok(mid))
			high = mid;
		else
			low = mid + 1;
	}
	cout << low << endl;
	return 0;
}