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

int n;
int a[15];

int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> a[i];
	for (int i = 0;i < (1 << n);i++)
	{
		int sum = 0;
		for (int j = 0;j < n;j++)
			if (i >> j & 1)
				sum += a[j];
			else
				sum -= a[j];
		if (sum % 360 == 0)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}