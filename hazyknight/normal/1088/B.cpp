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

int n,k;
int a[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	int sum = 0;
	for (int i = 1;i <= n;i++)
		if (a[i] - sum)
		{
			if (!k)
				break;
			k--;
			cout << a[i] - sum << endl;
			sum = a[i];
		}
	while (k--)
		cout << 0 << endl;
	return 0;
}