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
#include <iomanip>
#include <bitset>

using namespace std;

int n,t,ans = (1 << 30) - 1;
int a[1005];

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= 100;i++)
	{
		int sum = 0;
		for (int j = 1;j <= n;j++)
			sum += max(0,abs(a[j] - i) - 1);
		if (sum < ans)
		{
			t = i;
			ans = sum;
		}
	}
	cout << t << ' ' << ans << endl;
	return 0;
}