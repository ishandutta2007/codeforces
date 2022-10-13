#include <bits/stdc++.h>
using namespace std;

long long calc(long long m, long long n, long long x)
{
	long long res = 0;
	for (int i = 1; i <= m; i++) res += min(n, x / i);
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	long long m, n, k;
	cin >> m >> n >> k;
	
	long long low = 1, high = m * n, ans = 0;
	while (low <= high)
	{
		long long mid = (low + high) / 2;
		long long cnt = calc(m, n, mid);
		if (cnt >= k) ans = mid, high = mid - 1;
		else low = mid + 1;
	}
	
	cout << ans << endl;
}