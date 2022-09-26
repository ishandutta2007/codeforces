#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

int n;

long long ans;
long long a[2][300005];
long long sum[2][300005];
long long suml[2][300005];
long long sumr[2][300005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[0][i];
	for (int i = 1;i <= n;i++)
		cin >> a[1][i];
	for (int i = 0;i <= 1;i++)
		for (int j = n;j >= 1;j--)
			sum[i][j] = sum[i][j + 1] + a[i][j];
	for (int i = 0;i <= 1;i++)
	{
		for (int j = n;j >= 1;j--)
		{
			suml[i][j] = suml[i][j + 1] + sum[i][j + 1];
			sumr[i][j] = sumr[i][j + 1] + a[i][j] * (n - j);
		}
	}
	long long cur = 0;
	for (int i = 1;i <= n;i++)
	{
		ans = max(ans,cur + suml[~i & 1][i] + sumr[i & 1][i] + (n - i + 1) * sum[i & 1][i] + (i - 1) * 2 * (sum[~i & 1][i] + sum[i & 1][i]));
		cur += (i - 1) * 2 * a[~i & 1][i];
		cur += ((i - 1) * 2 + 1) * a[i & 1][i];
	}
	ans = max(ans,cur);
	cout << ans << endl;
	return 0;
}