#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

int n,m;
int a[100005];

long long sum;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	for (int i = n - 1;i >= 1;i--)
	{
		int to = max(1,a[i + 1] - 1);
		if (a[i] < to)
			continue;
		sum += a[i] - to;
		a[i] = to;
	}
	for (int i = 2;i <= n;i++)
		if (a[i] > a[i - 1])
			sum += a[i - 1];
	cout << sum << endl;
	return 0;
}