#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <set>

using namespace std;

int n,s;
int a[200005];

long long ans;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> s;
	int p = (n + 1) / 2;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	if (a[p] < s)
	{
		for (int i = p;i <= n;i++)
			if (a[i] < s)
				ans += s - a[i];
	}
	else
	{
		for (int i = p;i >= 1;i--)
			if (a[i] > s)
				ans += a[i] - s;
	}
	cout << ans << endl;
	return 0;
}