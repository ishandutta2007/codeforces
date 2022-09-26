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

int main()
{
	int n;
	cin >> n;
	for (int b = 1;b <= n;b++)
		for (int a = 1;a < b * n;a++)
			if (a % b == 0 && a * b > n)
			{
				cout << a << ' ' << b << endl;
				return 0;
			}
	cout << -1 << endl;
	return 0;
}