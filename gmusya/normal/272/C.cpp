#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
	ll n;
	cin >> n;
	vector <ll> a(n + 1);
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	ll q;
	cin >> q;
	vector <ll> answer(q + 1);
	vector <pair <ll, ll>> block(q + 1);
	for (ll i = 1; i <= q; i++)
		cin >> block[i].first >> block[i].second;
	for (ll i = 1; i <= q; i++)
		answer[i] = max(answer[i - 1] + block[i - 1].second, a[block[i].first]);
	for (ll i = 1; i <= q; i++)
		cout << answer[i] << endl;
	return 0;
}