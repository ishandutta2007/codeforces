#include <iostream>
#include <vector>
#include <map>

#define ll long long

using namespace std;

int main() {
	ll n, k;
	cin >> n >> k;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	ll ans = 0;
	map <ll, ll> ml;
	map <ll, ll> mr;
	for (ll i = 0; i < n; i++)
		mr[a[i]]++;
	for (ll i = 0; i < n; i++) {
		mr[a[i]]--;
		if (a[i] % k == 0) ans += ml[a[i] / k] * mr[a[i] * k];
		ml[a[i]]++;
	}
	cout << ans;
	return 0;
}