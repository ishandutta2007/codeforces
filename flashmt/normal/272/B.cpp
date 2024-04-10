#include <iostream>
using namespace std;

int main()
{
	int cnt[50] = {0}, n, x;
	long long ans = 0;
	cin >> n;
	while (n--)
	{
		cin >> x;
		int bit = 0;
		while (x) bit += x & 1, x >>= 1;
		ans += cnt[bit]++;
	}
	cout << ans << endl;
}