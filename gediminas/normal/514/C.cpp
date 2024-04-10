#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1181118711931201;
const ll pri = 5;
/*link https://codeforces.com/problemset/problem/514/C */
/*input
2 3
aaaaa
acacaca
aabaa
ccacacc
caaac
*/
/*output
YES
NO
NO
*/

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	set<ll> turim;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		ll has = 0;

		for (auto && j : a) {
			has *= pri;
			has += (j - 'a' + 1);
			has %= mod;
		}

		ll po = 1;

		for (int j = a.size() - 1; j >= 0; j--) {
			ll hashas = has;
			hashas -= (a[j] - 'a' + 1) * po;

			for (auto && k : {
						'a', 'b', 'c'
					}) {
				if (k == a[j])
					continue;

				ll hashisas = hashas + (k - 'a' + 1) * po;
				hashisas %= mod;
				hashisas += mod;
				hashisas %= mod;
				turim.insert(hashisas);
			}

			po *= pri;
			po %= mod;
		}
	}

	for (int i = 0; i < m; i++) {
		string a;
		cin >> a;
		ll has = 0;

		for (auto && j : a) {
			has *= pri;
			has += (j - 'a' + 1);
			has %= mod;
		}

		cout << (turim.count(has) ? "YES" : "NO") << "\n";
	}

}