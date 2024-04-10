#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
	ll n;
	cin >> n;
	vector <pair <ll, ll>> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i].first;
	for (ll i = 0; i < n; i++)
		a[i].second = i + 1;
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	ll sum = 0;
	for (ll i = 0; i < n; i++)
		sum += a[i].first * i;
	cout << sum + n << endl;
	for (ll i = 0; i < n; i++)
		cout << a[i].second << " ";
	return 0;
}