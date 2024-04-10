#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
	ll n, c;
	cin >> n >> c;
	vector <ll> a(n - 1), b(n - 1);
	for (ll i = 0; i < n - 1; i++)
		cin >> a[i];
	for (ll i = 0; i < n - 1; i++)
		cin >> b[i];
	vector <ll> suma(n), sumb(n);
	suma[0] = 0, sumb[0] = c;
	for (ll i = 1; i < n; i++) {
		suma[i] = min(suma[i - 1] + min(a[i - 1], b[i - 1] + c), sumb[i - 1] + a[i - 1]);
		sumb[i] = min(sumb[i - 1] + b[i - 1], suma[i - 1] + b[i - 1] + c);
	}
	for (ll i = 0; i < n; i++)
		cout << min(suma[i], sumb[i]) << " ";
	return 0;
}