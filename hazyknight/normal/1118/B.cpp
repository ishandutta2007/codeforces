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

const int MAXN = 200005;

int n,ans;
int a[MAXN];
int sum1[2][MAXN];
int sum2[2][MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++)
	{
		sum1[0][i] = sum1[0][i - 1];
		sum1[1][i] = sum1[1][i - 1];
		sum1[i & 1][i] += a[i];
	}
	for (int i = n;i >= 1;i--)
	{
		sum2[0][i] = sum2[0][i + 1];
		sum2[1][i] = sum2[1][i + 1];
		sum2[(n - i + 1) & 1][i] += a[i];
	}
	for (int i = 1;i <= n;i++)
		ans += (sum1[0][i - 1] + sum2[n & 1][i + 1] == sum1[1][i - 1] + sum2[~n & 1][i + 1]);
	cout << ans << endl;
	return 0;
}