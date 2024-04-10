#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <ll> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector <ll> b;
	for (int i = 0; i < n; i += 2) b.push_back(a[i]);
	for (int i = 1; i < n; i += 2) b.push_back(a[i]);
	for (int i = 0; i < n; i++) b.push_back(b[i]);
	ll sum = 0;
	ll ans = 0;
	int m = (n + 1) / 2;
	for (int i = 0; i < n + n; i++) {
		if (i >= m) sum -= b[i - m];
		sum += b[i];
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}