#include <iostream>
#include <vector>

#define ll long long
using namespace std;

int main() {
	ll n;
	cin >> n;
	vector <pair <ll, ll>> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	if (n % 2) {
		cout << "no";
		return 0;
	}
	vector <pair <ll, ll>> k(n / 2);
	for (ll i = 0; i < n / 2; i++) {
		k[i].first = a[i].first + a[i + n / 2].first;
		k[i].second = a[i].second + a[i + n / 2].second;
	}
	for (ll i = 0; i < n / 2 - 1; i++)
		if (k[i].first != k[i + 1].first || k[i].second != k[i + 1].second) {
			cout << "no";
			return 0;
		}
	cout << "yes";
	return 0;
}