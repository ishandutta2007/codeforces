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
#include <set>
#include <map>
#include <iomanip>
#include <assert.h>

using namespace std;

int n;
int a[2005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	cout << n + 1 << endl;
	for (int i = n;i >= 1;i--)
	{
		int t = i - 1 - a[i] % n;
		if (t < 0)
			t += n;
		cout << 1 << ' ' << i << ' ' << t << endl;
		for (int j = 1;j <= i;j++)
			a[j] += t;
	}
	cout << 2 << ' ' << n << ' ' << n << endl;
	return 0;
}