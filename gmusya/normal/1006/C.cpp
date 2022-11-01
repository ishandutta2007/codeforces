#include <iostream>
#include <vector>
#include <set>

#define ll long long
using namespace std;

int main() {
	ll n;
	cin >> n;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	ll sum = 0;
	for (ll i = 0; i < n; i++)
		sum += a[i];
	set <ll> s1, s2;
	ll cur_sum = 0;
	for (ll i = 0; i < n; i++) {
		cur_sum += a[i];
		if (cur_sum * 2 > sum)
			break;
		s1.insert(cur_sum);
	}
	cur_sum = 0;
	for (ll i = n - 1; i >= 0; i--) {
		cur_sum += a[i];
		if (cur_sum * 2 > sum)
			break;
		s2.insert(cur_sum);
	}
	ll answer = 0;
	for (auto now : s1)
		if (s2.find(now) != s2.end())
			answer = now;
	cout << answer;
	return 0;
}