#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
	ll n, k;
	cin >> n >> k;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	vector <ll> q(n);
	for (ll i = 0; i < k; i++)
		q[k - 1] += a[i];
	for (ll i = k; i < n; i++)
		q[i] = q[i - 1] + a[i] - a[i - k];
	vector <pair <ll, ll>> left(n);
	left[0] = { q[0], 0 };
	for (ll i = 1; i < n; i++) {
		if (q[i] > left[i - 1].first)
			left[i] = { q[i], i };
		else
			left[i] = left[i - 1];
	}
	ll ans = 0, l = 0, r = 0;
	for (ll i = 2 * k - 1; i < n; i++) {
		ll first_ans = q[i];
		pair <ll, ll> second_ans = left[i - k];
		if (first_ans + second_ans.first > ans) {
			ans = first_ans + second_ans.first;
			l = second_ans.second;
			r = i;
		}
	}
	l++, l++, r++, r++;
	l -= k, r -= k;
	cout << l << " " << r;
	return 0;
}