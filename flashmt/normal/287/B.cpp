#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long n;
	int k;
	cin >> n >> k;
	
	int low = 0, high = k - 1, ans = -1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		long long can = 1LL * (k + k - mid + 1) * mid / 2 - mid + 1;
		if (can >= n) ans = mid, high = mid - 1;
		else low = mid + 1;
	}
	
	cout << ans << endl;
}