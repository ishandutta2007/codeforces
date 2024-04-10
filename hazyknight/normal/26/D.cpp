#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

int n,m,k;

int main()
{
	cin >> n >> m >> k;
	if (m > n + k)
	{
		cout << 0 << endl;
		return 0;
	}
	if (k >= m)
	{
		cout << 1 << endl;
		return 0;
	}
	double ans = 1;
	for (int i = 1;i <= k + 1;i++)
		ans *= (double)(m - i + 1) / (n + i);
	cout << fixed << setprecision(5) << 1 - ans << endl;
	return 0;
}