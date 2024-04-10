#include <iostream>
#include <vector>

#define ll long long

using namespace std;

vector <bool> tf(26);

int main() {
	ll n, k;
	cin >> n >> k;
	vector <char> c(n);
	for (ll i = 0; i < n; i++)
		cin >> c[i];
	char x;
	for (ll i = 0; i < k; i++) {
		cin >> x;
		tf[x - 'a'] = true;
	}
	ll cnt = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (tf[c[i] - 'a'] == false) {
			ans += cnt * (cnt + 1) / 2;
			cnt = 0;
			continue;
		}
		cnt++;
	}
	ans += cnt * (cnt + 1) / 2;
	cout << ans;
	return 0;
}