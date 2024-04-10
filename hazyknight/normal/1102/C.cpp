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

int n,x,y,ans;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> x >> y;
	if (x > y)
	{
		cout << n << endl;
		return 0;
	}
	for (int a,i = 1;i <= n;i++)
	{
		cin >> a;
		ans += (a <= x);
	}
	cout << (ans + 1) / 2 << endl;
	return 0;
}