#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef double db;

const db INF = 1e9;

int a,b;

db solve(int S)
{
	if (S < 0)
		return INF;
	int low = 1,high = 1e9;
	while (low < high)
	{
		int mid = low + high + 1 >> 1;
		if ((db)S / mid / 2 >= b)
			low = mid;
		else
			high = mid - 1;
	}
	return (db)S / low / 2 < b ? INF : (db)S / low / 2;
}

int main()
{
	cin >> a >> b;
	if (a == b)
	{
		cout << b << endl;
		return 0;
	}
	db ans = min(solve(a - b),solve(a + b));
	if (ans == INF)
		cout << -1 << endl;
	else
		cout << fixed << setprecision(10) << ans << endl;
	return 0;
}