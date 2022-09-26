#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <cmath> 
#include <iomanip>

using namespace std;

int n,k;
int a[5005];
int sum[5005];

double ans;

int main()
{
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
		cin >> a[i],sum[i] = sum[i - 1] + a[i];
	for (int i = 1;i <= n;i++)
		for (int j = i;j <= n;j++)
			if (j - i + 1 >= k)
				ans = max(ans,(double)(sum[j] - sum[i - 1]) / (j - i + 1));
	cout << fixed << setprecision(7) << ans << endl;
	return 0;
}