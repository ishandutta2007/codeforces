#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main () {
	ll n;
	cin >> n;
	vector <pair <ll, ll>> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	ll pos = -1e10, cnt = 0;
	for (ll i = 0; i < n; i++) {
		if (a[i].first - a[i].second > pos) {
			cnt++;
			pos = a[i].first;
			continue;
		}
		if (i == n - 1 || a[i].first + a[i].second < a[i + 1].first) {
			cnt++;
			pos = a[i].first + a[i].second;
			continue;
		}
		pos = a[i].first;
	}
	cout << cnt;
	return 0;
}