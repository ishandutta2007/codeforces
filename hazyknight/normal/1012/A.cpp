#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <iomanip>

using namespace std;

int n;
int a[200005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	n <<= 1;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	long long ans = (long long)(a[n / 2] - a[1]) * (a[n] - a[n / 2 + 1]);
	for (int i = 2;i <= n / 2;i++)
		ans = min(ans,(long long)(a[n] - a[1]) * (a[i + n / 2 - 1] - a[i]));
	cout << ans << endl;
	return 0;
}