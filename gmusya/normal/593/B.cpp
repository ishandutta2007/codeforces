#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
	int n;
	cin >> n;
	ll x1, x2;
	cin >> x1 >> x2;
	vector <pair <ll, pair <ll, ll>>> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].second.first >> a[i].second.second;
	for (int i = 0; i < n; i++) 
		a[i].first = a[i].second.first * x1 + a[i].second.second;
	sort(a.begin(), a.end());
	for (int i = 0; i < n - 1; i++) {
		if (a[i].first == a[i + 1].first) continue;
		ll x2_i = a[i].second.first * x2 + a[i].second.second;
		ll x2_i1 = a[i + 1].second.first * x2 + a[i + 1].second.second;
		if (x2_i > x2_i1) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}