#include <iostream>
#include <vector>
#include <string>
#include <set>

typedef long long ll;

using namespace std;

const ll MOD1 = 1e9 + 123;
const ll MOD2 = 1e9 + 321;
const ll P = 31;

int main() {
	string s;
	cin >> s;
	vector <char> c(26);
	for (int i = 0; i < 26; i++)
		cin >> c[i];
	vector <int> bad(26);
	for (int i = 0; i < 26; i++)
		bad[i] = 1 - (c[i] - '0');
	set <ll> used;
	int k;
	cin >> k;
	int ans = 0;
	for (int L = 0; L < s.size(); L++) {
		int cnt = 0;
		ll hash1 = 0;
		ll hash2 = 0;
		for (int R = L; R < s.size(); R++) {
			cnt += bad[s[R] - 'a'];
			if (cnt > k) break;
			hash1 = ((hash1 * P) + s[R] - 'a' + 1) % MOD1;
			hash2 = ((hash2 * P) + s[R] - 'a' + 1) % MOD2;
			ll globalhash = hash1 * (1e9 + 400) + hash2;
			used.insert(globalhash);
		}
	}
	cout << used.size();
	return 0;
}