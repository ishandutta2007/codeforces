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

int n,tot,sum;

pair<int,int> a[105];

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i].first;
		tot += a[i].first;
		a[i].second = i;
	}
	int t = 1;
	for (int i = 2;i <= n;i++)
		if (a[i].first <= a[1].first / 2)
			a[++t] = a[i];
	for (int i = 1;i <= t;i++)
		sum += a[i].first;
	if (sum > tot / 2)
	{
		cout << t << endl;
		for (int i = 1;i <= t;i++)
			cout << a[i].second << ' ';
		cout << endl;
	}
	else
		cout << 0 << endl;
	return 0;
}