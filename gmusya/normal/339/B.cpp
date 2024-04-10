#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	ll n, m, cnt = 0;
	cin >> n >> m;
	vector <ll> a(m + 1);
	a[0] = 1;
	for (ll i = 1; i <= m; i++)
		cin >> a[i];
	for (ll i = 1; i <= m; i++) {
		if (a[i] >= a[i - 1])
			cnt += (a[i] - a[i - 1]);
		else
			cnt += (n - a[i - 1] + a[i]);
	}
	cout << cnt;
	return 0;
}