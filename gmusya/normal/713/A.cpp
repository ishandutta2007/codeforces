#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

#define ll long long

using namespace std;

int main() {
	unordered_map <string, ll> m;
	ll n;
	cin >> n;
	while (n--) {
		char c;
		cin >> c;
		if (c == '?') {
			string s;
			cin >> s;
			while (s.size() < 19)
				s = "0" + s;
			cout << m[s] << endl;
			continue;
		}
		string s;
		ll x;
		cin >> x;
		for (ll i = 0; i < 19; i++) {
			if (x % 2 == 0)
				s = "0" + s;
			else
				s = "1" + s;
			x /= 10;
		}
		if (c == '+')
			m[s]++;
		else
			m[s]--;
	}
	return 0;
}