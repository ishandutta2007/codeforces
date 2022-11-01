#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int 

using namespace std;

int main() {
	ll n, m;
	cin >> n >> m;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	vector <ll> b(n), ans(n);
	b[0] = a[0];
	for (ll i = 1; i < n; i++) b[i] = b[i - 1] + a[i];
	for (ll i = 0; i < m; i++) ans[i] = b[i];
	for (ll i = m; i < n; i++) ans[i] = ans[i - m] + b[i];
	for (auto now : ans) cout << now << " ";

	return 0;
}