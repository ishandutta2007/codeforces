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
#include <bitset>

using namespace std;

int n,t;
int MIN = 1e9,ans;

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> t;
	for (int a,b,i = 1;i <= n;i++)
	{
		cin >> a >> b;
		int T = 0;
		if (a >= t)
			T = a;
		else
			T = ((t - a - 1) / b + 1) * b + a;
		if (T < MIN)
		{
			MIN = T;
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}