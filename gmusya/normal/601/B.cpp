#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll m, q;
	cin >> m >> q;
	vector <ll> kek(m);
	for (ll i = 0; i < m; i++)
		cin >> kek[i];
	while (q--) {
		ll left, right;
		cin >> left >> right;
		left--;
		right--;
		ll n = right - left + 1;
		vector <ll> a(n);
		for (ll i = left; i < right + 1; i++)
			a[i - left] = kek[i];
		vector <ll> b;
		for (ll i = 0; i < n - 1; i++)
			b.push_back(abs(a[i] - a[i + 1]));
		vector <ll> l(n - 1), r(n - 1);
		stack <pair <ll, ll>> s;
		for (ll i = 0; i < n - 1; i++) {
			while (s.size() > 0 && s.top().first <= b[i]) {
				r[s.top().second] = i;
				s.pop();
			}
			s.push({ b[i], i });
		}
		while (s.size() > 0) {
			r[s.top().second] = n - 1;
			s.pop();
		}
		for (ll i = n - 2; i >= 0; i--) {
			while (s.size() > 0 && s.top().first < b[i]) {
				l[s.top().second] = i;
				s.pop();
			}
			s.push({ b[i], i });
		}
		while (s.size() > 0) {
			l[s.top().second] = -1;
			s.pop();
		}
		ll sum = 0;
		for (ll i = 0; i < n - 1; i++)
			sum += (r[i] - i) * (i - l[i]) * b[i];
		cout << sum << endl;
	}
	return 0;
}