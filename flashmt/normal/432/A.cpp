#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k, x, a[6] = {0};
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		x = (5 - x) / k;
		a[x]++;
	}
	
	int ans = 0;
	for (int i = 5; i; i--)
	{
		ans += a[i] / 3;
		a[i - 1] += a[i] % 3;
	}
	
	cout << ans << endl;
}