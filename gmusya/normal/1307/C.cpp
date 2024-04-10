#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
	string s;
	cin >> s;
	ll n = s.size();
	vector < vector <ll>> b(26, vector <ll> (26));
	vector <vector <ll>> a(n + 1, vector <ll>(26));
	for (ll i = 1; i <= n; i++) {
		a[i] = a[i - 1];
		a[i][s[i - 1] - 'a']++;
	}
	for (ll i = 1; i <= n; i++) {
		ll c = s[i - 1];
		for (ll j = 0; j < 26; j++) {
			ll k = a[n][j] - a[i][j];
			b[s[i - 1] - 'a'][j] += k;
		}
	}
	ll ans = 0;
	for (ll i = 0; i < 26; i++)
		for (ll j = 0; j < 26; j++)
			ans = max(ans, b[i][j]);
	for (ll i = 0; i < 26; i++)
		ans = max(ans, a[n][i]);
	cout << ans;
	return 0;
}