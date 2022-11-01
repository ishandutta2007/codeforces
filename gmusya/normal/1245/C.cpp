#include <iostream>
#include <vector>
#include <string>

#define ll long long int

using namespace std;
const ll BIGNUM = 1000000007;

int main() {
	string s;
	cin >> s;
	vector <ll> b(100010);
	b[0] = 1;
	b[1] = 1;
	for (ll i = 2; i < 100010; i++) b[i] = (b[i - 1] + b[i - 2]) % BIGNUM;
	vector <ll> a;
	ll cnt = 1;
	for (ll i = 0; i < s.size() - 1; i++) {
		if (s[i] == 'm' || s[i] == 'w') {
			cout << 0;
			return 0;
		}
		if ((s[i] == 'u' && s[i + 1] == 'u') || (s[i] == 'n' && s[i + 1] == 'n')) {
			cnt++;
		}
		else {
			a.push_back(cnt);
			cnt = 1;
		}
	}
	if (s[s.size() - 1] == 'm' || s[s.size() - 1] == 'w') {
		cout << 0;
		return 0;
	}
	a.push_back(cnt);
	ll ans = 1;
	for (int i = 0; i < a.size(); i++) ans = (ans * b[a[i]]) % BIGNUM;
	cout << ans << endl;
	return 0;
}