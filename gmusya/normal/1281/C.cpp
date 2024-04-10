#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long 

using namespace std;

const ll MOD = 1e9 + 7;

int main() {
	int t;
	cin >> t;
	while (t--) {
		bool tf = true;
		ll length;
		cin >> length;
		string s;
		cin >> s;
		vector <ll> kek(max((ll)s.size(), length));
		for (ll i = 0; i < s.size(); i++)
			kek[i] = { s[i] - '0'};
		ll answer = s.size();
		ll new_answer = 0;
		for (ll i = 0; i < length; i++) {
			new_answer = (answer - i - 1) * (kek[i] - 1);
			if (new_answer > MOD)
				tf = false;
			new_answer %= MOD;
			if (tf)
				for (ll j = answer; j < min(length, answer + new_answer); j++)
					kek[j] = kek[j - answer + i + 1];
			answer = (answer + new_answer) % MOD;
		}
		cout << (answer + MOD) % MOD << endl;
	}
	return 0;
}