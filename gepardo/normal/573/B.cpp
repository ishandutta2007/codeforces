#include <iostream>
#include <algorithm>

using namespace std;

int n, a[1000000], b[1000000], c[1000000], ans = 0;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	b[0] = 1;
	for (int i = 1; i < n; i++) b[i] = min(a[i], b[i - 1] + 1);
	c[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) c[i] = min(a[i], c[i + 1] + 1);
	for (int i = 0; i < n; i++) ans = max(ans, min(b[i], c[i]));
	cout << ans;
}